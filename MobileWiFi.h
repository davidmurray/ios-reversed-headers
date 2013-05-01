// Header for MobileWiFi.framework
// Copyright (C) 2013 Cykey (David Murray) cykey@live.com
// All rights reserved.

#ifndef _MOBILEWIFI_H_
#define _MOBILEWIFI_H_

#include <CoreFoundation/CoreFoundation.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct __WiFiDeviceClient *WiFiDeviceClientRef;
    typedef struct __WiFiNetwork      *WiFiNetworkRef;
    typedef struct __WiFiManager      *WiFiManagerRef;
    typedef CFErrorRef                *WiFiErrorRef;

    typedef void (*WiFiDeviceScanCallback)(WiFiDeviceClientRef device, CFArrayRef results, WiFiErrorRef error, void *token);
    typedef void (*WiFiDeviceAssociateCallback)(WiFiDeviceClientRef device, WiFiNetworkRef network, CFDictionaryRef dict, WiFiErrorRef error, void *token);

    // WiFi manager functions.

    WiFiManagerRef WiFiManagerClientCreate(CFAllocatorRef allocator, int flags);
    CFArrayRef WiFiManagerClientCopyDevices(WiFiManagerRef manager);
    CFArrayRef WiFiManagerClientCopyNetworks(WiFiManagerRef manager);
    WiFiDeviceClientRef WiFiManagerClientGetDevice();
    void WiFiManagerClientScheduleWithRunLoop(WiFiManagerRef manager, CFRunLoopRef runLoop, CFStringRef mode);
    void WiFiManagerClientUnscheduleFromRunLoop(WiFiManagerRef manager);
    void WiFiManagerClientSetProperty(WiFiManagerRef manager, CFStringRef property, CFPropertyListRef value);
    CFPropertyListRef WiFiManagerClientCopyProperty(WiFiManagerRef manager, CFStringRef property);
    // MIS is WiFi tethering (Mobile Internet Sharing).
    int WiFiManagerClientGetMISState(WiFiManagerRef manager);
    void WiFiManagerClientSetMISState(WiFiManagerRef manager, int state);
    void WiFiManagerClientSetMisPassword(WiFiManagerRef manager, CFStringRef password);
    void WiFiManagerClientSetMISDiscoveryState(WiFiManagerRef manager, int state);
    int WiFiManagerClientGetMISDiscoveryState(WiFiManagerRef manager);

    // WiFi network functions.

    CFPropertyListRef WiFiNetworkGetProperty(WiFiNetworkRef network, CFStringRef property);
    int WiFiNetworkGetIntProperty(WiFiNetworkRef network, CFStringRef property);
    float WiFiNetworkGetFloatProperty(WiFiNetworkRef network, CFStringRef property);
    CFStringRef WiFiNetworkCopyPassword(WiFiNetworkRef);
    void WiFiNetworkSetPassword(WiFiNetworkRef network, CFStringRef password);
    CFStringRef WiFiNetworkGetSSID(WiFiNetworkRef network);
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

    // WiFi device client functions.

    CFPropertyListRef WiFiDeviceClientCopyProperty(WiFiDeviceClientRef client, CFStringRef property);
    WiFiNetworkRef WiFiDeviceClientCopyCurrentNetwork(WiFiDeviceClientRef client);
    int WiFiDeviceClientGetPower(WiFiDeviceClientRef client);
    void WiFiDeviceClientScanAsync(WiFiDeviceClientRef device, CFDictionaryRef dict, WiFiDeviceScanCallback callback, uint32_t flags);
    void WiFiDeviceClientAssociateAsync(WiFiDeviceClientRef client, WiFiNetworkRef network, WiFiDeviceAssociateCallback callback, CFDictionaryRef dict);
    void WiFiDeviceClientAssociateCancel(WiFiDeviceClientRef client);
    void WiFiDeviceClientDisassociate(WiFiDeviceClientRef client);
    CFStringRef WiFiDeviceClientGetInterfaceName(WiFiDeviceClientRef client);

    CFStringRef kWiFiATJTestModeEnabledKey;
    CFStringRef kWiFiDeviceCapabilitiesKey;
    CFStringRef kWiFiDeviceSupportsWAPIKey;
    CFStringRef kWiFiDeviceSupportsWoWKey;
    CFStringRef kWiFiDeviceVendorIDKey;
    CFStringRef kWiFiLocaleTestParamsKey;
    CFStringRef kWiFiLoggingDriverFileKey;
    CFStringRef kWiFiLoggingDriverLoggingEnabledKey;
    CFStringRef kWiFiLoggingEnabledKey;
    CFStringRef kWiFiLoggingFileEnabledKey;
    CFStringRef kWiFiLoggingFileKey;
    CFStringRef kWiFiManagerDisableBlackListKey;
    CFStringRef kWiFiNetworkEnterpriseProfileKey;
    CFStringRef kWiFiPreferenceCustomNetworksSettingsKey;
    CFStringRef kWiFiPreferenceEnhancedWoWEnabledKey;
    CFStringRef kWiFiPreferenceMStageAutoJoinKey;
    CFStringRef kWiFiRSSIThresholdKey; // '-80'
    CFStringRef kWiFiScaledRSSIKey;
    CFStringRef kWiFiScaledRateKey;
    CFStringRef kWiFiStrengthKey;
    CFStringRef kWiFiTetheringCredentialsKey;

#ifdef __cplusplus
}
#endif

#endif
