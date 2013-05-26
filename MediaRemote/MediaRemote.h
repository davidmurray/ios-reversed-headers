/*
 * Media remote framework header.
 */

#ifndef _MediaRemote_H_
#define _MediaRemote_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

#pragma mark - CFNotificationCenter Things

/*
 * These are used on the local notification center.
 */

CFStringRef kMRMediaRemoteNowPlayingInfoDidChangeNotification;
CFStringRef kMRMediaRemoteNowPlayingPlaybackQueueDidChangeNotification;
CFStringRef kMRMediaRemotePickableRoutesDidChangeNotification;
CFStringRef kMRMediaRemoteNowPlayingApplicationDidChangeNotification;
CFStringRef kMRMediaRemoteNowPlayingApplicationIsPlayingDidChangeNotification;
CFStringRef kMRMediaRemoteRouteStatusDidChangeNotification;

#pragma mark - Keys

CFStringRef kMRMediaRemoteNowPlayingApplicationPIDUserInfoKey;
CFStringRef kMRMediaRemoteNowPlayingApplicationIsPlayingUserInfoKey;
CFStringRef kMRMediaRemoteNowPlayingInfoAlbum;
CFStringRef kMRMediaRemoteNowPlayingInfoArtist;
CFStringRef kMRMediaRemoteNowPlayingInfoArtworkData;
CFStringRef kMRMediaRemoteNowPlayingInfoArtworkMIMEType;
CFStringRef kMRMediaRemoteNowPlayingInfoChapterNumber;
CFStringRef kMRMediaRemoteNowPlayingInfoComposer;
CFStringRef kMRMediaRemoteNowPlayingInfoDuration;
CFStringRef kMRMediaRemoteNowPlayingInfoElapsedTime;
CFStringRef kMRMediaRemoteNowPlayingInfoGenre;
CFStringRef kMRMediaRemoteNowPlayingInfoIsAdvertisement;
CFStringRef kMRMediaRemoteNowPlayingInfoIsBanned;
CFStringRef kMRMediaRemoteNowPlayingInfoIsInWishList;
CFStringRef kMRMediaRemoteNowPlayingInfoIsLiked;
CFStringRef kMRMediaRemoteNowPlayingInfoIsMusicApp;
CFStringRef kMRMediaRemoteNowPlayingInfoPlaybackRate;
CFStringRef kMRMediaRemoteNowPlayingInfoProhibitsSkip;
CFStringRef kMRMediaRemoteNowPlayingInfoQueueIndex;
CFStringRef kMRMediaRemoteNowPlayingInfoRadioStationIdentifier;
CFStringRef kMRMediaRemoteNowPlayingInfoRepeatMode;
CFStringRef kMRMediaRemoteNowPlayingInfoShuffleMode;
CFStringRef kMRMediaRemoteNowPlayingInfoStartTime;
CFStringRef kMRMediaRemoteNowPlayingInfoSupportsFastForward15Seconds;
CFStringRef kMRMediaRemoteNowPlayingInfoSupportsIsBanned;
CFStringRef kMRMediaRemoteNowPlayingInfoSupportsIsLiked;
CFStringRef kMRMediaRemoteNowPlayingInfoSupportsRewind15Seconds;
CFStringRef kMRMediaRemoteNowPlayingInfoTimestamp;
CFStringRef kMRMediaRemoteNowPlayingInfoTitle;
CFStringRef kMRMediaRemoteNowPlayingInfoTotalChapterCount;
CFStringRef kMRMediaRemoteNowPlayingInfoTotalDiscCount;
CFStringRef kMRMediaRemoteNowPlayingInfoTotalQueueCount;
CFStringRef kMRMediaRemoteNowPlayingInfoTotalTrackCount;
CFStringRef kMRMediaRemoteNowPlayingInfoTrackNumber;
CFStringRef kMRMediaRemoteNowPlayingInfoUniqueIdentifier;
CFStringRef kMRMediaRemoteOptionMediaType;
CFStringRef kMRMediaRemoteOptionSourceID;
CFStringRef kMRMediaRemoteOptionTrackID;
CFStringRef kMRMediaRemoteRouteDescriptionUserInfoKey;
CFStringRef kMRMediaRemoteRouteStatusUserInfoKey;

#pragma mark - API

typedef enum {
    kMRPlay = 0,
    kMRPause = 1,
    kMRTogglePlayPause = 2,
    kMRStop = 3,
    kMRNextTrack = 4,
    kMRPreviousTrack = 5,
    kMRToggleShuffle = 6,
    kMRToggleRepeat = 7,
    kMRStartForwardSeek = 8,
    kMREndForwardSeek = 9,
    kMRStartBackwardSeek = 10,
    kMREndBackwardSeek = 11,
    kMRGoBackFifteenSeconds = 12,
    kMRSkipFifteenSeconds = 13,
} kMRCommand;

/*
 * Use 0 for __reserved.
 */
Boolean MRMediaRemoteSendCommand(kMRCommand command, uint32_t __reserved);

void MRMediaRemoteSetPlaybackSpeed(int speed);
void MRMediaRemoteSetElapsedTime(double elapsedTime);

void MRMediaRemoteSetNowPlayingApplicationOverrideEnabled(Boolean enabled);

void MRMediaRemoteRegisterForNowPlayingNotifications(dispatch_queue_t queue);
void MRMediaRemoteUnregisterForNowPlayingNotifications();

void MRMediaRemoteBeginRouteDiscovery(void);
void MRMediaRemoteEndRouteDiscovery(void);

CFArrayRef MRMediaRemoteCopyPickableRoutes();

typedef void (^MRMediaRemoteGetNowPlayingInfoCompletion)(CFDictionaryRef information);
typedef void (^MRMediaRemoteGetNowPlayingApplicationPIDCompletion)(int PID);
typedef void (^MRMediaRemoteGetNowPlayingApplicationIsPlayingCompletion)(Boolean isPlaying);

void MRMediaRemoteGetNowPlayingApplicationPID(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingApplicationPIDCompletion completion);
void MRMediaRemoteGetNowPlayingInfo(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingInfoCompletion completion);
void MRMediaRemoteGetNowPlayingApplicationIsPlaying(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingApplicationIsPlayingCompletion completion);

__END_DECLS

#endif /* _MediaRemote_H_ */
