//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"
#import <IDEKit/IDECodesignIssueResolutionAbstractGenerateProfileOption.h>

@class NSSet;

@interface IDECodesignIssueResolutionGenerateDevelopmentProfileOption : IDECodesignIssueResolutionAbstractGenerateProfileOption
{
    NSSet *_requiredCodesignableDevices;
    NSSet *_appIDRequirements;
}

@property(retain) NSSet *appIDRequirements; // @synthesize appIDRequirements=_appIDRequirements;
@property(retain) NSSet *requiredCodesignableDevices; // @synthesize requiredCodesignableDevices=_requiredCodesignableDevices;
- (id)invokeOptionWithWindowOrNil:(id)arg1;
- (id)initWithPortalSource:(id)arg1 account:(id)arg2 signingCertificate:(id)arg3 platformIdentifier:(id)arg4 appIDRequirements:(id)arg5 requiredCodesignableDevices:(id)arg6 logAspect:(id)arg7;

@end

