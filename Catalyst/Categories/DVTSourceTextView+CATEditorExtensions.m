//
//  IDESourceCodeEditor+CATViewReplacement.m
//  Catalyst
//
//  Created by Kolin Krewinkel on 9/25/14.
//  Copyright (c) 2014 Kolin Krewinkel. All rights reserved.
//

@import QuartzCore;

#import <INPopoverController/INPopoverController.h>
#import <libextobjc/extobjc.h>
#import <pop/POP.h>
#import <ReactiveCocoa/ReactiveCocoa.h>

#import "DVTSourceTextView+CATEditorExtensions.h"

#import "CATNextNavigator.h"
#import "CATNavigatorTarget.h"
#import "PLYSwizzling.h"

static IMP CMDDVTSourceTextViewOriginalInit = nil;
static IMP CMDDVTSourceTextViewOriginalMouseDragged = nil;

@implementation DVTSourceTextView (CATEditorExtensions)

@synthesizeAssociation(DVTSourceTextView, cat_blinkTimer);
@synthesizeAssociation(DVTSourceTextView, cat_blinkState);
@synthesizeAssociation(DVTSourceTextView, cat_rangeInProgressStart);
@synthesizeAssociation(DVTSourceTextView, cat_rangeInProgress);
@synthesizeAssociation(DVTSourceTextView, cat_finalizingRanges);
@synthesizeAssociation(DVTSourceTextView, cat_selectedRanges);
@synthesizeAssociation(DVTSourceTextView, cat_selectionViews);
@synthesizeAssociation(DVTSourceTextView, cat_nextNavigator);

#pragma mark -
#pragma mark NSObject

+ (void)load
{
    CMDDVTSourceTextViewOriginalInit = PLYPoseSwizzle(self, @selector(_commonInitDVTSourceTextView), self, @selector(cat_commonInitDVTSourceTextView), YES);
    CMDDVTSourceTextViewOriginalMouseDragged = PLYPoseSwizzle(self, @selector(mouseDragged:), self, @selector(cat_mouseDragged:), YES);
}

#pragma mark -
#pragma mark Initializer

- (void)cat_commonInitDVTSourceTextView
{
    self.cat_rangeInProgress = [NSValue valueWithRange:NSMakeRange(NSNotFound, 0)];
    self.cat_rangeInProgressStart = [NSValue valueWithRange:NSMakeRange(NSNotFound, 0)];

    self.cat_blinkTimer = [NSTimer timerWithTimeInterval:0.5 target:self selector:@selector(cat_blinkCursors:) userInfo:nil repeats:YES];
    [[NSRunLoop mainRunLoop] addTimer:self.cat_blinkTimer forMode:NSRunLoopCommonModes];

    [NSEvent addLocalMonitorForEventsMatchingMask:NSKeyDownMask handler:^NSEvent *(NSEvent *event)
     {
         if ([[self window] firstResponder] == self)
         {

             if (event.modifierFlags & NSAlternateKeyMask && [event.charactersIgnoringModifiers isEqualToString:@" "])
             {

                 NSMutableArray *items = [[NSMutableArray alloc] init];
                 DVTTextStorage *textStorage = (DVTTextStorage *)self.textStorage;

                 [[self cat_effectiveSelectedRanges] enumerateObjectsUsingBlock:^(NSValue *vRange, NSUInteger idx, BOOL *stop)
                  {
                      NSRange range = [vRange rangeValue];

                      DVTSourceModelItem *modelItem = [textStorage.sourceModelService sourceModelItemAtCharacterIndex:range.location];

                      NSUInteger count = 0;
                      NSRectArray rects = [self.layoutManager rectArrayForCharacterRange:modelItem.range withinSelectedCharacterRange:modelItem.range inTextContainer:self.textContainer rectCount:&count];

                      CATNavigatorTarget *target = [[CATNavigatorTarget alloc] initWithRect:rects[count - 1]
                                                                                  modelItem:modelItem];
                      [items addObject:target];
                  }];

                 self.cat_nextNavigator = [[CATNextNavigator alloc] initWithView:self.superview
                                                                     targetItems:items
                                                                   layoutManager:self.layoutManager];
                 [self.cat_nextNavigator showItems:items];


                 return nil;
             }
         }

         return event;
     }];

    CMDDVTSourceTextViewOriginalInit(self, @selector(_commonInitDVTSourceTextView));
}

