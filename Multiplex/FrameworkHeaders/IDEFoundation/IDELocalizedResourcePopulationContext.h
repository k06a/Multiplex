//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEFoundation/IDELocalizationWorkContext.h>

#import "IDELocalizationWorkProvider-Protocol.h"

@class IDEContainer<IDELocalizedContainer>, NSDictionary, NSMutableDictionary;

@interface IDELocalizedResourcePopulationContext : IDELocalizationWorkContext <IDELocalizationWorkProvider>
{
    NSMutableDictionary *_adaptorsByGroupIdentifier;
    IDEContainer *_container;
}

+ (id)contextWithParent:(id)arg1 container:(id)arg2;
@property(retain) IDEContainer *container; // @synthesize container=_container;
@property(readonly) NSDictionary *adaptorsByGroupIdentifier; // @synthesize adaptorsByGroupIdentifier=_adaptorsByGroupIdentifier;
- (id)work;
- (void)primitiveInvalidate;
- (void)setAdaptor:(id)arg1 forGroupIdentifier:(id)arg2;
- (id)init;

@end
