//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEFoundation/IDEExecutionTracker.h>

@class DVTObservingToken, DVTOperation;

@interface IDEExecutionOperationTracker : IDEExecutionTracker
{
    DVTOperation *_operation;
    DVTObservingToken *_isFinishedObservingToken;
    BOOL _operationFinished;
}

@property(nonatomic) BOOL operationFinished; // @synthesize operationFinished=_operationFinished;
@property(retain) DVTOperation *operation; // @synthesize operation=_operation;
- (id)notFinishedReasonWithDepth:(unsigned long long)arg1;
- (BOOL)isFinished;
- (void)cancelWithReason:(int)arg1;
- (id)initWithOperation:(id)arg1;
- (id)initWithOperation:(id)arg1 serviceTier:(int)arg2;

@end