#pragma mark -
#pragma mark Setters

- (BOOL)isSelectable
{
    return NO;
}

#pragma mark -
#pragma mark Events

- (void)moveToBeginningOfDocument:(id)sender
{
    [self cat_setSelectedRanges:@[[NSValue valueWithRange:NSMakeRange(0, 0)]]
                      finalized:YES];
}

- (void)moveToEndOfDocument:(id)sender
{
    NSUInteger documentLength = [self.textStorage.string length];
    [self cat_setSelectedRanges:@[[NSValue valueWithRange:NSMakeRange(documentLength - 1, 0)]]
                      finalized:YES];
}

- (void)moveCursorsToLineRelativeRangeIncludingLength:(BOOL)includeLength
{
    NSMutableArray *newRanges = [[NSMutableArray alloc] init];
    [[self cat_effectiveSelectedRanges] enumerateObjectsUsingBlock:^(NSValue *vRange,
                                                                     NSUInteger idx,
                                                                     BOOL *stop)
     {
         NSRange range = [vRange rangeValue];

         // The cursors are being pushed to the line's relative location of 0 or .length.
         NSRange rangeOfContainingLine = [self.textStorage.string lineRangeForRange:range];
         NSRange cursorRange = NSMakeRange(rangeOfContainingLine.location, 0);

         if (includeLength)
         {
             cursorRange.location += rangeOfContainingLine.length - 1;
         }

         // Add the range with length of 0 at the position on the line.
         [newRanges addObject:[NSValue valueWithRange:cursorRange]];
     }];

    [self cat_setSelectedRanges:newRanges
                      finalized:YES];
}

- (void)moveToLeftEndOfLine:(id)sender
{
    [self moveCursorsToLineRelativeRangeIncludingLength:NO];
}

- (void)moveToRightEndOfLine:(id)sender
{
    [self moveCursorsToLineRelativeRangeIncludingLength:YES];
}

- (void)moveLeft:(id)sender
{
    NSMutableArray *ranges = [[NSMutableArray alloc] init];
    [[self cat_effectiveSelectedRanges] enumerateObjectsUsingBlock:^(NSValue *vRange, NSUInteger idx, BOOL *stop) {
        NSRange range = [vRange rangeValue];
        NSRange newRange = range;

        if (range.length == 0)
        {
            if (range.location > 0)
            {
                newRange.location = range.location - 1;
            }
        }
        else
        {
            newRange.length = 0;
        }

        [ranges addObject:[NSValue valueWithRange:newRange]];
    }];

    [self cat_setSelectedRanges:ranges finalized:(self.cat_finalizingRanges == nil)];
}

- (void)moveRight:(id)sender
{
    NSMutableArray *ranges = [[NSMutableArray alloc] init];
    [[self cat_effectiveSelectedRanges] enumerateObjectsUsingBlock:^(NSValue *vRange, NSUInteger idx, BOOL *stop) {
        NSRange range = [vRange rangeValue];
        NSRange newRange = range;

        if (range.length == 0)
        {
            if (range.location < self.textStorage.length)
            {
                newRange.location = range.location + 1;
            }
        }
        else
        {
            newRange.location = range.location + range.length;
            newRange.length = 0;
        }

        [ranges addObject:[NSValue valueWithRange:newRange]];
    }];

    [self cat_setSelectedRanges:ranges finalized:(self.cat_finalizingRanges == nil)];
}

- (void)moveUp:(id)sender
{

}

- (void)moveDown:(id)sender
{

}

- (void)cat_blinkCursors:(NSTimer *)sender
{
    if ([self.cat_selectionViews count] == 0)
    {
        return;
    }

    BOOL previous = self.cat_blinkState;

    [self.cat_selectionViews enumerateKeysAndObjectsUsingBlock:^(id key, NSView *view, BOOL *stop) {
        if (view != self)
        {
            if (self.window.isKeyWindow)
            {
                view.hidden = !previous;
            }
            else
            {
                view.hidden = YES;
            }
        }
    }];

    self.cat_blinkState = !self.cat_blinkState;
}

