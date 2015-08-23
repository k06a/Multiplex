//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <DVTKit/DVTLibraryDetailController.h>

@class DVTAssetDetailTextView;

@interface DVTTextLibraryDetailController : DVTLibraryDetailController
{
    DVTAssetDetailTextView *_textView;
    struct {
        unsigned int delegateImplementsTextForAsset:1;
        unsigned int _reserved:7;
    } _flags;
}

@property(readonly) DVTAssetDetailTextView *textView; // @synthesize textView=_textView;
- (void)sizeToFitSuggestedSize:(struct CGSize)arg1 forAsset:(id)arg2;
- (void)refreshWithAsset:(id)arg1 representedObject:(id)arg2;
- (void)viewDidInstall;
- (void)setDelegate:(id)arg1;

@end

