//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "IDEReviewFilesDataSource-Protocol.h"

@class IDENavigatorDataCell, IDEWorkspace, NSArray, NSMutableSet, NSPredicate, NSString;

@interface IDESourceControlReviewFilesDataSource : NSObject <IDEReviewFilesDataSource>
{
    IDENavigatorDataCell *_containerFileRefCell;
    IDENavigatorDataCell *_aggregateContainerFileRefCell;
    IDENavigatorDataCell *_fileReferenceCell;
    IDENavigatorDataCell *_groupCell;
    IDENavigatorDataCell *_plainObjectCell;
    IDENavigatorDataCell *_workingCopyTreeItemCell;
    IDENavigatorDataCell *_workingCopyTreeGroupCell;
    NSMutableSet *_bindingTokens;
    NSArray *_navigableItems;
    NSArray *_statusCategoryNames;
    NSString *_selectedRevisionIdentifier;
    NSPredicate *_filterPredicate;
    IDEWorkspace *_workspace;
}

+ (id)keyPathsForValuesAffectingFlatNavigableItems;
+ (id)keyPathsForValuesAffectingFileSystemNavigableItems;
+ (id)keyPathsForValuesAffectingWorkspaceNavigableItems;
@property(copy) NSArray *statusCategoryNames; // @synthesize statusCategoryNames=_statusCategoryNames;
@property(retain) IDEWorkspace *workspace; // @synthesize workspace=_workspace;
@property(copy) NSString *selectedRevisionIdentifier; // @synthesize selectedRevisionIdentifier=_selectedRevisionIdentifier;
- (void)dealloc;
- (void)teardown;
- (void)reviewFilesNavigator:(id)arg1 outlineView:(id)arg2 willDisplayCell:(id)arg3 forNavigableItem:(id)arg4;
- (id)reviewFilesNavigator:(id)arg1 importantFilePathsForNavigableItem:(id)arg2 excludingDisabledItems:(id)arg3;
- (id)reviewFilesNavigator:(id)arg1 documentLocationForNavigableItem:(id)arg2;
- (id)reviewFilesNavigator:(id)arg1 outlineView:(id)arg2 dataCellForNavigableItem:(id)arg3;
- (id)plainObjectCell;
- (id)workingCopyTreeGroupCell;
- (id)workingCopyTreeItemCell;
- (id)groupCell;
- (id)fileReferenceCell;
- (id)aggregateContainerFileRefCell;
- (id)containerFileRefCell;
- (id)newBasicContainerFileRefCell;
- (id)aggregateSourceControlCategoryStatusCellsWithRepresentedObject:(id)arg1;
- (id)sourceControlCategoryStatusCellsWithRepresentedObject:(id)arg1;
- (id)statusCellsForCategoryName:(id)arg1 representedObject:(id)arg2;
@property(copy) NSPredicate *filterPredicate; // @synthesize filterPredicate=_filterPredicate;
- (id)issueNavigableItems;
@property(readonly) NSArray *flatNavigableItems;
@property(readonly) NSArray *fileSystemNavigableItems;
@property(readonly) NSArray *workspaceNavigableItems;
@property(copy) NSArray *navigableItems; // @synthesize navigableItems=_navigableItems;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

