//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@class DVTLicenseAgreementHelper, NSAttributedString, NSTextField, NSTextView, NSView;

@interface IDELicenseAgreementViewController : NSViewController
{
    DVTLicenseAgreementHelper *_licenseAgreementHelper;
    int _agreementStatus;
    NSAttributedString *_licenseAgreement;
    NSTextView *_licenseAgreementTextView;
    NSView *_foregroundContentView;
    BOOL _licenseOnly;
    NSTextField *_licenseSubtitle;
}

+ (void)initialize;
@property __weak NSTextField *licenseSubtitle; // @synthesize licenseSubtitle=_licenseSubtitle;
@property(retain) NSView *foregroundContentView; // @synthesize foregroundContentView=_foregroundContentView;
@property int agreementStatus; // @synthesize agreementStatus=_agreementStatus;
- (BOOL)_agreeToLicense;
- (void)agreeToLicense:(id)arg1;
- (void)disagreeWithLicense:(id)arg1;
- (void)_writeLicenseTextToURL:(id)arg1;
- (id)_licenseSavePanel;
- (void)save:(id)arg1;
- (BOOL)isGMLicense;
- (BOOL)shouldShowLicenseAgreement;
- (void)loadView;
- (id)initWithDefaultNib:(BOOL)arg1;

@end
