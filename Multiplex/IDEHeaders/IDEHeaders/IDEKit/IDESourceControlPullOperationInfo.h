//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEKit/IDESourceControlUpdateOperationInfo.h>

@class IDESourceControlBranch, IDESourceControlRepository;

@interface IDESourceControlPullOperationInfo : IDESourceControlUpdateOperationInfo
{
    IDESourceControlRepository *_remote;
    IDESourceControlBranch *_remoteBranch;
}

@property(retain) IDESourceControlBranch *remoteBranch; // @synthesize remoteBranch=_remoteBranch;
@property(retain) IDESourceControlRepository *remote; // @synthesize remote=_remote;
- (void)primitiveInvalidate;
- (id)processInfoWithProgressBlock:(dispatch_block_t)arg1 isSingleOperation:(BOOL)arg2 completionBlock:(dispatch_block_t)arg3;
- (int)statusForWorkingTreeItem:(id)arg1;

@end

