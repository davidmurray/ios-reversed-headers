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
    kMRPause,
    kMRTogglePlayPause,
    kMRStop,
    kMRNextTrack,
    kMRPreviousTrack,
    kMRToggleShuffle,
    kMRToggleRepeat,
    kMRStartSeek,
    kMREndSeek,
    kMRStartHyperSeek,      /* These are for 15 second durations. */
    kMREndHyperSeek,
    kMRGoBack,
    kMRSkip,
} kMRCommand;

/*
 * Use 0 for __reserved.
 */
Boolean MRMediaRemoteSendCommand(kMRCommand command, uint32_t __reserved);

void MRMediaRemoteBeginRouteDiscovery(void);
void MRMediaRemoteEndRouteDiscovery(void);

CFArrayRef MRMediaRemoteCopyPickableRoutes();

typedef void (^MRMediaRemoteGetNowPlayingInfoCompletion)(CFDictionaryRef information);
typedef void (^MRMediaRemoteGetNowPlayingApplicationPIDCompletion)(int PID);

void MRMediaRemoteGetNowPlayingApplicationPID(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingApplicationPIDCompletion completion);
void MRMediaRemoteGetNowPlayingInfo(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingInfoCompletion completion);

__END_DECLS

#endif /* _MediaRemote_H_ */
