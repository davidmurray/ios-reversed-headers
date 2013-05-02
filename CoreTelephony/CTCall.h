/*
 * CoreTelephony calling support.
 */

#ifndef _CTCall_H_
#define _CTCall_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

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
} kCTCallStatus;

#pragma mark - API

CFArrayRef CTCopyCurrentCalls(CFAllocatorRef allocator);

CFStringRef CTCallCopyAddress(CFAllocatorRef allocator, CTCallRef call);
CFStringRef CTCallCopyAddress(CFAllocatorRef allocator, CTCallRef call);

double CTCallGetDuration(CTCallRef call);
double CTCallGetStartTime(CTCallRef call);

kCTCallStatus CTCallGetStatus(CTCallRef call);

void CTCallHold(CTCallRef call);
void CTCallResume(CTCallRef call);
void CTCallDisconnect(CTCallRef call);

__END_DECLS

#endif /* _CTCall_H_ */
