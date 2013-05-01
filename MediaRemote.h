// Header for MediaRemote.dylib
// 2013 (C) Cykey cykey@live.com
// All rights reserved.

#ifndef _MEDIAREMOTE_H_
#define _MEDIAREMOTE_H_

#include <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C" {
#endif
    // For use on the CFNotificationCenterGetLocalCenter notification center.
    CFStringRef kMRMediaRemoteNowPlayingInfoDidChangeNotification;
    CFStringRef kMRMediaRemoteNowPlayingPlaybackQueueDidChangeNotification;
    CFStringRef kMRMediaRemotePickableRoutesDidChangeNotification;
    CFStringRef kMRMediaRemoteNowPlayingApplicationDidChangeNotification;
    CFStringRef kMRMediaRemoteNowPlayingApplicationIsPlayingDidChangeNotification;
    CFStringRef kMRMediaRemoteRouteStatusDidChangeNotification;

    CFStringRef kMRMediaRemoteNowPlayingApplicationIsPlayingUserInfoKey;
    CFStringRef kMRMediaRemoteNowPlayingApplicationPIDUserInfoKey;
    CFStringRef kMRMediaRemoteNowPlayingInfoAlbum;
    CFStringRef kMRMediaRemoteNowPlayingInfoArtist;
    CFStringRef kMRMediaRemoteNowPlayingInfoArtworkData;
    CFStringRef kMRMediaRemoteNowPlayingInfoArtworkMIMEType;
    CFStringRef kMRMediaRemoteNowPlayingInfoChapterNumber;
    CFStringRef kMRMediaRemoteNowPlayingInfoComposer;
    CFStringRef kMRMediaRemoteNowPlayingInfoDiscNumber;
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

    Boolean MRMediaRemoteSendCommand(unsigned int command, int unknown0 /* use 0 */);

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

    void MRMediaRemoteBeginRouteDiscovery();
    CFArrayRef MRMediaRemoteCopyPickableRoutes();
    void MRMediaRemoteEndRouteDiscovery();

    typedef void (^MRMediaRemoteGetNowPlayingInfoCompletion)(CFDictionaryRef information);
    void MRMediaRemoteGetNowPlayingInfo(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingInfoCompletion completion);

    typedef void (^MRMediaRemoteGetNowPlayingApplicationPIDCompletion)(int PID);
    void MRMediaRemoteGetNowPlayingApplicationPID(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingApplicationPIDCompletion completion);

#ifdef __cplusplus
}
#endif

#endif