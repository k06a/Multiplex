//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSString;

@interface DVTTableCellViewTextField : NSTextField
{
    NSString *_stringValueBeforeEditing;
    BOOL _forceIsEditableToNo;
}

+ (Class)cellClass;
- (void)setNeedsDisplay;
- (void)setFrame:(struct CGRect)arg1;
- (id)_enclosingTableCellView;
- (BOOL)abortEditing;
- (void)textDidEndEditing:(id)arg1;
- (void)textDidChange:(id)arg1;
- (void)textDidBeginEditing:(id)arg1;
- (struct CGSize)intrinsicContentSize;
- (BOOL)isEditable;
- (BOOL)allowsVibrancy;

@end