- (void)insertText:(id)insertObject
{
    NSString *insertString = (NSString *)insertObject;

    // Prevents random stuff being thrown in.
    if (![insertString isKindOfClass:[NSString class]])
    {
        return;
    }

    // Sequential (negative) offset of characters added.
    __block NSInteger totalDelta = 0;

    // The updated-0 length, and offseted, ranges to replace the old ones after insertion.
    NSMutableArray *newRanges = [[NSMutableArray alloc] init];
    [self.cat_selectedRanges enumerateObjectsUsingBlock:^(NSValue *vRange,
                                                          NSUInteger idx,
                                                          BOOL *stop)
     {
         NSRange range = [vRange rangeValue];

         // Offset by the previous mutations made (+/- doesn't matter, as long as the different maths at each point correspond to the relative offset made by inserting a # of chars.)
         NSRange offsetRange = NSMakeRange(range.location + totalDelta, range.length);
         [self insertText:insertString replacementRange:offsetRange];

         // Move cursor (or range-selection) to the end of what was just added with 0-length.
         NSRange newInsertionPointRange = NSMakeRange(offsetRange.location + [insertString length], 0);
         [newRanges addObject:[NSValue valueWithRange:newInsertionPointRange]];

         // Offset the following ones by noting the original length and updating for the replacement's length, moving cursors following forward/backward.
         NSInteger delta = range.length - [insertString length];
         totalDelta -= delta;
     }];

    // Update the ranges, and force finalization.
    [self cat_setSelectedRanges:newRanges finalized:YES];
}

- (void)deleteBackward:(id)sender
{
    // Sequential (negative) offset of characters added.
    __block NSInteger totalDelta = 0;

    // Replacement insertion-pointer ranges
    NSMutableArray *newRanges = [[NSMutableArray alloc] init];

    // _Never_ concurrent. Always synchronous-in order.
    [self.cat_selectedRanges enumerateObjectsUsingBlock:^(NSValue *vRange,
                                                          NSUInteger idx,
                                                          BOOL *stop)
     {
         // Update the base range with the delta'd amount of change from previous mutations.
         NSRange range = [vRange rangeValue];
         NSRange offsetRange = NSMakeRange(range.location + totalDelta, range.length);

         NSLog(@"Offset range: %@", NSStringFromRange(offsetRange));

         NSRange deletingRange = NSMakeRange(0, 0);
         if (offsetRange.length == 0)
         {
             deletingRange = NSMakeRange(offsetRange.location - 1, 1);
         }
         else
         {
             deletingRange = NSMakeRange(offsetRange.location, offsetRange.length);
         }

         NSLog(@"Range deleting: %@", NSStringFromRange(deletingRange));

         // Delete the characters
         [self insertText:@"" replacementRange:deletingRange];

         // New range for the beam (to the beginning of the range we replaced)
         NSRange newInsertionPointRange = NSMakeRange(deletingRange.location, 0);
         [newRanges addObject:[NSValue valueWithRange:newInsertionPointRange]];

         // Increment/decrement the delta by how much we trimmed.
         totalDelta -= deletingRange.length;
     }];

    // Update the ranges, and force finalization.
    [self cat_setSelectedRanges:newRanges finalized:YES];
}

- (void)cat_mouseDragged:(NSEvent *)theEvent
{
    NSRange rangeInProgress = [self.cat_rangeInProgress rangeValue];
    NSRange rangeInProgressOrigin = [self.cat_rangeInProgressStart rangeValue];

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
    self.cat_rangeInProgress = [NSValue valueWithRange:newRange];

    [self cat_setSelectedRanges:[self.cat_selectedRanges arrayByAddingObject:[NSValue valueWithRange:newRange]] finalized:NO];
}

- (void)mouseDown:(NSEvent *)theEvent
{
    BOOL commandKeyHeld = (theEvent.modifierFlags & NSCommandKeyMask) != 0;

    NSArray *existingSelections = [self cat_effectiveSelectedRanges];
    if (!existingSelections)
    {
        existingSelections = @[];
    }

    CGPoint clickLocation = [self convertPoint:[theEvent locationInWindow] fromView:nil];
    NSUInteger index = [self characterIndexForInsertionAtPoint:clickLocation];

    NSRange rangeOfSelection = NSMakeRange(index, 0);
    self.cat_rangeInProgress = [NSValue valueWithRange:rangeOfSelection];
    self.cat_rangeInProgressStart = [NSValue valueWithRange:rangeOfSelection];

    if (commandKeyHeld)
    {
        [self cat_setSelectedRanges:[existingSelections arrayByAddingObject:[NSValue valueWithRange:rangeOfSelection]] finalized:NO];
    }
    else
    {
        [self cat_setSelectedRanges:@[[NSValue valueWithRange:rangeOfSelection]] finalized:YES];
        [self cat_setSelectedRanges:@[[NSValue valueWithRange:rangeOfSelection]] finalized:NO];
    }
}

