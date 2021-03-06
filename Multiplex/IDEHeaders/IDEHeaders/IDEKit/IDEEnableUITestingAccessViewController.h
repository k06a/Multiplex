//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"


@class NSButton, NSProgressIndicator, NSString, NSTextField;

@interface IDEEnableUITestingAccessViewController : NSViewController <NSTextViewDelegate>
{
    NSTextField *_titleText;
    NSTextField *_descriptionText;
    NSButton *_accessButton;
    NSButton *_skipButton;
    NSProgressIndicator *_progressBar;
    dispatch_block_t skipHandler;
    dispatch_block_t requestAccessHandler;
}

@property(copy) dispatch_block_t requestAccessHandler; // @synthesize requestAccessHandler;
@property(copy) dispatch_block_t skipHandler; // @synthesize skipHandler;
- (void)skip:(id)arg1;
- (void)requestAccess:(id)arg1;
- (void)viewDidAppear;
- (id)initWithDefaultNib;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

