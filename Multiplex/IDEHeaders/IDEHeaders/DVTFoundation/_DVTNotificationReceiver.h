//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class DVTStackBacktrace, NSOperationQueue, NSString;

@interface _DVTNotificationReceiver : NSObject
{
    id _observer;
    SEL _selector;
    NSOperationQueue *_queue;
    dispatch_block_t _block;
    BOOL _registeredWithBlock;
    DVTStackBacktrace *_creationBacktrace;
    NSString *_notificationName;
}

- (void)receiveNotification:(id)arg1;
- (id)initWithBlock:(dispatch_block_t)arg1 queue:(id)arg2;
- (id)initWithObserver:(id)arg1 selector:(SEL)arg2;

@end

