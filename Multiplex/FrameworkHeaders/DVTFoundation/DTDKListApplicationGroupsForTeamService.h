//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <DVTFoundation/DTDKTeamBasedService.h>

@class NSArray;

@interface DTDKListApplicationGroupsForTeamService : DTDKTeamBasedService
{
    NSArray *_cloudContainers;
}

+ (id)guaranteedComprehensiveResponseKeys;
+ (id)serviceForTeam:(id)arg1 andPlatform:(id)arg2;
@property(readonly) NSArray *cloudContainers; // @synthesize cloudContainers=_cloudContainers;

@end

