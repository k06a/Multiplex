//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "ITunesSoftwareServiceUploadDelegate-Protocol.h"

@class NSString;

@interface DVTITunesConnectProxyDelegate : NSObject <ITunesSoftwareServiceUploadDelegate>
{
    dispatch_block_t _willBeginCallback;
    dispatch_block_t _updatePercentageCallback;
    dispatch_block_t _updateMessageCallback;
    dispatch_block_t _shouldContinueCallback;
    dispatch_block_t _didCompleteCallback;
}

@property(copy) dispatch_block_t didCompleteCallback; // @synthesize didCompleteCallback=_didCompleteCallback;
@property(copy) dispatch_block_t shouldContinueCallback; // @synthesize shouldContinueCallback=_shouldContinueCallback;
@property(copy) dispatch_block_t updateMessageCallback; // @synthesize updateMessageCallback=_updateMessageCallback;
@property(copy) dispatch_block_t updatePercentageCallback; // @synthesize updatePercentageCallback=_updatePercentageCallback;
@property(copy) dispatch_block_t willBeginCallback; // @synthesize willBeginCallback=_willBeginCallback;
- (void)softwareService:(id)arg1 didCompleteUploadForApplication:(id)arg2;
- (BOOL)softwareService:(id)arg1 shouldContinueUploadForApplication:(id)arg2;
- (void)softwareService:(id)arg1 didUpdateStatusMessage:(id)arg2 forApplication:(id)arg3;
- (void)softwareService:(id)arg1 didUpdatePercentageComplete:(id)arg2 forApplication:(id)arg3;
- (void)softwareService:(id)arg1 willBeginUploadForApplication:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

