//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEFoundation/IDEIssueProvider.h>

#import "IDETestsInTestableObserver-Protocol.h"

@class IDEWorkspace, NSMutableArray, NSMutableDictionary, NSMutableSet, NSString;

@interface IDETestableIssueProvider : IDEIssueProvider <IDETestsInTestableObserver>
{
    IDEWorkspace *_workspace;
    NSMutableDictionary *_issuesByTestID;
    NSMutableArray *_genericIssues;
    unsigned long long _currentIssueGeneration;
    NSMutableSet *_observedTestables;
}

+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
- (void)_processResult:(id)arg1;
- (void)_addIssuesForTest:(id)arg1 issues:(id)arg2 isGeneric:(BOOL)arg3;
- (void)_clearIssuesForTest:(id)arg1;
- (void)_postTestIssue:(id)arg1 forTestable:(id)arg2;
- (id)_documentLocationForFilePath:(id)arg1 lineNumber:(id)arg2 timestamp:(id)arg3;
- (id)_headingNameForTest:(id)arg1;
- (void)_beginNewIssueGeneration;
- (BOOL)_filterIssuesByActiveScheme;
- (id)displayNameForIssueTypeIdentifier:(id)arg1;
- (void)testsChanged:(id)arg1;
- (void)testablesChanged:(id)arg1;
- (void)allTestablesChanged;
- (void)_updateObservedTestablesForTest:(id)arg1;
- (void)primitiveInvalidate;
- (id)_initWithWorkspace:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

