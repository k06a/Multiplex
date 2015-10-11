//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEFoundation/IDEOnDiskLogStore.h>

@class NSMutableDictionary, NSOperationQueue, NSString;

@interface IDEOnDiskLogStore_Impl : IDEOnDiskLogStore
{
    NSString *_rootDirectoryPath;
    NSMutableDictionary *_cache;
    NSMutableDictionary *_cachedLogs;
    NSOperationQueue *_asyncOperations;
    BOOL _preserveOldLogs;
}

+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
+ (void)initialize;
- (BOOL)preserveOldLogs;
- (id)description;
- (void)setPreserveOldLogs:(BOOL)arg1;
- (id)_pathForUniqueIdentifier:(id)arg1;
- (void)_removeAllButTheLatestLog;
- (void)_pruneLogsToLogStoreSizeLimit;
- (void)_removeLogRecord:(id)arg1 completionBlock:(dispatch_block_t)arg2;
- (void)_moveToRootDirectoryAtPath:(id)arg1 errorBlock:(dispatch_block_t)arg2;
- (id)addLog:(id)arg1 entityIdentifier:(id)arg2 completionBlock:(dispatch_block_t)arg3;
- (void)_saveLog:(id)arg1 logRecord:(id)arg2 toPath:(id)arg3 completionBlock:(dispatch_block_t)arg4;
- (BOOL)_saveCacheWithError:(id *)arg1;
- (id)_cachePath;
- (id)coverageReportFilePathForActivityLogSection:(id)arg1;
- (id)testableSummariesPlistFilePathForActivityLogSection:(id)arg1;
- (id)rootDirectoryPath;
- (void)primitiveInvalidate;
- (id)initWithRootDirectoryAtPath:(id)arg1 error:(id *)arg2;

@end
