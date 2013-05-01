// Header for CTCall
// CTCall is part of CoreTelephony.framework.
// Copyright (C) 2013 Cykey (David Murray) cykey@live.com
// All rights reserved.

#ifndef _CTCALL_H_
#define _CTCALL_H_

#ifdef __cplusplus
extern "C" {
#endif
    #include <CoreFoundation/CoreFoundation.h>

    typedef struct __CTCall/* {
            int unknown_0;
            int unknown_1;
            OSSpinLock *lock; // 0x8
            int status; // 0x24

    }*/ *CTCallRef;

    CFArrayRef CTCopyCurrentCalls(CFAllocatorRef allocator);

    CFStringRef CTCallCopyAddress(CFAllocatorRef allocator, CTCallRef call);
    CFStringRef CTCallCopyName(CFAllocatorRef allocator, CTCallRef call);

    double CTCallGetDuration(CTCallRef call);
    double CTCallGetStartTime(CTCallRef call);

    int CTCallGetStatus(CTCallRef call);

    void CTCallHold(CTCallRef call);
    void CTCallResume(CTCallRef call);
    void CTCallDisconnect(CTCallRef call);

    // XXX: This needs to be looked into some more.
    // CALL STATUSES:
    // 1 means the incoming call has been answered.
    // 2 possibly means that the call was dropped or interrupted? Not sure.
    // 3 means an outgoing call has been initiated.
    // 4 means there's an incoming call.
    // 5 means the incoming call has ended.

    // From TelephonyUI.framework:
    CTCallRef TPGetDisplayedCallFromCalls(int unknown /* use 0 */);

#ifdef __cplusplus
}
#endif

#endif