- (void)mouseUp:(NSEvent *)theEvent
{
    [self cat_setSelectedRanges:[self cat_effectiveSelectedRanges] finalized:YES];
    self.cat_rangeInProgress = [NSValue valueWithRange:NSMakeRange(NSNotFound, 0)];
    self.cat_rangeInProgressStart = [NSValue valueWithRange:NSMakeRange(NSNotFound, 0)];
}

- (void)mouseMoved:(NSEvent *)theEvent
{
    NSRect frameRelativeToWindow = [self convertRect:self.frame
                                              toView:nil];
    NSRect frameRelativeToScreen = [self.window convertRectToScreen:frameRelativeToWindow];

    if (CGRectContainsPoint(frameRelativeToScreen, [NSEvent mouseLocation])
        && [NSCursor currentCursor] != [NSCursor IBeamCursor])
    {
        [[NSCursor IBeamCursor] push];
    }
}

- (void)mouseEntered:(NSEvent *)theEvent
{
    [[NSCursor IBeamCursor] push];
}

- (void)mouseExited:(NSEvent *)theEvent
{
    [[NSCursor IBeamCursor] pop];
}

#pragma mark -
#pragma mark Setters

- (NSArray *)derivedRanges:(NSArray *)ranges
{
    NSArray *sortedRanges = [self sortedRanges:ranges];
    NSArray *reducedRanges = [self reducedRanges:sortedRanges];

    return reducedRanges;
}

- (NSArray *)sortedRanges:(NSArray *)ranges
{
    return [ranges sortedArrayUsingComparator:^NSComparisonResult(NSValue *vRange1, NSValue *vRange2) {
        NSRange range1 = [vRange1 rangeValue];
        NSInteger range1Loc = range1.location;

        NSRange range2 = [vRange2 rangeValue];
        NSInteger range2Loc = range2.location;

        if (range2Loc > range1Loc)
        {
            return NSOrderedAscending;
        }
        else if (range2Loc < range1Loc)
        {
            return NSOrderedDescending;
        }

        return NSOrderedSame;
    }];
}

- (NSArray *)reducedRanges:(NSArray *)sortedRanges
{
    NSMutableArray *reducedRanges = [[NSMutableArray alloc] init];
    NSMutableArray *shouldCompare = [[NSMutableArray alloc] init];

    [sortedRanges enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        [shouldCompare addObject:@YES];
    }];

    [sortedRanges enumerateObjectsWithOptions:0 usingBlock:^(NSValue *vRange1, NSUInteger idx, BOOL *stop)
     {
         if (![shouldCompare[idx] boolValue])
         {
             return;
         }

         NSRange range1 = [vRange1 rangeValue];

         __block NSRange rangeToAdd = range1;
         __block BOOL shouldAdd = YES;

         [sortedRanges enumerateObjectsWithOptions:0 usingBlock:^(NSValue *vRange2, NSUInteger idx2, BOOL *stop2)
          {
              NSRange range2 = [vRange2 rangeValue];

              BOOL literallyTheSameRange = idx == idx2;

              if (literallyTheSameRange)
              {
                  return;
              }

              BOOL endsBeyondStartOfRange = range2.location + range2.length >= rangeToAdd.location;
              BOOL startsBeforeOrWithinRange = range2.location <= rangeToAdd.location + rangeToAdd.length;

              if (endsBeyondStartOfRange && startsBeforeOrWithinRange)
              {
                  NSRange originalRangeToAdd = rangeToAdd;
                  shouldCompare[idx2] = @NO;

                  NSInteger relativeIncrease = (rangeToAdd.location + rangeToAdd.length) - range2.location;
                  if (relativeIncrease < range2.length)
                  {
                      rangeToAdd.length += range2.length - relativeIncrease;
                  }

                  if (NSEqualRanges(originalRangeToAdd, [self.cat_rangeInProgress rangeValue]))
                  {
                      self.cat_rangeInProgress = [NSValue valueWithRange:rangeToAdd];
                  }
              }
          }];

         [reducedRanges enumerateObjectsUsingBlock:^(NSValue *vRange2, NSUInteger idx, BOOL *stop)
          {
              NSRange range2 = [vRange2 rangeValue];
              BOOL equivalentRanges = NSEqualRanges(rangeToAdd, range2);
              if (equivalentRanges)
              {
                  shouldAdd = NO;
                  *stop = YES;
                  return;
              }
          }];


         if (shouldAdd)
         {
             [reducedRanges addObject:[NSValue valueWithRange:rangeToAdd]];
         }
     }];

    return [[NSArray alloc] initWithArray:reducedRanges];
}

