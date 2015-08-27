//
//  IDESourceCodeEditor+CATViewReplacement.m
//  Multiplex
//
//  Created by Kolin Krewinkel on 9/25/14.
//  Copyright (c) 2014 Kolin Krewinkel. All rights reserved.
//

@import MPXFoundation;
@import MPXSelectionCore;
@import QuartzCore;
@import JRSwizzle;

#import <DVTKit/DVTTextStorage.h>
#import <DVTKit/DVTLayoutManager.h>
#import <DVTKit/DVTFontAndColorTheme.h>
#import <DVTKit/DVTFoldingManager.h>
#import <DVTKit/DVTUndoManager.h>

#import "DVTSourceTextView+MPXEditorExtensions.h"

static const NSInteger MPXLeftArrowSelectionOffset = -1;
static const NSInteger MPXRightArrowSelectionOffset = 1;

@implementation DVTSourceTextView (MPXEditorExtensions)

@synthesizeAssociation(DVTSourceTextView, mpx_inUndoGroup);
@synthesizeAssociation(DVTSourceTextView, mpx_shouldCloseGroupOnNextChange);
@synthesizeAssociation(DVTSourceTextView, mpx_selectionManager);
@synthesizeAssociation(DVTSourceTextView, mpx_definitionLongPressTimer);
@synthesizeAssociation(DVTSourceTextView, mpx_textViewSelectionDecorator);

@synthesizeAssociation(DVTSourceTextView, mpx_rangeInProgressStart);
@synthesizeAssociation(DVTSourceTextView, mpx_rangeInProgress);

#pragma mark - Initializer

- (void)mpx_commonInitDVTSourceTextView
{
    [self mpx_commonInitDVTSourceTextView];

    self.mpx_textViewSelectionDecorator = [[MPXTextViewSelectionDecorator alloc] initWithTextView:self];

    self.mpx_selectionManager = [[MPXSelectionManager alloc] initWithTextView:self];
    self.mpx_selectionManager.visualizationDelegate = self.mpx_textViewSelectionDecorator;

    self.mpx_rangeInProgress = [MPXSelection selectionWithRange:NSMakeRange(NSNotFound, 0)];
    self.mpx_rangeInProgressStart = [MPXSelection selectionWithRange:NSMakeRange(NSNotFound, 0)];

    self.selectedTextAttributes = @{};
}

- (void)undo:(id)sender
{
    if (self.mpx_inUndoGroup) {
        self.mpx_inUndoGroup = NO;
        [self.undoManager endUndoGrouping];
    }

    [self.undoManager undoNestedGroup];
}

#pragma mark - NSView

- (void)mpx_viewWillMoveToWindow:(NSWindow *)window
{
    [self mpx_viewWillMoveToWindow:window];

    // Observe the window's state while the view resides in it
    if (window) {
        [[NSNotificationCenter defaultCenter] addObserver:self.mpx_textViewSelectionDecorator selector:@selector(startBlinking) name:NSWindowDidBecomeKeyNotification object:window];
        [[NSNotificationCenter defaultCenter] addObserver:self.mpx_textViewSelectionDecorator selector:@selector(stopBlinking) name:NSWindowDidResignKeyNotification object:window];
    } else {
        [[NSNotificationCenter defaultCenter] removeObserver:self name:NSWindowDidBecomeKeyNotification object:nil];
        [[NSNotificationCenter defaultCenter] removeObserver:self name:NSWindowDidResignKeyNotification object:nil];
    }
}

#pragma mark - Cursors

- (BOOL)isSelectable
{
    return YES;
}

#pragma mark - Keyboard Events

