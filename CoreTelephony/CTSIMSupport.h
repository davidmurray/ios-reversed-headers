/*
 * CoreTelephony SIM support.
 */

#ifndef _CTSIMSupport_H_
#define _CTSIMSupport_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

#pragma mark - API

typedef CFStringRef CTSIMStatus;

CTSIMStatus kCTSIMSupportSIMStatusBlacklisted;
CTSIMStatus kCTSIMSupportSIMStatusChangeNotification;
CTSIMStatus kCTSIMSupportSIMStatusCorporateLocked;
CTSIMStatus kCTSIMSupportSIMStatusFixedDialingLocked;
CTSIMStatus kCTSIMSupportSIMStatusMemoryFailure;
CTSIMStatus kCTSIMSupportSIMStatusNetworkLocked;
CTSIMStatus kCTSIMSupportSIMStatusNotInserted;
CTSIMStatus kCTSIMSupportSIMStatusNotReady;
CTSIMStatus kCTSIMSupportSIMStatusOperatorLocked;
CTSIMStatus kCTSIMSupportSIMStatusOperatorSubsetLocked;
CTSIMStatus kCTSIMSupportSIMStatusPINLocked;
CTSIMStatus kCTSIMSupportSIMStatusPUKLocked;
CTSIMStatus kCTSIMSupportSIMStatusReady;
CTSIMStatus kCTSIMSupportSIMStatusServiceProviderLocked;

CTSIMStatus CTSIMSupportGetSIMStatus();

CFStringRef CTSIMSupportCopyMobileSubscriberIdentity(CFAllocatorRef allocator);
CFStringRef CTSIMSupportCopyMobileSubscriberCountryCode(CFAllocatorRef allocator);
CFStringRef CTSIMSupportCopyMobileSubscriberNetworkCode(CFAllocatorRef allocator);

/* For use with the CoreTelephony notification system. */
CFStringRef kCTSIMSupportSIMStatusChangeNotification;

__END_DECLS

#endif /* _CTSIMSupport_H_ */