- (void)cat_setSelectedRanges:(NSArray *)ranges finalized:(BOOL)finalized
{
    ranges = [self derivedRanges:ranges];

    if (finalized)
    {
        if ([self.cat_selectedRanges isEqual:ranges] && self.cat_finalizingRanges == nil)
        {
            return;
        }

        self.cat_selectedRanges = ranges;
        self.cat_finalizingRanges = nil;

        NSLog(@"Finalized ranges to %@.", self.cat_selectedRanges);
    }
    else
    {
        if ([ranges isEqualToArray:self.cat_finalizingRanges])
        {
            return;
        }

        self.cat_finalizingRanges = ranges;
    }

    [ranges enumerateObjectsUsingBlock:^(NSValue *vRange, NSUInteger idx, BOOL *stop)
     {
         if (idx == 0)
         {
             NSRange range = [vRange rangeValue];
             self.selectedRange = range;
         }
         else
         {
             *stop = YES;
         }
     }];

    DVTTextStorage *textStorage = (DVTTextStorage *)self.textStorage;
    NSColor *backgroundColor = textStorage.fontAndColorTheme.sourceTextBackgroundColor;

    [self.layoutManager addTemporaryAttribute:NSBackgroundColorAttributeName value:backgroundColor forCharacterRange:NSMakeRange(0, [textStorage.string length])];

    [self.cat_selectionViews enumerateKeysAndObjectsUsingBlock:^(NSValue *value, NSView *view, BOOL *stop)
     {
         if (view != self)
         {
             [view removeFromSuperview];
         }
     }];

    self.cat_selectionViews =
    ({
        DVTTextStorage *textStorage = (DVTTextStorage *)self.textStorage;
        NSMutableDictionary *selectionViews = [[NSMutableDictionary alloc] init];

        [[self cat_effectiveSelectedRanges] enumerateObjectsUsingBlock:^(NSValue *vRange, NSUInteger idx, BOOL *stop)
         {
             NSRange range = [vRange rangeValue];

             NSRange rangeToDraw = range;

             if (range.length > 0)
             {
                 selectionViews[[NSValue valueWithRange:range]] = self;
                 rangeToDraw = NSMakeRange(range.location + range.length, 0);
             }

             CGRect lineLocation = [self.layoutManager lineFragmentRectForGlyphAtIndex:rangeToDraw.location effectiveRange:NULL];
             CGPoint location = [self.layoutManager locationForGlyphAtIndex:rangeToDraw.location];

             NSView *view = [[NSView alloc] init];
             view.wantsLayer = YES;
             view.layer.backgroundColor = [textStorage.fontAndColorTheme.sourceTextInsertionPointColor CGColor];

             CGRect rect = CGRectMake(CGRectGetMinX(lineLocation) + location.x, CGRectGetMaxY(lineLocation) - location.y, 1.f, 18.f);

             [self addSubview:view];

             selectionViews[[NSValue valueWithRect:rect]] = view;
         }];

        selectionViews;
    });
}

- (void)layout
{
    [self.cat_selectionViews enumerateKeysAndObjectsUsingBlock:^(NSValue *vRect, NSView *view, BOOL *stop) {
        CGRect rect = [vRect CGRectValue];
        
        if (view == self)
        {
            NSRange range = [vRect rangeValue];
            
            DVTTextStorage *textStorage = (DVTTextStorage *)self.textStorage;
            NSColor *backgroundColor = textStorage.fontAndColorTheme.sourceTextSelectionColor;
            
            [self.layoutManager addTemporaryAttribute:NSBackgroundColorAttributeName value:backgroundColor forCharacterRange:range];
            
            return;
        }
        
        view.frame = rect;
    }];
    
    [super layout];
}

- (NSArray *)cat_effectiveSelectedRanges
{
    return self.cat_finalizingRanges ? self.cat_finalizingRanges : self.cat_selectedRanges;
}

@end