- (void)insertText:(id)insertObject
{
    // Prevents random stuff being thrown in.
    if (![insertObject isKindOfClass:[NSString class]]) {
        return;
    }

    if (self.mpx_shouldCloseGroupOnNextChange && self.mpx_inUndoGroup) {
        self.mpx_inUndoGroup = NO;
        [self.undoManager endUndoGrouping];
        self.mpx_shouldCloseGroupOnNextChange = NO;
    }


    if (!self.mpx_inUndoGroup) {
        self.mpx_inUndoGroup = YES;

        [self.undoManager beginUndoGrouping];

        NSArray *currState = self.mpx_selectionManager.finalizedSelections;
        [self.undoManager registerUndoWithTarget:self handler:^(id  _Nonnull target) {
            self.mpx_selectionManager.finalizedSelections = currState;
            [self.mpx_textViewSelectionDecorator startBlinking];
        }];
    }

    NSString *insertString = (NSString *)insertObject;

    // Sequential (negative) offset of characters added.
    __block NSInteger totalDelta = 0;
    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        NSRange range = selection.range;
        NSUInteger insertStringLength = [insertString length];

        // Offset by the previous mutations made (+/- doesn't matter, as long as the different maths at each point correspond to the relative offset made by inserting a # of chars.)
        NSRange offsetRange = NSMakeRange(range.location + totalDelta, range.length);

        [self.textStorage replaceCharactersInRange:offsetRange withString:insertString withUndoManager:self.undoManager];

        // Offset the following ones by noting the original length and updating for the replacement's length, moving cursors following forward/backward.
        NSInteger delta = range.length - insertStringLength;
        totalDelta -= delta;

        NSRange lineRange;
        (void)[self.layoutManager lineFragmentRectForGlyphAtIndex:NSMaxRange(offsetRange) effectiveRange:&lineRange];

        NSUInteger relativeLinePosition = selection.interLineDesiredIndex;

        if (relativeLinePosition == NSNotFound)
        {
            relativeLinePosition = NSMaxRange(offsetRange) - lineRange.location;
        }

        // Move cursor (or range-selection) to the end of what was just added with 0-length.
        NSRange newInsertionPointRange = NSMakeRange(offsetRange.location + insertStringLength, 0);
        return [[MPXSelection alloc] initWithSelectionRange:newInsertionPointRange
                                      interLineDesiredIndex:relativeLinePosition
                                                     origin:newInsertionPointRange.location];
    } sequentialModification:YES];

    [self.mpx_textViewSelectionDecorator startBlinking];
}

- (void)deleteBackward:(id)sender
{
    // Sequential (negative) offset of characters added.
    __block NSInteger totalDelta = 0;

    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        // Update the base range with the delta'd amount of change from previous mutations.
        NSRange range = [selection range];
        NSRange offsetRange = NSMakeRange(range.location + totalDelta, range.length);

        NSRange deletingRange = NSMakeRange(0, 0);
        if (offsetRange.length == 0) {
            deletingRange = NSMakeRange(offsetRange.location - 1, 1);
        } else {
            deletingRange = NSMakeRange(offsetRange.location, offsetRange.length);
        }

        // Delete the characters
        [self insertText:@"" replacementRange:deletingRange];

        // New range for the beam (to the beginning of the range we replaced)
        NSRange newInsertionPointRange = NSMakeRange(deletingRange.location, 0);
        MPXSelection *newSelection = [MPXSelection selectionWithRange:newInsertionPointRange];

        // Increment/decrement the delta by how much we trimmed.
        totalDelta -= deletingRange.length;

        return newSelection;
    }];
}

#pragma mark Indentations/Other insertions

- (void)insertNewline:(id)sender
{
    NSUndoManager *undoManager = self.undoManager;
    DVTTextStorage *textStorage = (DVTTextStorage *)self.textStorage;

    [self insertText:@"\n"];

    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        NSRange range = selection.range;

        [textStorage indentAtBeginningOfLineForCharacterRange:range undoManager:undoManager];

        NSLayoutManager *layoutManager = [self layoutManager];
        NSRange lineRange;
        NSUInteger desiredIndex = [layoutManager glyphIndexForCharacterAtIndex:NSMaxRange(range)];
        NSUInteger lineNumber = 0;
        NSUInteger numberOfLines = 0;

        for (NSUInteger index = 0; index < [layoutManager numberOfGlyphs]; numberOfLines++) {
            (void)[layoutManager lineFragmentRectForGlyphAtIndex:index effectiveRange:&lineRange];

            if (desiredIndex >= lineRange.location && desiredIndex <= NSMaxRange(lineRange)) {
                lineNumber = numberOfLines;
                break;
            }

            index = NSMaxRange(lineRange);
        }

        NSUInteger firstNonBlank = [textStorage firstNonblankForLine:lineNumber + 1 convertTabs:YES];

        NSRange effectiveRange;
        (void)[self.layoutManager lineFragmentRectForGlyphAtIndex:desiredIndex
                                                   effectiveRange:&effectiveRange];
        return [MPXSelection selectionWithRange:NSMakeRange(effectiveRange.location + firstNonBlank, 0)];
    }];
}

