// Header for MediaRemote.dylib
// 2013 (C) Cykey cykey@live.com
// All rights reserved.

#ifndef MEDIAREMOTE_H
#define MEDIAREMOTE_H

#include <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C" {
#endif
    // For use on the CFNotificationCenterGetLocalCenter notification center.
    extern CFStringRef kMRMediaRemoteNowPlayingInfoDidChangeNotification;
    extern CFStringRef kMRMediaRemoteNowPlayingPlaybackQueueDidChangeNotification;
    extern CFStringRef kMRMediaRemotePickableRoutesDidChangeNotification;
    extern CFStringRef kMRMediaRemoteNowPlayingApplicationDidChangeNotification;
    extern CFStringRef kMRMediaRemoteNowPlayingApplicationIsPlayingDidChangeNotification;
    extern CFStringRef kMRMediaRemoteRouteStatusDidChangeNotification;

    extern CFStringRef kMRMediaRemoteNowPlayingApplicationIsPlayingUserInfoKey;
    extern CFStringRef kMRMediaRemoteNowPlayingApplicationPIDUserInfoKey;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoAlbum;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoArtist;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoArtworkData;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoArtworkMIMEType;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoChapterNumber;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoComposer;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoDiscNumber;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoDuration;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoElapsedTime;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoGenre;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoIsAdvertisement;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoIsBanned;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoIsInWishList;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoIsLiked;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoIsMusicApp;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoPlaybackRate;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoProhibitsSkip;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoQueueIndex;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoRadioStationIdentifier;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoRepeatMode;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoShuffleMode;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoStartTime;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoSupportsFastForward15Seconds;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoSupportsIsBanned;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoSupportsIsLiked;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoSupportsRewind15Seconds;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTimestamp;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTitle;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTotalChapterCount;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTotalDiscCount;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTotalQueueCount;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTotalTrackCount;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTrackNumber;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoUniqueIdentifier;
    extern CFStringRef kMRMediaRemoteOptionMediaType;
    extern CFStringRef kMRMediaRemoteOptionSourceID;
    extern CFStringRef kMRMediaRemoteOptionTrackID;
    extern CFStringRef kMRMediaRemoteRouteDescriptionUserInfoKey;
    extern CFStringRef kMRMediaRemoteRouteStatusUserInfoKey;

    extern Boolean MRMediaRemoteSendCommand(unsigned int command, int unknown0 /* use 0 */);

    // 0 is play.
    // 1 is pause.
    // 2 is toggle play/pause.
    // 3 is stop.
    // 4 is go to next track.
    // 5 is go to previous track.
    // 6 is toggle shuffle mode.
    // 7 is toggle repeat mode.
    // 8 is start seeking.
    // 9 is stop seeking.
    // 10 is start seeking on hyper mode (15 seconds).
    // 11 is stop seeking on hyper mode (15 seconds).
    // 12 is go back for 15 seconds.
    // 13 is skip fifteen seconds.

    extern void MRMediaRemoteBeginRouteDiscovery();
    extern CFArrayRef MRMediaRemoteCopyPickableRoutes();
    extern void MRMediaRemoteEndRouteDiscovery();

    typedef void (^MRMediaRemoteGetNowPlayingInfoCompletion)(CFDictionaryRef information);
    extern void MRMediaRemoteGetNowPlayingInfo(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingInfoCompletion completion);

    typedef void (^MRMediaRemoteGetNowPlayingApplicationPIDCompletion)(int PID);
    extern void MRMediaRemoteGetNowPlayingApplicationPID(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingApplicationPIDCompletion completion);

#ifdef __cplusplus
}
#endif

#endif