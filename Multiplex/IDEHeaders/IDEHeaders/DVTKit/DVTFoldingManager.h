//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "DVTInvalidation-Protocol.h"

@class DVTStackBacktrace, DVTTextFold, NSString;

@interface DVTFoldingManager : NSObject <DVTInvalidation>
{
    DVTTextFold *_topLevelFold;
    id  delegate;
}

+ (void)initialize;
@property(retain, nonatomic) DVTTextFold *topLevelFold; // @synthesize topLevelFold=_topLevelFold;
@property __weak id  delegate; // @synthesize delegate;
- (id)fixedSelectionRangesForRanges:(id)arg1 affinity:(unsigned long long)arg2 inTextView:(id)arg3;
- (id)adjustFoldsForRange:(struct _NSRange)arg1 changeInLength:(long long)arg2;
- (id)foldsEnclosingRange:(struct _NSRange)arg1;
- (id)lastFoldTouchingCharacterIndex:(unsigned long long)arg1;
- (id)firstFoldTouchingCharacterIndex:(unsigned long long)arg1;
- (id)blockFoldsTouchingRange:(struct _NSRange)arg1;
- (id)allFoldsTouchingRange:(struct _NSRange)arg1;
- (BOOL)isRangeInsideAFold:(struct _NSRange)arg1;
- (BOOL)isCharacterRangeFolded:(struct _NSRange)arg1;
- (BOOL)containsFoldWithRange:(struct _NSRange)arg1;
- (BOOL)isCharacterFoldedAtIndex:(unsigned long long)arg1;
- (void)foldRangesRecursively:(id)arg1;
- (void)unfoldRanges:(id)arg1;
- (void)foldRanges:(id)arg1;
- (void)unfoldRecursiveRange:(struct _NSRange)arg1;
- (void)unfoldEnclosingRange:(struct _NSRange)arg1;
- (void)unfoldRange:(struct _NSRange)arg1;
- (void)unfoldAtCharacterIndex:(unsigned long long)arg1;
- (void)unfoldAll;
- (void)unfoldInlineFoldsInRange:(struct _NSRange)arg1;
- (void)foldInlineText:(id)arg1 inRange:(struct _NSRange)arg2 tokenType:(id)arg3;
- (void)foldRange:(struct _NSRange)arg1;
- (void)_applyFoldsRecursively:(id)arg1;
- (void)primitiveInvalidate;
- (id)initWithRange:(struct _NSRange)arg1;
- (id)init;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