#pragma mark Scrolling

- (void)centerSelectionInVisibleArea:(id)sender
{
}

#pragma mark - Basic Directional Arrows
#pragma mark -

#pragma mark Simple Index-Movement

- (void)mpx_offsetSelectionsDefaultingLengthsToZero:(NSInteger)amount modifySelection:(BOOL)modifySelection
{
    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection)
     {
         NSRange existingRange = selection.range;

         // Start the new range from the existing point, resetting the length to 0.
         NSRange newRange = existingRange;
         newRange.length = 0;

         // Push the range forward or move it backwards.
         if (amount > 0)
         {
             newRange.location = NSMaxRange(existingRange) + amount;
         }
         else
         {
             newRange.location = existingRange.location + amount;
         }

         // Validate the range at the edges
         if (newRange.location == NSUIntegerMax)
         {
             newRange.location = 0;
         }
         else if (newRange.location > [self.textStorage length])
         {
             newRange.location = self.textStorage.length - 1;
         }

         // The selection should reach out and touch where it originated from.
         if (modifySelection)
         {
             newRange = NSUnionRange(existingRange, newRange);
         }

         return [MPXSelection selectionWithRange:newRange];
     }];
}

- (void)moveLeft:(id)sender
{
    [self mpx_moveLeftModifyingSelection:NO];
}

- (void)moveLeftAndModifySelection:(id)sender
{
    [self mpx_moveLeftModifyingSelection:YES];
}

- (void)mpx_moveLeftModifyingSelection:(BOOL)modifySelection
{
    [self mpx_offsetSelectionsDefaultingLengthsToZero:MPXLeftArrowSelectionOffset
                                      modifySelection:modifySelection];
}

- (void)moveRight:(id)sender
{
    [self mpx_moveRightModifyingSelection:NO];
}

- (void)moveRightAndModifySelection:(id)sender
{
    [self mpx_moveRightModifyingSelection:YES];
}

- (void)mpx_moveRightModifyingSelection:(BOOL)modifySelection
{
    [self mpx_offsetSelectionsDefaultingLengthsToZero:MPXRightArrowSelectionOffset
                                      modifySelection:modifySelection];
}

#pragma mark Up and Down/Line-Movements

- (void)mpx_shiftSelectionLineWithRelativePosition:(CATRelativePosition)position
                                modifyingSelection:(BOOL)modifySelection
{
    NSCAssert(position != CATRelativePositionLeft, @"Use beginning/end of line methods.");
    NSCAssert(position != CATRelativePositionRight, @"Use beginning/end of line methods.");

    NSLayoutManager *layoutManager = self.layoutManager;

    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection)
     {
         // "Previous" refers exclusively to time, not location.
         NSRange previousAbsoluteRange = selection.range;

         // Effective range is used because lineRangeForRange does not handle the custom linebreaking/word-wrapping that the text view does.
         NSRange previousLineRange = ({
             NSRange range;
             [layoutManager lineFragmentRectForGlyphAtIndex:NSMaxRange(previousAbsoluteRange)
                                             effectiveRange:&range];
             range;
         });

         // The index of the selection relative to the start of the line in the entire string
         NSUInteger previousRelativeIndex = NSMaxRange(previousAbsoluteRange) - previousLineRange.location;

         // Where the cursor is placed is not where it originally came from, so we should aim to place it there.
         if (selection.interLineDesiredIndex != previousRelativeIndex &&
             selection.interLineDesiredIndex != NSNotFound)
         {
             previousRelativeIndex = selection.interLineDesiredIndex;
         }

         // The selection is in the first/zero-th line, so there is no above line to find.
         // Sublime Text and OS X behavior is to jump to the start of the document.
         if (previousLineRange.location == 0 &&
             position == CATRelativePositionTop)
         {
             return [MPXSelection selectionWithRange:NSMakeRange(0, 0)];
         }
         else if (NSMaxRange(previousLineRange) == self.textStorage.length &&
                  position == CATRelativePositionBottom)
         {
             return [MPXSelection selectionWithRange:NSMakeRange(self.textStorage.length, 0)];
         }


         NSRange newLineRange = ({
             NSRange range;

             if (position == CATRelativePositionTop)
             {
                 [layoutManager lineFragmentRectForGlyphAtIndex:previousLineRange.location - 1
                                                 effectiveRange:&range];
             }
             else
             {
                 [layoutManager lineFragmentRectForGlyphAtIndex:NSMaxRange(previousLineRange)
                                                 effectiveRange:&range];
             }


             range;
         });

         // The line is long enough to show at the original relative-index
         if (newLineRange.length > previousRelativeIndex)
         {
             NSUInteger desiredPosition = newLineRange.location + previousRelativeIndex;

             NSRange newAbsoluteRange = NSMakeRange(desiredPosition, 0);
             if (modifySelection)
             {
                 newAbsoluteRange = NSUnionRange(previousAbsoluteRange, newAbsoluteRange);
             }

             return [MPXSelection selectionWithRange:newAbsoluteRange];
         }

         NSRange newAbsoluteRange = NSMakeRange(NSMaxRange(newLineRange) - 1, 0);
         if (modifySelection)
         {
             newAbsoluteRange = NSUnionRange(previousAbsoluteRange, newAbsoluteRange);
         }

         // This will place it at the end of the line, aiming to be placed at the original position.
         return [[MPXSelection alloc] initWithSelectionRange:newAbsoluteRange
                                       interLineDesiredIndex:previousRelativeIndex
                                                      origin:newAbsoluteRange.location];
     }];
}

