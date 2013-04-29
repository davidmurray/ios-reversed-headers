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

    // For use with the MRMediaRemoteGetNowPlayingInfo function.
    extern CFStringRef kMRMediaRemoteNowPlayingInfoArtworkData;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoAlbum;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoArtist;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoArtworkMIMEType;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoDiscNumber;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoDuration;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoElapsedTime;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoGenre;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoIsMusicApp;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoPlaybackRate;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoQueueIndex;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoRepeatMode;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoShuffleMode;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoStartTime;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTimestamp;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTitle;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTotalDiscCount;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTotalQueueCount;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTotalTrackCount;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoTrackNumber;
    extern CFStringRef kMRMediaRemoteNowPlayingInfoUniqueIdentifier;

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

    typedef void (^MRMediaRemoteGetNowPlayingInfoCompletion)(CFDictionaryRef information);
    extern "C" void MRMediaRemoteGetNowPlayingInfo(dispatch_queue_t queue, MRMediaRemoteGetNowPlayingInfoCompletion completion);


#ifdef __cplusplus
}
#endif

#endif