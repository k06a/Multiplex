//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

#import "DVTDownloadableInstallationHelper-Protocol.h"

@class NSString;

@interface IDEDownloadableInstallationHelper : NSObject <DVTDownloadableInstallationHelper>
{
}

- (void)downloadableNamed:(id)arg1 needsTerminationOfAppsWithBundleIdentifier:(id)arg2 completionBlock:(dispatch_block_t)arg3;
- (void)_didCompleteAlertWithReturnCode:(long long)arg1 bundleIdentifier:(id)arg2 completionBlock:(dispatch_block_t)arg3;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

