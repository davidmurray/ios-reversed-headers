/*
 * MobileWiFi framework base header.
 *
 * Copyright (c) 2013-2014 Cykey (David Murray)
 * All rights reserved.
 */

#ifndef MOBILEWIFI_H_
#define MOBILEWIFI_H_

#include "WiFiDeviceClient.h"
#include "WiFiNetwork.h"
#include "WiFiManager.h"

#if __cplusplus
extern "C" {
#endif

#pragma mark - Constants

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

#if __cplusplus
}
#endif

#endif /* MOBILEWIFI_H_ */
