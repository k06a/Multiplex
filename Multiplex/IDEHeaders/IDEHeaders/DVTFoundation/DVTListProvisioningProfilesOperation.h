//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <DVTFoundation/DVTTeamOperationBase.h>

@class NSSet;

@interface DVTListProvisioningProfilesOperation : DVTTeamOperationBase
{
    NSSet *_profileRecords;
}

+ (id)_operationWithSingleTeamToken:(id)arg1 andPlatform:(id)arg2;
@property(retain, nonatomic) NSSet *profileRecords; // @synthesize profileRecords=_profileRecords;

@end

