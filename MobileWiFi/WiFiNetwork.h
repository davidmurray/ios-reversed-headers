/*
 * MobileWiFi network header.
 *
 * Copyright (c) 2013-2014 Cykey (David Murray)
 * All rights reserved.
 */

#ifndef WIFINETWORK_H_
#define WIFINETWORK_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

#pragma mark - Definitions

    /*
     * Opaque structure definitions.
     */

    typedef struct __WiFiNetwork *WiFiNetworkRef;

#pragma mark - API

    CFPropertyListRef WiFiNetworkGetProperty(WiFiNetworkRef network, CFStringRef property);

    int WiFiNetworkGetIntProperty(WiFiNetworkRef network, CFStringRef property);

    float WiFiNetworkGetFloatProperty(WiFiNetworkRef network, CFStringRef property);

    CFStringRef WiFiNetworkCopyPassword(WiFiNetworkRef);
    CFStringRef WiFiNetworkGetSSID(WiFiNetworkRef network);

    void WiFiNetworkSetPassword(WiFiNetworkRef network, CFStringRef password);

    float WiFiNetworkGetNetworkUsage(WiFiNetworkRef network);

    Boolean WiFiNetworkIsWEP(WiFiNetworkRef network);
    Boolean WiFiNetworkIsWPA(WiFiNetworkRef network);
    Boolean WiFiNetworkIsEAP(WiFiNetworkRef network);
    Boolean WiFiNetworkIsApplePersonalHotspot(WiFiNetworkRef network);
    Boolean WiFiNetworkIsAdHoc(WiFiNetworkRef network);
    Boolean WiFiNetworkIsHidden(WiFiNetworkRef network);
    Boolean WiFiNetworkRequiresPassword(WiFiNetworkRef network);
    Boolean WiFiNetworkRequiresUsername(WiFiNetworkRef network);

    /* This returns NULL a lot, not sure why. */
    CFDateRef WiFiNetworkGetLastAssociationDate(WiFiNetworkRef network);

    CFDictionaryRef WiFiNetworkCopyRecord(WiFiNetworkRef network);

#if __cplusplus
}
#endif

#endif /* WIFINETWORK_H_ */
