//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "DVTTextCompletionItem-Protocol.h"

@class NSArray, NSAttributedString, NSImage, NSString;

@interface DVTStringTextCompletionItem : NSObject <DVTTextCompletionItem>
{
    NSString *_name;
    NSString *_localizedName;
    NSImage *_icon;
    double _priority;
    long long _priorityBucket;
    unsigned long long _priorityComparatorKind;
}

@property unsigned long long priorityComparatorKind; // @synthesize priorityComparatorKind=_priorityComparatorKind;
@property long long priorityBucket; // @synthesize priorityBucket=_priorityBucket;
@property(retain) NSImage *icon; // @synthesize icon=_icon;
@property double priority; // @synthesize priority=_priority;
@property(copy) NSString *localizedName; // @synthesize localizedName=_localizedName;
@property(copy) NSString *name; // @synthesize name=_name;
@property(readonly) BOOL notRecommended;
@property(readonly, copy) NSAttributedString *descriptionText;
@property(readonly, copy) NSString *completionText;
@property(readonly, copy) NSString *parentText;
@property(readonly, copy) NSString *displayType;
@property(readonly, copy) NSString *displayText;
@property(readonly) unsigned long long hash;
- (BOOL)isEqual:(id)arg1;
@property(readonly, copy) NSString *description;
- (id)initWithName:(id)arg1;

// Remaining properties
@property(readonly, copy) NSArray *additionalCompletions;
@property(readonly) int completionItemStyle;
@property(readonly, copy) NSString *debugDescription;
@property(readonly) NSImage *highlightedStatusIcon;
@property(readonly) NSImage *statusIcon;
@property(readonly) Class superclass;

@end

