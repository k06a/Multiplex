//
//  DVTSourceTextView+MPXEditorClipboardSupport.m
//  Multiplex
//
//  Created by Kolin Krewinkel on 8/26/15.
//  Copyright © 2015 Kolin Krewinkel. All rights reserved.
//

@import JRSwizzle;
@import MPXSelectionCore;

#import <DVTKit/DVTLayoutManager.h>
#import <DVTKit/DVTTextStorage.h>

#import "DVTSourceTextView+MPXEditorExtensions.h"

#import "DVTSourceTextView+MPXEditorArrowKeyMovement.h"

@implementation DVTSourceTextView (MPXEditorArrowKeyMovement)

#pragma mark - Convenience

- (NSRange)lineRangeForCharacterIndex:(NSUInteger)characterIndex
{
    NSUInteger glyphIndex = [self.layoutManager glyphIndexForCharacterAtIndex:characterIndex];

    NSRange lineRange;
    [self.layoutManager lineFragmentRectForGlyphAtIndex:glyphIndex effectiveRange:&lineRange];

    return lineRange;
}

#pragma mark - Directional Movemnts

- (void)moveUp:(id)sender
{
    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        NSRange lineRange = [self lineRangeForCharacterIndex:selection.insertionIndex];

        
    }];
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

#pragma mark - Left/Right Movements

- (void)moveBackward:(id)sender
{
    [self moveLeft:sender];
}

- (void)moveLeft:(id)sender
{
    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        NSUInteger newIndex = MAX(selection.insertionIndex - 1, 0);
        return [[MPXSelection alloc] initWithSelectionRange:NSMakeRange(newIndex, 0)
                                      indexWantedWithinLine:selection.indexWantedWithinLine
                                                     origin:selection.origin];
    }];
}

- (void)moveBackwardAndModifySelection:(id)sender
{
    [self moveLeftAndModifySelection:sender];
}

- (void)moveLeftAndModifySelection:(id)sender
{
    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        return [selection modifySelectionUpstreamByAmount:1];
    }];
}

- (void)moveForward:(id)sender
{
    [self moveRight:sender];
}

- (void)moveRight:(id)sender
{
    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        NSUInteger newIndex = MIN(selection.insertionIndex + 1, self.textStorage.length);
        return [[MPXSelection alloc] initWithSelectionRange:NSMakeRange(newIndex, 0)
                                      indexWantedWithinLine:selection.indexWantedWithinLine
                                                     origin:selection.origin];
    }];
}

- (void)moveForwardAndModifySelection:(id)sender
{
    [self moveRightAndModifySelection:sender];
}

- (void)moveRightAndModifySelection:(id)sender
{
    [self mpx_mapAndFinalizeSelectedRanges:^MPXSelection *(MPXSelection *selection) {
        return [selection modifySelectionDownstreamByAmount:1];
    }];
}

@end
