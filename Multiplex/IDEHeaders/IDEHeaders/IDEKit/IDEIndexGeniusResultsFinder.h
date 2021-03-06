//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEKit/IDEGeniusResultsFinder.h>

@class DVTDispatchLock;

@interface IDEIndexGeniusResultsFinder : IDEGeniusResultsFinder
{
    id _indexDidChangeNotificationObserver;
    DVTDispatchLock *_generationLock;
    unsigned long long _currentGeneration;
}

- (void)_updateGeniusResults;
- (BOOL)_getUpdateGeniusResultsPhaseOneBlock:(dispatch_block_t *)arg1 phaseTwoBlock:(dispatch_block_t *)arg2 phaseThreeBlock:(dispatch_block_t *)arg3;
- (void)setIdle:(BOOL)arg1;
- (void)primitiveInvalidate;
- (id)_initWithWorkspaceTabController:(id)arg1 navigableItemCoordinator:(id)arg2;

@end