- (void)mpx_moveSelectionsUpModifyingSelection:(BOOL)modifySelection
{
    [self mpx_shiftSelectionLineWithRelativePosition:CATRelativePositionTop
                                  modifyingSelection:modifySelection];
}

- (void)mpx_moveSelectionsDownModifyingSelection:(BOOL)modifySelection
{
    [self mpx_shiftSelectionLineWithRelativePosition:CATRelativePositionBottom
                                  modifyingSelection:modifySelection];
}

#pragma mark Up/Down Forwarding Methods

- (void)moveUp:(id)sender
{
    [self mpx_moveSelectionsUpModifyingSelection:NO];
}

- (void)moveUpAndModifySelection:(id)sender
{
    [self mpx_moveSelectionsUpModifyingSelection:YES];
}

- (void)moveDown:(id)sender
{
    [self mpx_moveSelectionsDownModifyingSelection:NO];
}

- (void)moveDownAndModifySelection:(id)sender
{
    [self mpx_moveSelectionsDownModifyingSelection:YES];
}

#pragma mark Semantic Directional Movements (alias to explicit ones)

- (void)moveBackward:(id)sender
{
    [self moveLeft:sender];
}

- (void)moveBackwardAndModifySelection:(id)sender
{
    [self moveLeftAndModifySelection:sender];
}

- (void)moveForward:(id)sender
{
    [self moveRight:sender];
}

- (void)moveForwardAndModifySelection:(id)sender
{
    [self moveRightAndModifySelection:sender];
}

#pragma mark -

#pragma mark - Mouse Events

- (void)mpx_mouseDragged:(NSEvent *)theEvent
{
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(mpx_performOriginalJump:) object:nil];

    [self.mpx_textViewSelectionDecorator stopBlinking];

    NSRange rangeInProgress = self.mpx_rangeInProgress.range;
    NSRange rangeInProgressOrigin = self.mpx_rangeInProgressStart.range;

    if (rangeInProgress.location == NSNotFound || rangeInProgressOrigin.location == NSNotFound)
    {
        return;
    }

    CGPoint clickLocation = [self convertPoint:[theEvent locationInWindow] fromView:nil];
    NSUInteger index = [self characterIndexForInsertionAtPoint:clickLocation];
    NSRange newRange;

    if (index > rangeInProgressOrigin.location)
    {
        newRange = NSMakeRange(rangeInProgressOrigin.location, index - rangeInProgressOrigin.location);
    }
    else
    {
        newRange = NSMakeRange(index, (rangeInProgressOrigin.location + rangeInProgressOrigin.length) - index);
    }

    // Update the model value for when it is used combinatorily.
    self.mpx_rangeInProgress = [MPXSelection selectionWithRange:newRange];

    [self.mpx_selectionManager setTemporarySelections:[self.mpx_selectionManager.finalizedSelections arrayByAddingObject:[MPXSelection selectionWithRange:newRange]]];
}

