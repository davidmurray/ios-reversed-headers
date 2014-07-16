/*
 * CoreTelephony SIM support.
 *
 * Copyright (c) 2013-2014 Cykey (David Murray)
 * All rights reserved.
 */

#ifndef CTSIMSUPPORT_H_
#define CTSIMSUPPORT_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

#pragma mark - Definitions

    typedef CFStringRef CTSIMStatus;

    extern CTSIMStatus kCTSIMSupportSIMStatusBlacklisted;
    extern CTSIMStatus kCTSIMSupportSIMStatusChangeNotification;
    extern CTSIMStatus kCTSIMSupportSIMStatusCorporateLocked;
    extern CTSIMStatus kCTSIMSupportSIMStatusFixedDialingLocked;
    extern CTSIMStatus kCTSIMSupportSIMStatusMemoryFailure;
    extern CTSIMStatus kCTSIMSupportSIMStatusNetworkLocked;
    extern CTSIMStatus kCTSIMSupportSIMStatusNotInserted;
    extern CTSIMStatus kCTSIMSupportSIMStatusNotReady;
    extern CTSIMStatus kCTSIMSupportSIMStatusOperatorLocked;
    extern CTSIMStatus kCTSIMSupportSIMStatusOperatorSubsetLocked;
    extern CTSIMStatus kCTSIMSupportSIMStatusPINLocked;
    extern CTSIMStatus kCTSIMSupportSIMStatusPUKLocked;
    extern CTSIMStatus kCTSIMSupportSIMStatusReady;
    extern CTSIMStatus kCTSIMSupportSIMStatusServiceProviderLocked;

    /* For use with the CoreTelephony notification system. */
    extern CFStringRef kCTSIMSupportSIMStatusChangeNotification;

#pragma mark - API

    CTSIMStatus CTSIMSupportGetSIMStatus();

    CFStringRef CTSIMSupportCopyMobileSubscriberIdentity(CFAllocatorRef allocator);
    CFStringRef CTSIMSupportCopyMobileSubscriberCountryCode(CFAllocatorRef allocator);
    CFStringRef CTSIMSupportCopyMobileSubscriberNetworkCode(CFAllocatorRef allocator);

    int CTSIMSupportGetRemainingPINAttempts();
    int CTSIMSupportGetRemainingPUKAttempts();
    void CTSIMSupportPINUnlock(CFStringRef code);

#if __cplusplus
}
#endif

#endif /* CTSIMSUPPORT_H_ */
