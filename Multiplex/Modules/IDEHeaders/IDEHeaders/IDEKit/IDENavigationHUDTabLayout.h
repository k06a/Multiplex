//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class IDENavigationHUDNewSplitTabLayoutCell, IDENavigationHUDTabLayoutCell, IDEWorkspaceTabController, IDEWorkspaceTabControllerLayoutTree, NSArray, NSMapTable;

@interface IDENavigationHUDTabLayout : NSObject
{
    IDENavigationHUDNewSplitTabLayoutCell *_cellRepresentingNewGeniusSplit;
    NSMapTable *_strongLayoutTreeNodeToStrongLayoutCellMap;
    IDEWorkspaceTabControllerLayoutTree *_tabLayoutTree;
    IDEWorkspaceTabController *_workspaceTabController;
    IDENavigationHUDTabLayoutCell *_rootLayoutCell;
}

@property(readonly) IDENavigationHUDNewSplitTabLayoutCell *cellRepresentingNewGeniusSplit; // @synthesize cellRepresentingNewGeniusSplit=_cellRepresentingNewGeniusSplit;
@property(readonly) IDENavigationHUDTabLayoutCell *rootLayoutCell; // @synthesize rootLayoutCell=_rootLayoutCell;
@property(readonly) IDEWorkspaceTabController *workspaceTabController; // @synthesize workspaceTabController=_workspaceTabController;
- (id)tabLayoutCellForLayoutTreeNode:(id)arg1;
@property(readonly) NSArray *orderedPrimaryEditorContextLayoutTreeNodes;
- (id)description;
- (id)initWithWorkspaceTabController:(id)arg1 inNavigationHUDController:(id)arg2;

@end
