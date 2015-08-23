//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class DVTDispatchLock, NSFileManager, NSMutableDictionary;

@interface DVTDownloadableManagerIOCache : NSObject
{
    DVTDispatchLock *_lock;
    NSFileManager *_fileManager;
    NSMutableDictionary *_fileExistsCache;
    NSMutableDictionary *_shasumCache;
    NSMutableDictionary *_packageVersionCache;
}

+ (id)sharedCache;
- (id)packageVersionOfIdentifer:(id)arg1 atInstallPrefix:(id)arg2;
- (id)shasumOfFileAtPath:(id)arg1;
- (BOOL)fileExistsAtPath:(id)arg1;
- (id)_objectForKey:(id)arg1 fromCache:(id)arg2 orCreate:(dispatch_block_t)arg3;
- (void)clear;
- (id)init;

@end

