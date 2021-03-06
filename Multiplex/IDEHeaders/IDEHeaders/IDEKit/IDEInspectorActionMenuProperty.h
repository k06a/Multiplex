//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEKit/IDEInspectorAbstractActionProperty.h>

@class IDEInspectorKeyPath, NSArray, NSPopUpButton, NSString;

@interface IDEInspectorActionMenuProperty : IDEInspectorAbstractActionProperty
{
    NSArray *_menuItems;
    IDEInspectorKeyPath *_menuItemsKeyPath;
    NSString *_title;
    IDEInspectorKeyPath *_titleKeyPath;
    IDEInspectorKeyPath *_targetKeyPath;
    NSPopUpButton *_pullDown;
}

@property(retain, nonatomic) NSPopUpButton *pullDown; // @synthesize pullDown=_pullDown;
- (void)setupRefreshTriggersAndConfigure;
- (void)refresh;
- (id)staticMenuItems;
- (void)applyMenuItemsToPullDown:(id)arg1;
- (void)refreshTarget;
- (void)refreshTitle:(id)arg1;
- (double)baseline;
- (void)broadcastAction:(id)arg1;

@end

