//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEKit/IDEEditorStepperView.h>

@class IDEActionButton, NSImage;

@interface IDEEditorMenuStepperView : IDEEditorStepperView
{
    IDEActionButton *_actionButton;
    id  _delegate;
}

+ (id)keyPathsForValuesAffectingCanMove;
@property(retain) id  delegate; // @synthesize delegate=_delegate;
- (void)primitiveInvalidate;
- (void)setGradientStyle:(int)arg1;
- (void)selectPrevious:(id)arg1;
- (void)selectNext:(id)arg1;
- (BOOL)canMove;
- (id)menuForActionButton;
- (struct CGSize)centerViewSizeInHeight:(double)arg1;
- (id)newCenterView;
@property(retain) NSImage *image;

@end
