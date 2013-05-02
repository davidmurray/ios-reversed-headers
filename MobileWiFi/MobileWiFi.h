/*
 * MobileWiFi framework header.
 */

#ifndef _MobileWiFi_H_
#define _MobileWiFi_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

/*
 * Opaque structure definitions.
 */

typedef struct __WiFiDeviceClient *WiFiDeviceClientRef;
typedef struct __WiFiNetwork      *WiFiNetworkRef;
typedef struct __WiFiManager      *WiFiManagerRef;

typedef CFErrorRef *WiFiErrorRef;

typedef void (*WiFiDeviceScanCallback)(WiFiDeviceClientRef device, CFArrayRef results, WiFiErrorRef error, void *token);
typedef void (*WiFiDeviceAssociateCallback)(WiFiDeviceClientRef device, WiFiNetworkRef network, CFDictionaryRef dict, WiFiErrorRef error, void *token);

#pragma mark - WiFi Manager Functions

WiFiManagerRef WiFiManagerClientCreate(CFAllocatorRef allocator, int flags);

CFArrayRef WiFiManagerClientCopyDevices(WiFiManagerRef manager);
CFArrayRef WiFiManagerClientCopyNetworks(WiFiManagerRef manager);

WiFiDeviceClientRef WiFiManagerClientGetDevice();

void WiFiManagerClientScheduleWithRunLoop(WiFiManagerRef manager, CFRunLoopRef runLoop, CFStringRef mode);
void WiFiManagerClientUnscheduleFromRunLoop(WiFiManagerRef manager);
void WiFiManagerClientSetProperty(WiFiManagerRef manager, CFStringRef property, CFPropertyListRef value);

CFPropertyListRef WiFiManagerClientCopyProperty(WiFiManagerRef manager, CFStringRef property);

#pragma mark - MIS (Mobile Internet Sharing) Functions

void WiFiManagerClientSetMISState(WiFiManagerRef manager, int state);
void WiFiManagerClientSetMisPassword(WiFiManagerRef manager, CFStringRef password);
void WiFiManagerClientSetMISDiscoveryState(WiFiManagerRef manager, int state);

int WiFiManagerClientGetMISState(WiFiManagerRef manager);
int WiFiManagerClientGetMISDiscoveryState(WiFiManagerRef manager);

#pragma mark - WiFi Network Functions

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

#pragma mark - WiFi device client functions

CFPropertyListRef WiFiDeviceClientCopyProperty(WiFiDeviceClientRef client, CFStringRef property);

WiFiNetworkRef WiFiDeviceClientCopyCurrentNetwork(WiFiDeviceClientRef client);

int WiFiDeviceClientGetPower(WiFiDeviceClientRef client);

void WiFiDeviceClientScanAsync(WiFiDeviceClientRef device, CFDictionaryRef dict, WiFiDeviceScanCallback callback, uint32_t flags);
void WiFiDeviceClientAssociateAsync(WiFiDeviceClientRef client, WiFiNetworkRef network, WiFiDeviceAssociateCallback callback, CFDictionaryRef dict);
void WiFiDeviceClientAssociateCancel(WiFiDeviceClientRef client);
void WiFiDeviceClientDisassociate(WiFiDeviceClientRef client);

CFStringRef WiFiDeviceClientGetInterfaceName(WiFiDeviceClientRef client);

#pragma mark - CFStringRef constants

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

__END_DECLS

#endif /* _MobileWiFi_H_ */
