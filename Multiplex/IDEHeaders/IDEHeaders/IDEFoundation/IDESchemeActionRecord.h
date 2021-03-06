//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class DVTFilePath, IDESchemeActionResult, IDESchemeActionRunDestinationRecord, IDESchemeCommand, NSDate, NSString;

@interface IDESchemeActionRecord : NSObject
{
    int _schemeTask;
    IDESchemeCommand *_schemeCommand;
    NSString *_title;
    NSDate *_startedTime;
    NSDate *_endedTime;
    IDESchemeActionResult *_buildResult;
    IDESchemeActionResult *_actionResult;
    IDESchemeActionRunDestinationRecord *_runDestinationRecord;
    DVTFilePath *_localRecordDirectoryFilePath;
    DVTFilePath *_creatingWorkspaceFilePath;
}

+ (int)schemeTaskForString:(id)arg1;
+ (id)stringForSchemeTask:(int)arg1;
+ (id)schemeCommandForString:(id)arg1;
+ (id)keyPathsForValuesAffectingTestsFailedCount;
+ (id)keyPathsForValuesAffectingTestsCount;
+ (id)keyPathsForValuesAffectingAnalyzerWarningCount;
+ (id)keyPathsForValuesAffectingErrorCount;
+ (id)keyPathsForValuesAffectingWarningCount;
+ (id)keyPathsForValuesAffectingStatus;
+ (BOOL)getSchemeTask:(int *)arg1 fromDictionaryRepresentation:(id)arg2;
@property(retain, nonatomic) DVTFilePath *creatingWorkspaceFilePath; // @synthesize creatingWorkspaceFilePath=_creatingWorkspaceFilePath;
@property(retain, nonatomic) DVTFilePath *localRecordDirectoryFilePath; // @synthesize localRecordDirectoryFilePath=_localRecordDirectoryFilePath;
@property(readonly, nonatomic) IDESchemeActionRunDestinationRecord *runDestinationRecord; // @synthesize runDestinationRecord=_runDestinationRecord;
@property(retain, nonatomic) IDESchemeActionResult *actionResult; // @synthesize actionResult=_actionResult;
@property(retain, nonatomic) IDESchemeActionResult *buildResult; // @synthesize buildResult=_buildResult;
@property(copy, nonatomic) NSDate *endedTime; // @synthesize endedTime=_endedTime;
@property(copy, nonatomic) NSDate *startedTime; // @synthesize startedTime=_startedTime;
@property(copy, nonatomic) NSString *title; // @synthesize title=_title;
@property(readonly, nonatomic) int schemeTask; // @synthesize schemeTask=_schemeTask;
@property(retain, nonatomic) IDESchemeCommand *schemeCommand; // @synthesize schemeCommand=_schemeCommand;
@property(readonly, nonatomic) unsigned long long testsFailedCount;
@property(readonly, nonatomic) unsigned long long testsCount;
@property(readonly, nonatomic) unsigned long long analyzerWarningCount;
@property(readonly, nonatomic) unsigned long long errorCount;
@property(readonly, nonatomic) unsigned long long warningCount;
@property(readonly, nonatomic) int status;
- (id)description;
- (void)close;
- (BOOL)updateWithDictionaryRepresentation:(id)arg1 forSchemeActionsInvocationRecord:(id)arg2;
- (id)dictionaryRepresentationForSchemeActionsInvocationRecord:(id)arg1;
- (BOOL)saveReturningError:(id *)arg1;
- (void)recordRunDestination:(id)arg1;
- (id)init;
- (id)initWithLocalRecordDirectoryFilePath:(id)arg1 creatingWorkspaceFilePath:(id)arg2 schemeTask:(int)arg3;

@end

