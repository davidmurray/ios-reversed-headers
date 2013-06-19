/*
 * MobileWiFi network header.
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

    CFDateRef WiFiNetworkGetLastAssociationDate(WiFiNetworkRef network);

    CFDictionaryRef WiFiNetworkCopyRecord(WiFiNetworkRef network);

#if __cplusplus
}
#endif

#endif /* WIFINETWORK_H_ */
