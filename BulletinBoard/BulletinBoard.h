/*
 * BulletinBoard framework header.
 * Copyright (c) 2015 Qusic (Bang Lee)
 */

// From iOS 8.2 SDK

#import <CoreFoundation/CoreFoundation.h>

@class BBDataProvider, BBBulletinRequest;

#if __cplusplus
extern "C" {
#endif

// Publish notifications
void _BBDataProviderAddBulletinForDestinations(BBDataProvider *dataProvider, BBBulletinRequest *bulletin, NSUInteger destinations, BOOL addToLockScreen);
void BBDataProviderAddBulletinForDestinations(BBDataProvider *dataProvider, BBBulletinRequest *bulletin, NSUInteger destinations); // _BBDataProviderAddBulletinForDestinations: addToLockScreen = NO
void BBDataProviderAddBulletin(BBDataProvider *dataProvider, BBBulletinRequest *bulletin, BOOL allDestinations); // _BBDataProviderAddBulletinForDestinations: destinations = allDestinations ? 0xe : 0x2, addToLockScreen = NO
void BBDataProviderAddBulletinToLockScreen(BBDataProvider *dataProvider, BBBulletinRequest *bulletin); // _BBDataProviderAddBulletinForDestinations: destinations = 0x4, addToLockScreen = YES
void BBDataProviderModifyBulletin(BBDataProvider *dataProvider, BBBulletinRequest *bulletin); // _BBDataProviderAddBulletinForDestinations: destinations = 0x0, addToLockScreen = NO

// Clear notifications
void BBDataProviderWithdrawBulletinWithPublisherBulletinID(BBDataProvider *dataProvider, NSString *publisherBulletinID);
void BBDataProviderWithdrawBulletinsWithRecordID(BBDataProvider *dataProvider, NSString *recordID);

// Refresh notifications
void BBDataProviderInvalidateBulletinsForDestinations(BBDataProvider *dataProvider, NSUInteger destinations);
void BBDataProviderInvalidateBulletins(BBDataProvider *dataProvider); // BBDataProviderInvalidateBulletinsForDestinations: destinations = 0x32
void BBDataProviderReloadDefaultSectionInfo(BBDataProvider *dataProvider);

// App badges
void BBDataProviderSetApplicationBadge(BBDataProvider *dataProvider, NSInteger value);
void BBDataProviderSetApplicationBadgeString(BBDataProvider *dataProvider, NSString *value);

#if __cplusplus
}
#endif

@interface BBServer : NSObject
- (BBDataProvider *)dataProviderForSectionID:(NSString *)sectionID;
- (NSSet *)allBulletinIDsForSectionID:(NSString *)sectionID;
- (NSSet *)bulletinIDsForSectionID:(NSString *)sectionID inFeed:(NSUInteger)feed;
- (NSSet *)bulletinsRequestsForBulletinIDs:(NSSet *)bulletinIDs;
- (NSSet *)bulletinsForPublisherBulletinIDs:(NSSet *)publisherBulletinIDs sectionID:(NSString *)sectionID;
@end

