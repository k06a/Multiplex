//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import "DVTDocumentLocation-Protocol.h"

@class NSString;

@interface IDEGaugeDocumentLocation : DVTDocumentLocation
{
    BOOL _displaysWhileTracing;
    NSString *_displayName;
    unsigned long long _priority;
}

+ (id)launchSessionFromURL:(id)arg1;
+ (id)URLForScheme:(id)arg1 launchSession:(id)arg2;
+ (id)URLForScheme:(id)arg1 launchSession:(id)arg2 otherQueryString:(id)arg3;
@property BOOL displaysWhileTracing; // @synthesize displaysWhileTracing=_displaysWhileTracing;
@property(readonly) unsigned long long priority; // @synthesize priority=_priority;
@property(readonly) NSString *displayName; // @synthesize displayName=_displayName;
- (id)initWithDisplayName:(id)arg1 documentURL:(id)arg2 priority:(unsigned long long)arg3;

@end

