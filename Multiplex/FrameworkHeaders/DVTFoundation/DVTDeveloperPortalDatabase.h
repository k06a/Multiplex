//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "CDStructures.h"

@interface DVTDeveloperPortalDatabase : NSObject
{
}

+ (id)createProvisioningProfileOperationForToken:(id)arg1 withName:(id)arg2 appID:(id)arg3 devices:(id)arg4 certificates:(id)arg5 platform:(id)arg6 andTeam:(id)arg7;
+ (id)renewProvisioningProfileOperationForToken:(id)arg1 andProvisioningProfile:(id)arg2;
+ (void)renewProvisioningProfile:(id)arg1 withCallback:(dispatch_block_t)arg2;
+ (void)createProvisioningProfileNamed:(id)arg1 withAppID:(id)arg2 devices:(id)arg3 certificates:(id)arg4 andPlatform:(id)arg5 toTeam:(id)arg6 withCallback:(dispatch_block_t)arg7;
+ (id)fetchDistributionProfileOperationForToken:(id)arg1 andPlatform:(id)arg2 andSubPlatform:(id)arg3 forBundleIdentifier:(id)arg4 withFeatures:(id)arg5 includeDevices:(BOOL)arg6;
+ (id)fetchTeamDistributionProfileOperationForToken:(id)arg1 andPlatform:(id)arg2 andSubPlatform:(id)arg3 forBundleIdentifier:(id)arg4 withFeatures:(id)arg5;
+ (id)fetchTeamProfileOperationForToken:(id)arg1 andPlatform:(id)arg2 andSubPlatform:(id)arg3 forBundleIdentifier:(id)arg4 withFeatures:(id)arg5;
+ (id)_fetchTeamDistributionProfileOperationForSingleTeamToken:(id)arg1 andPlatform:(id)arg2 andSubPlatform:(id)arg3 forBundleIdentifier:(id)arg4 withFeatures:(id)arg5 includeDevices:(BOOL)arg6;
+ (id)_fetchTeamProfileOperationForSingleTeamToken:(id)arg1 andPlatform:(id)arg2 andSubPlatform:(id)arg3 forBundleIdentifier:(id)arg4 withFeatures:(id)arg5;
+ (id)_fetchOrCreateAppIDForSingleTeamToken:(id)arg1 andPlatform:(id)arg2 forBundleIdentifier:(id)arg3 withFeatures:(id)arg4;
+ (id)fetchOrCreateAppIDOperationForSingleTeamToken:(id)arg1 andPlatform:(id)arg2 forBundleIdentifier:(id)arg3 withFeatures:(id)arg4;
+ (id)_updateAppIdId:(id)arg1 appIdName:(id)arg2 token:(id)arg3 andPlatform:(id)arg4 withFeatures:(id)arg5;
+ (id)_updatePortalIdentifiers:(id)arg1 appIdId:(id)arg2 token:(id)arg3 andPlatform:(id)arg4 listTeamItemsOpClass:(Class)arg5 teamItemsKeyPath:(id)arg6 itemIdentifierKeyPath:(id)arg7 itemPortalIdentifierKeyPath:(id)arg8 addTeamItemsOpClass:(Class)arg9 addAppItemsOpClass:(Class)arg10;
+ (id)addDeviceOperationForToken:(id)arg1 withUUID:(id)arg2 name:(id)arg3 portalDeviceClass:(id)arg4 andPlatform:(id)arg5;
+ (id)downloadProfilesOperationForToken:(id)arg1;
+ (id)downloadCertificatesOperationForToken:(id)arg1 developmentCertificatesOnly:(BOOL)arg2 restrictToPlatform:(id)arg3;
+ (id)lightweightSyncOperationForToken:(id)arg1;
+ (id)developersAndTeamsSyncOperation;
+ (void)_refreshFromToken:(id)arg1 andTeamListResponse:(id)arg2;
+ (void)_refreshFromToken:(id)arg1 andServiceResponses:(id)arg2 logAspect:(id)arg3;
+ (void)_purgeOrphanedEntitiesInContext:(id)arg1 withLogAspect:(id)arg2;
+ (_Bool)_purgeOrphanedEntitiesOfType:(id)arg1 inContext:(id)arg2 withLogAspect:(id)arg3;
+ (void)_refreshFromServiceResponse:(id)arg1 logAspect:(id)arg2;
+ (id)certificateFromPortalResponse:(id)arg1 updateIfFound:(_Bool)arg2 logAspect:(id)arg3;
+ (id)certificatesFromPortalResponses:(id)arg1 updateIfFound:(_Bool)arg2 logAspect:(id)arg3;
+ (id)certificatesInContext:(id)arg1;
+ (id)certificateMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)certificatesMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)provisioningProfileForDTDKProvisioningProfile:(id)arg1 inContext:(id)arg2;
+ (id)provisioningProfileForDVTProvisioningProfile:(id)arg1 inContext:(id)arg2;
+ (id)teamNameForProfile:(id)arg1 inContext:(id)arg2;
+ (id)teamForProfile:(id)arg1 inContext:(id)arg2;
+ (id)provisioningProfileFromPortalResponse:(id)arg1 logAspect:(id)arg2;
+ (id)provisioningProfilesFromPortalResponses:(id)arg1 logAspect:(id)arg2;
+ (id)provisioningProfileForUUID:(id)arg1 inContext:(id)arg2;
+ (id)provisioningProfileForPortalId:(id)arg1 inContext:(id)arg2;
+ (id)provisioningProfilesInContext:(id)arg1;
+ (id)provisioningProfileMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)provisioningProfilesMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)deviceFromPortalResponse:(id)arg1 updateIfFound:(_Bool)arg2;
+ (id)devicesFromPortalResponses:(id)arg1 updateIfFound:(_Bool)arg2;
+ (id)deviceForPortalId:(id)arg1 inContext:(id)arg2;
+ (id)devicesForUUID:(id)arg1 inContext:(id)arg2;
+ (id)devicesInContext:(id)arg1;
+ (id)deviceMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)devicesMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)omcIdentifierFromPortalResponse:(id)arg1;
+ (id)omcIdentifiersFromPortalResponses:(id)arg1;
+ (id)omcIdentifierForPortalId:(id)arg1 inContext:(id)arg2;
+ (id)omcIdentifierMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)omcIdentifiersMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)applicationGroupFromPortalResponse:(id)arg1;
+ (id)applicationGroupsFromPortalResponses:(id)arg1;
+ (id)applicationGroupForPortalId:(id)arg1 inContext:(id)arg2;
+ (id)applicationGroupsInContext:(id)arg1;
+ (id)applicationGroupMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)applicationGroupsMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)cloudContainerFromPortalResponse:(id)arg1;
+ (id)cloudContainersFromPortalResponses:(id)arg1;
+ (id)cloudContainerForPortalId:(id)arg1 inContext:(id)arg2;
+ (id)cloudContainersInContext:(id)arg1;
+ (id)cloudContainerMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)cloudContainersMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)shoeboxIDFromPortalResponse:(id)arg1;
+ (id)shoeboxIDsFromPortalResponses:(id)arg1;
+ (id)shoeboxIDForPortalId:(id)arg1 inContext:(id)arg2;
+ (id)shoeboxIDsInContext:(id)arg1;
+ (id)shoeboxIDMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)shoeboxIDsMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)wildcardAppIDForTeam:(id)arg1 andPlatform:(id)arg2;
+ (id)appIdsForTeam:(id)arg1 andPlatform:(id)arg2 forBundleIdentifier:(id)arg3 withFeatures:(id)arg4;
+ (id)appIdsForTeam:(id)arg1 andPlatform:(id)arg2 forBundleIdentifier:(id)arg3 allowWildcards:(_Bool)arg4;
+ (id)appIdsForTeam:(id)arg1 andPlatform:(id)arg2 forBundleIdentifier:(id)arg3;
+ (id)appIDFromPortalResponse:(id)arg1;
+ (id)appIDsFromPortalResponses:(id)arg1;
+ (id)appIDForPortalId:(id)arg1 inContext:(id)arg2;
+ (id)appIDsInContext:(id)arg1;
+ (id)appIDMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)appIDsMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)roleForTeam:(id)arg1 developer:(id)arg2 role:(id)arg3;
+ (id)roleMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (void)refreshAllTeamsFromPortal;
+ (id)_listTeamsOperationForToken:(id)arg1;
+ (id)teamNameForID:(id)arg1 inContext:(id)arg2;
+ (id)teamFromPortalResponse:(id)arg1;
+ (id)teamForPortalId:(id)arg1 inContext:(id)arg2;
+ (id)teamsInContext:(id)arg1;
+ (id)teamMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)teamsMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)developerFromPortalResponse:(id)arg1;
+ (id)developerForPortalId:(id)arg1 inContext:(id)arg2;
+ (id)developerForPersonId:(id)arg1 inContext:(id)arg2;
+ (id)developerForAccount:(id)arg1 inContext:(id)arg2;
+ (id)developersInContext:(id)arg1;
+ (id)developerMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)developersMatchingPredicate:(id)arg1 inContext:(id)arg2;
+ (id)objectWithEntityName:(id)arg1 matchingPredicate:(id)arg2 inContext:(id)arg3;
+ (id)objectsWithEntityName:(id)arg1 matchingPredicate:(id)arg2 inContext:(id)arg3;
+ (id)conditionalMoc;
+ (id)temporaryMoc;
+ (id)mainThreadMoc;
+ (id)moc;
+ (id)mocWithLogAspect:(id)arg1;

@end

