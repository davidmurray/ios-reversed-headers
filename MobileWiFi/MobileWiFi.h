/*
 * MobileWiFi framework base header.
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