- (void)mpx_performOriginalJump:(NSTimer *)sender
{
    NSEvent *mouseDownEvent = sender.userInfo;
    if (!CGPointEqualToPoint(self.window.mouseLocationOutsideOfEventStream, [mouseDownEvent locationInWindow])) {
        return;     
    }

    [self.mpx_selectionManager setTemporarySelections:nil];
    self.mpx_rangeInProgress = [MPXSelection selectionWithRange:NSMakeRange(NSNotFound, 0)];
    self.mpx_rangeInProgressStart = [MPXSelection selectionWithRange:NSMakeRange(NSNotFound, 0)];

    [self _didClickOnTemporaryLinkWithEvent:mouseDownEvent];
}

- (void)mpx_mouseDown:(NSEvent *)theEvent
{
    NSUInteger index = ({
        CGPoint clickLocation = [self convertPoint:[theEvent locationInWindow]
                                          fromView:nil];
        [self characterIndexForInsertionAtPoint:clickLocation];
    });

    if (index == NSNotFound)
    {
        return;
    }

    NSInteger clickCount = theEvent.clickCount;
    BOOL commandKeyHeld = (theEvent.modifierFlags & NSCommandKeyMask) != 0;

    NSArray *selections = self.mpx_selectionManager.visualSelections;
    NSRange resultRange = NSMakeRange(NSNotFound, 0);
    DVTTextStorage *textStorage = (DVTTextStorage *)self.textStorage;

    switch (clickCount) {
            // Selects only the single point at the approximate location of the cursor
        case 1:
            resultRange = NSMakeRange(index, 0);
            break;
        case 2:
        {
            if ([((DVTLayoutManager *)self.layoutManager).foldingManager firstFoldTouchingCharacterIndex:index])
            {
                [self mpx_mouseDown:theEvent];
                return;
            }

            resultRange = [textStorage doubleClickAtIndex:index];
            break;
        }
        case 3:
            resultRange = [textStorage.string lineRangeForRange:NSMakeRange(index, 0)];
            break;
        default:
            return;
    }

    if (resultRange.location == NSNotFound)
    {
        return;
    }

    [self.mpx_textViewSelectionDecorator stopBlinking];
    [self.mpx_textViewSelectionDecorator setCursorsVisible:YES];

    MPXSelection *selection = [MPXSelection selectionWithRange:resultRange];
    self.mpx_rangeInProgress = selection;
    self.mpx_rangeInProgressStart = selection;

    if (commandKeyHeld)
    {
        [self.mpx_selectionManager setTemporarySelections:[selections arrayByAddingObject:selection]];

        self.mpx_definitionLongPressTimer = [NSTimer timerWithTimeInterval:0.333
                                                                    target:self
                                                                  selector:@selector(mpx_performOriginalJump:)
                                                                  userInfo:theEvent
                                                                   repeats:NO];

        [[NSRunLoop mainRunLoop] addTimer:self.mpx_definitionLongPressTimer forMode:NSDefaultRunLoopMode];
    }
    else
    {
        // Because the click was singular, the other selections will *not* come back under any circumstances.
        // Thus, it must be finalized at the point where it's at is if it's a zero-length selection.
        // Otherwise, they'll be re-added during dragging.
        self.mpx_selectionManager.finalizedSelections = @[selection];

        self.mpx_shouldCloseGroupOnNextChange = YES;

        // In the event the user drags, however, it needs to unfinalized so that it can be extended again.
        [self.mpx_selectionManager setTemporarySelections:@[selection]];
    }
}

- (void)mpx_mouseUp:(NSEvent *)theEvent
{
    [self.mpx_definitionLongPressTimer invalidate];

    self.mpx_selectionManager.finalizedSelections = self.mpx_selectionManager.visualSelections;
    self.mpx_rangeInProgress = [MPXSelection selectionWithRange:NSMakeRange(NSNotFound, 0)];
    self.mpx_rangeInProgressStart = [MPXSelection selectionWithRange:NSMakeRange(NSNotFound, 0)];

    [self.mpx_textViewSelectionDecorator startBlinking];
}


#pragma mark - Range Manipulation

- (void)selectAll:(id)sender
{
    self.mpx_selectionManager.finalizedSelections = @[[MPXSelection selectionWithRange:NSMakeRange(0, [self.textStorage.string length])]];
}

- (void)mpx_mapAndFinalizeSelectedRanges:(MPXSelection * (^)(MPXSelection *selection))mapBlock
{
    [self mpx_mapAndFinalizeSelectedRanges:mapBlock sequentialModification:NO];
}

