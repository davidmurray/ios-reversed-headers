/*
 * CoreTelephony calling support.
 *
 * Copyright (c) 2013, Cykey (David Murray)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CTCALL_H_
#define CTCALL_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

#pragma mark - Definitions

    /*
     * Opaque structure definition.
     */

    typedef struct __CTCall *CTCallRef;

    typedef enum {
        kCTCallStatusUnknown = 0,
        kCTCallStatusAnswered,
        kCTCallStatusDroppedInterrupted,
        kCTCallStatusOutgoingInitiated,
        kCTCallStatusIncomingCall,
        kCTCallStatusIncomingCallEnded
    } CTCallStatus;

    typedef CFStringRef CTCallType;

    extern CTCallType kCTCallTypeNormal;
    extern CTCallType kCTCallTypeVOIP;
    extern CTCallType kCTCallTypeVideoConference;
    extern CTCallType kCTCallTypeVoicemail;

    /* For use with the CoreTelephony notification system. */

    extern CFStringRef kCTCallStatusChangeNotification;
    extern CFStringRef kCTCallIdentificationChangeNotification;

#pragma mark - API

    CFArrayRef CTCopyCurrentCalls(CFAllocatorRef allocator);

    /* The 'types' argument is an array of CTCallTypes. */
    CFArrayRef CTCopyCurrentCallsWithTypes(CFAllocatorRef allocator, CFArrayRef types);

    int CTGetCurrentCallCount();

    CFStringRef CTCallCopyAddress(CFAllocatorRef allocator, CTCallRef call);
    CFStringRef CTCallCopyName(CFAllocatorRef allocator, CTCallRef call);
    CFStringRef CTCallCopyCountryCode(CFAllocatorRef allocator, CTCallRef call);
    CFStringRef CTCallCopyNetworkCode(CFAllocatorRef allocator, CTCallRef call);

    CFStringRef CTCallCopyUniqueStringID(CFAllocatorRef allocator, CTCallRef call);

    double CTCallGetDuration(CTCallRef call);
    double CTCallGetStartTime(CTCallRef call);

    CTCallStatus CTCallGetStatus(CTCallRef call);
    CTCallType CTCallGetCallType(CTCallRef call);

    /* Pass NULL to delete all calls. */
    void CTCallDeleteAllCallsBeforeDate(CFDateRef date);
    void CTCallHistoryInvalidateCaches();

    void CTCallTimersReset();

    void CTCallAnswer(CTCallRef call);
    void CTCallHold(CTCallRef call);
    void CTCallResume(CTCallRef call);
    void CTCallDisconnect(CTCallRef call);

    void CTCallListDisconnectAll();

    Boolean CTCallIsConferenced(CTCallRef call);
    Boolean CTCallIsAlerting(CTCallRef call);
    Boolean CTCallIsToVoicemail(CTCallRef call);
    Boolean CTCallIsOutgoing(CTCallRef call);

    void CTCallJoinConference(CTCallRef call);
    void CTCallLeaveConference(CTCallRef call);

    /*
     * The phone number passed in the dial functions must be normalized.
     * E.g. +1 (555) 555-5555 would become 15555555555.
     * One can use CPPhoneNumberCopyNormalized from AppSupport.framework to normalize phone numbers.
     */

    CTCallRef CTCallDial(CFStringRef number);
    CTCallRef CTCallDialEmergency(CFStringRef number);

#if __cplusplus
}
#endif

#endif /* CTCALL_H_ */
