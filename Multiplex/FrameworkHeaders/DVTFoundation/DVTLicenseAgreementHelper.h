//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class NSString;

@interface DVTLicenseAgreementHelper : NSObject
{
    int _installedLicenseType;
    NSString *_installedLicenseID;
}

+ (BOOL)shouldShowLicenseAgreementForInstalledXcodeLicenseID:(id)arg1 lastAgreedToLicenseID:(id)arg2 installedXcodeVersion:(id)arg3 xcodeVersionForLastAgreedToLicense:(id)arg4;
@property(readonly) NSString *installedLicenseID; // @synthesize installedLicenseID=_installedLicenseID;
@property(readonly) int installedLicenseType; // @synthesize installedLicenseType=_installedLicenseType;
- (BOOL)shouldShowLicenseAgreement;
- (BOOL)agreeToLicense;
- (id)_getLoggedInUserName;
- (BOOL)_isRunningAsSuperUser;
- (id)initWithLicenseInfoPath:(id)arg1;

@end

