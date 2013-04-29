// Header for MobileWiFi.framework
// Copyright (C) 2013 Cykey (David Murray) cykey@live.com
// All rights reserved.

#ifndef MOBILEWIFI_H
#define MOBILEWIFI_H

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

    extern WiFiManagerRef WiFiManagerClientCreate(CFAllocatorRef allocator, int flags);
    extern CFArrayRef WiFiManagerClientCopyDevices(WiFiManagerRef manager);
    extern CFArrayRef WiFiManagerClientCopyNetworks(WiFiManagerRef manager);
    extern WiFiDeviceClientRef WiFiManagerClientGetDevice();
    extern void WiFiManagerClientScheduleWithRunLoop(WiFiManagerRef manager, CFRunLoopRef runLoop, CFStringRef mode);
    extern void WiFiManagerClientUnscheduleFromRunLoop(WiFiManagerRef manager);
    extern void WiFiManagerClientSetProperty(WiFiManagerRef manager, CFStringRef property, CFPropertyListRef value);
    extern CFPropertyListRef WiFiManagerClientCopyProperty(WiFiManagerRef manager, CFStringRef property);
    // MIS is WiFi tethering (Mobile Internet Sharing).
    extern int WiFiManagerClientGetMISState(WiFiManagerRef manager);
    extern void WiFiManagerClientSetMISState(WiFiManagerRef manager, int state);
    extern void WiFiManagerClientSetMisPassword(WiFiManagerRef manager, CFStringRef password);
    extern void WiFiManagerClientSetMISDiscoveryState(WiFiManagerRef manager, int state);
    extern int WiFiManagerClientGetMISDiscoveryState(WiFiManagerRef manager);

    // WiFi network functions.

    extern CFPropertyListRef WiFiNetworkGetProperty(WiFiNetworkRef network, CFStringRef property);
    extern int WiFiNetworkGetIntProperty(WiFiNetworkRef network, CFStringRef property);
    extern float WiFiNetworkGetFloatProperty(WiFiNetworkRef network, CFStringRef property);
    extern CFStringRef WiFiNetworkCopyPassword(WiFiNetworkRef);
    extern void WiFiNetworkSetPassword(WiFiNetworkRef network, CFStringRef password);
    extern CFStringRef WiFiNetworkGetSSID(WiFiNetworkRef network);
    extern float WiFiNetworkGetNetworkUsage(WiFiNetworkRef network);
    extern Boolean WiFiNetworkIsWEP(WiFiNetworkRef network);
    extern Boolean WiFiNetworkIsWPA(WiFiNetworkRef network);
    extern Boolean WiFiNetworkIsEAP(WiFiNetworkRef network);
    extern Boolean WiFiNetworkIsApplePersonalHotspot(WiFiNetworkRef network);
    extern Boolean WiFiNetworkIsAdHoc(WiFiNetworkRef network);
    extern Boolean WiFiNetworkIsHidden(WiFiNetworkRef network);
    extern Boolean WiFiNetworkRequiresPassword(WiFiNetworkRef network);
    extern Boolean WiFiNetworkRequiresUsername(WiFiNetworkRef network);
    extern CFDateRef WiFiNetworkGetLastAssociationDate(WiFiNetworkRef network);
    extern CFDictionaryRef WiFiNetworkCopyRecord(WiFiNetworkRef network);

    // WiFi device client functions.

    extern CFPropertyListRef WiFiDeviceClientCopyProperty(WiFiDeviceClientRef client, CFStringRef property);
    extern WiFiNetworkRef WiFiDeviceClientCopyCurrentNetwork(WiFiDeviceClientRef client);
    extern int WiFiDeviceClientGetPower(WiFiDeviceClientRef client);
    extern void WiFiDeviceClientScanAsync(WiFiDeviceClientRef device, CFDictionaryRef dict, WiFiDeviceScanCallback callback, uint32_t flags);
    extern void WiFiDeviceClientAssociateAsync(WiFiDeviceClientRef client, WiFiNetworkRef network, WiFiDeviceAssociateCallback callback, CFDictionaryRef dict);
    extern void WiFiDeviceClientAssociateCancel(WiFiDeviceClientRef client);
    extern void WiFiDeviceClientDisassociate(WiFiDeviceClientRef client);
    extern CFStringRef WiFiDeviceClientGetInterfaceName(WiFiDeviceClientRef client);

    extern CFStringRef kWiFiATJTestModeEnabledKey;
    extern CFStringRef kWiFiDeviceCapabilitiesKey;
    extern CFStringRef kWiFiDeviceSupportsWAPIKey;
    extern CFStringRef kWiFiDeviceSupportsWoWKey;
    extern CFStringRef kWiFiDeviceVendorIDKey;
    extern CFStringRef kWiFiLocaleTestParamsKey;
    extern CFStringRef kWiFiLoggingDriverFileKey;
    extern CFStringRef kWiFiLoggingDriverLoggingEnabledKey;
    extern CFStringRef kWiFiLoggingEnabledKey;
    extern CFStringRef kWiFiLoggingFileEnabledKey;
    extern CFStringRef kWiFiLoggingFileKey;
    extern CFStringRef kWiFiManagerDisableBlackListKey;
    extern CFStringRef kWiFiNetworkEnterpriseProfileKey;
    extern CFStringRef kWiFiPreferenceCustomNetworksSettingsKey;
    extern CFStringRef kWiFiPreferenceEnhancedWoWEnabledKey;
    extern CFStringRef kWiFiPreferenceMStageAutoJoinKey;
    extern CFStringRef kWiFiRSSIThresholdKey; // '-80'
    extern CFStringRef kWiFiScaledRSSIKey;
    extern CFStringRef kWiFiScaledRateKey;
    extern CFStringRef kWiFiStrengthKey;
    extern CFStringRef kWiFiTetheringCredentialsKey;


#ifdef __cplusplus
}
#endif

#endif