- (void)mpx_mapAndFinalizeSelectedRanges:(MPXSelection * (^)(MPXSelection *selection))mapBlock
                  sequentialModification:(BOOL)sequentialModification
{
    NSArray *mappedValues = [[[self.mpx_selectionManager.visualSelections rac_sequence] map:mapBlock] array];
    self.mpx_selectionManager.finalizedSelections = mappedValues;

    [self.mpx_textViewSelectionDecorator startBlinking];
}

- (void)_drawInsertionPointInRect:(CGRect)rect color:(NSColor *)color
{

}

#pragma mark - Autocompletion

- (void)mpx_didInsertCompletionTextAtRange:(NSRange)completedTextRange
{
    __block NSInteger offset = 0;

    /* The first range is the one which needs to be outright replaced from the start.
     What's passed back with `completedTextRange` is the first range's replacement. */

    NSArray *selections =
    ({
        NSMutableArray *selections = [[NSMutableArray alloc] initWithArray:self.mpx_selectionManager.visualSelections];

        MPXSelection *existingSelection = selections[0];

        offset += NSMaxRange(completedTextRange) - NSMaxRange(existingSelection.range);

        selections[0] = [MPXSelection selectionWithRange:completedTextRange];
        selections;
    });

    NSString *completionText = [self.string substringWithRange:completedTextRange];

    /* Now, the remaining ranges need to be adjusted to include the text (and adjust the selection.) */

    __block NSUInteger idx = 0;
    NSArray *newSelections = [[selections rac_sequence] map:^MPXSelection *(MPXSelection *selection) {
        NSRange selectionRange = selection.range;

        if (idx > 0)
        {
            selectionRange.location += offset;

            /* First, one needs to reverse-enumerate over the completion text. We're looking for the first match of a character, and then traversing back from there. Then we'll know what, if anything, is already available as a base to complete. If nothing is there, the whole string needs to be inserted.
             */
            NSInteger completionStringIndex = [completionText length] - 1;

            /* Used as the pointer to walk-back from the selection and see what matches. Essentially, we're wanting to find the first substring to match and go back from there to see if it matches the "full" partial substring to the beginning of it. For instance:

             (Completing for the word `category`)

             cate| vs. nate|

             Only chcking the first char before the selection would not be accurate.
             */

            NSInteger selectionRelativeIndex = 0;

            while (completionStringIndex >= 0)
            {
                unichar completionChar = [completionText characterAtIndex:completionStringIndex];
                unichar compareStorageChar = [self.string characterAtIndex:(NSMaxRange(selectionRange) - 1) + selectionRelativeIndex];

                if (completionChar == compareStorageChar)
                {
                    selectionRelativeIndex--;
                }

                /* Always decrement, as we're seeking the first match within the completion string that is found in the text. If a match was found, we need to continue walking back.
                 */
                completionStringIndex--;
            }

            NSInteger completionStringStartIndex = -selectionRelativeIndex;
            NSInteger insertedStringLength = ([completionText length]) - completionStringStartIndex;

            [self insertText:[completionText substringFromIndex:completionStringStartIndex]
            replacementRange:NSMakeRange(NSMaxRange(selectionRange), 0)];

            offset += insertedStringLength;
        }

        NSRange indentedRange = [self _indentInsertedTextIfNecessaryAtRange:selectionRange];

        NSRange firstPlaceholder = [self rangeOfPlaceholderFromCharacterIndex:indentedRange.location
                                                                      forward:YES
                                                                         wrap:YES
                                                                        limit:indentedRange.length];

        idx++;

        if (firstPlaceholder.location == NSUIntegerMax)
        {
            NSRange finalEndOfCompletionRange = NSMakeRange(NSMaxRange(indentedRange), 0);
            return [MPXSelection selectionWithRange:finalEndOfCompletionRange];
        }

        return [MPXSelection selectionWithRange:firstPlaceholder];
    }].array;

    self.mpx_selectionManager.finalizedSelections = newSelections;
}

- (BOOL)mpx_shouldAutoCompleteAtLocation:(NSUInteger)location
{
    BOOL internalShouldAutoComplete = [self mpx_shouldAutoCompleteAtLocation:location];

    return (internalShouldAutoComplete &&
            !([self.mpx_selectionManager.visualSelections count] > 1));
}

@end
