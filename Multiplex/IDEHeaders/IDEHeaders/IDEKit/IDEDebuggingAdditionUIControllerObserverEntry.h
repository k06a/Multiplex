//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class IDECancellableToken, IDELaunchSession, NSString;

@interface IDEDebuggingAdditionUIControllerObserverEntry : NSObject
{
    IDELaunchSession *_launchSession;
    NSString *_uiControllerID;
    IDECancellableToken *_canellableToken;
    dispatch_block_t _handler;
}

@property(readonly) dispatch_block_t handler; // @synthesize handler=_handler;
@property(readonly) IDECancellableToken *canellableToken; // @synthesize canellableToken=_canellableToken;
@property(readonly) NSString *uiControllerID; // @synthesize uiControllerID=_uiControllerID;
@property(readonly) __weak IDELaunchSession *launchSession; // @synthesize launchSession=_launchSession;
- (id)initWithLaunchSession:(id)arg1 uiControllerID:(id)arg2 handler:(dispatch_block_t)arg3;

@end

