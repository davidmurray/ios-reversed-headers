/*
 * MobileWiFi device client header.
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

#ifndef WIFIDEVICECLIENT_H_
#define WIFIDEVICECLIENT_H_

#include <CoreFoundation/CoreFoundation.h>
#include "WiFiNetwork.h"

#if __cplusplus
extern "C" {
#endif

#pragma mark - Definitions

    /*
     * Opaque structure definition.
     */

    typedef struct __WiFiDeviceClient *WiFiDeviceClientRef;

    /* Callback typedefs. */
    typedef void (*WiFiDeviceClientCallback)(WiFiDeviceClientRef device, CFDictionaryRef data, const void *object);
    typedef void (*WiFiDeviceClientLinkCallback)(WiFiDeviceClientRef device, const void *object);
    typedef void (*WiFiDeviceScanCallback)(WiFiDeviceClientRef device, CFArrayRef results, int error, const void *object);
    typedef void (*WiFiDeviceAssociateCallback)(WiFiDeviceClientRef device, WiFiNetworkRef network, CFDictionaryRef dict, int error, const void *object);

#pragma mark - API

    CFPropertyListRef WiFiDeviceClientCopyProperty(WiFiDeviceClientRef client, CFStringRef property);

    WiFiNetworkRef WiFiDeviceClientCopyCurrentNetwork(WiFiDeviceClientRef client);

    int WiFiDeviceClientGetPower(WiFiDeviceClientRef client);
    void WiFiDeviceClientSetPower(WiFiDeviceClientRef client, int power);

    /*
     * The following keys in the dict parameter are understood by wifid:
     * "SCAN_CHANNELS": An array of dictionaries containing the 'CHANNEL' and 'CHANNEL_FLAGS' keys.
     * "SCAN_MAXAGE": Unknown. Use 2.
     * "SCAN_MERGE": Unknown. Use 1.
     * "SCAN_NUM_SCANS": Number of scans to perform.
     * "SCAN_PHY_MODE": Has something to do with PHY.
     * "SCAN_RSSI_THRESHOLD": The RSSI theshold level. Apple uses -80, meaning that networks that have a signal strength lower than -80 will be ignored.
     * "SCAN_TYPE": Unknown. Use 1.
     */
    int WiFiDeviceClientScanAsync(WiFiDeviceClientRef device, CFDictionaryRef dict, WiFiDeviceScanCallback callback, const void *object);

    /*
     * Used to connect to a network. Example usage:
     *    (Get a WiFiNetworkRef instance from the scan results or something.)
     *    WiFiNetworkSetPassword(network, CFSTR("Password1"));
     *    WiFiDeviceClientAssociateAsync(client, network, MyCallbackFunction, NULL);
     */
    int WiFiDeviceClientAssociateAsync(WiFiDeviceClientRef client, WiFiNetworkRef network, WiFiDeviceAssociateCallback callback, CFDictionaryRef dict);
    void WiFiDeviceClientAssociateCancel(WiFiDeviceClientRef client);
    void WiFiDeviceClientDisassociate(WiFiDeviceClientRef client);

    CFStringRef WiFiDeviceClientGetInterfaceName(WiFiDeviceClientRef client);

    /* I think LQM stands for 'Link Quality Monitoring', also known as signal strength. */
    void WiFiDeviceClientRegisterLQMCallback(WiFiDeviceClientRef device, WiFiDeviceClientCallback callback, const void *object);
    void WiFiDeviceClientRegisterExtendedLinkCallback(WiFiDeviceClientRef device, WiFiDeviceClientCallback callback, const void *object);
    void WiFiDeviceClientRegisterLinkCallback(WiFiDeviceClientRef device, WiFiDeviceClientLinkCallback callback, const void *object);

#if __cplusplus
}
#endif

#endif /* WIFIDEVICECLIENT_H_ */
