/*
 * MobileWiFi device client header.
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
    typedef void (*WiFiDeviceScanCallback)(WiFiDeviceClientRef device, CFArrayRef results, CFErrorRef error, void *token);
    typedef void (*WiFiDeviceAssociateCallback)(WiFiDeviceClientRef device, WiFiNetworkRef network, CFDictionaryRef dict, CFErrorRef error, void *token);

#pragma mark - API

    CFPropertyListRef WiFiDeviceClientCopyProperty(WiFiDeviceClientRef client, CFStringRef property);

    WiFiNetworkRef WiFiDeviceClientCopyCurrentNetwork(WiFiDeviceClientRef client);

    int WiFiDeviceClientGetPower(WiFiDeviceClientRef client);

    void WiFiDeviceClientScanAsync(WiFiDeviceClientRef device, CFDictionaryRef dict, WiFiDeviceScanCallback callback, uint32_t flags);
    void WiFiDeviceClientAssociateAsync(WiFiDeviceClientRef client, WiFiNetworkRef network, WiFiDeviceAssociateCallback callback, CFDictionaryRef dict);
    void WiFiDeviceClientAssociateCancel(WiFiDeviceClientRef client);
    void WiFiDeviceClientDisassociate(WiFiDeviceClientRef client);

    CFStringRef WiFiDeviceClientGetInterfaceName(WiFiDeviceClientRef client);

    /* LQ stands for 'Link Quality', also known as signal strength. */
    void WiFiDeviceClientRegisterLQMCallback(WiFiDeviceClientRef device, WiFiDeviceClientCallback callback, const void *object);
    void WiFiDeviceClientRegisterExtendedLinkCallback(WiFiDeviceClientRef device, WiFiDeviceClientCallback callback, const void *object);
    void WiFiDeviceClientRegisterLinkCallback(WiFiDeviceClientRef device, WiFiDeviceClientLinkCallback callback, const void *object);

#if __cplusplus
}
#endif

#endif /* WIFIDEVICECLIENT_H_ */
