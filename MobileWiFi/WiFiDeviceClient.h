/*
 * MobileWiFi device client header.
 *
 * Copyright (c) 2013-2014 Cykey (David Murray)
 * All rights reserved.
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
    typedef void (*WiFiDeviceClientGenericCallback)(WiFiDeviceClientRef device, CFDictionaryRef data, const void *object);
    typedef void (*WiFiDeviceClientLinkOrPowerCallback)(WiFiDeviceClientRef device, const void *object);
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

    /*
     * LQM stands for 'Link Quality Metrics':
     * Jan 23 15:25:01  kernel[0] <Debug>: 187357.621783 wlan.A[13651] AppleBCMWLANNetManager::updateLinkQualityMetrics(): Report LQM to User Land 50, fAverageRSSI -71
     */

    void WiFiDeviceClientRegisterLQMCallback(WiFiDeviceClientRef device, WiFiDeviceClientGenericCallback callback, const void *object);
    void WiFiDeviceClientRegisterExtendedLinkCallback(WiFiDeviceClientRef device, WiFiDeviceClientGenericCallback callback, const void *object);
    void WiFiDeviceClientRegisterLinkCallback(WiFiDeviceClientRef device, WiFiDeviceClientLinkOrPowerCallback callback, const void *object);
    void WiFiDeviceClientRegisterPowerCallback(WiFiDeviceClientRef device, WiFiDeviceClientLinkOrPowerCallback callback, const void *object);

#if __cplusplus
}
#endif

#endif /* WIFIDEVICECLIENT_H_ */
