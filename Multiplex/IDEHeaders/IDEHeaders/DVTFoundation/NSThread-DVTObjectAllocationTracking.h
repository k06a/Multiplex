//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@interface NSThread (DVTObjectAllocationTracking)
+ (id)countedSetOfObjectAllocationDescriptionsOnCurrentThreadWhileInvokingBlock:(dispatch_block_t)arg1;
+ (void)stopTrackingObjectAllocationsOnCurrentThread;
+ (BOOL)isTrackingObjectAllocationsOnCurrentThread;
+ (void)startTrackingObjectAllocationsOnCurrentThreadUsingBlock:(dispatch_block_t)arg1;
@end
