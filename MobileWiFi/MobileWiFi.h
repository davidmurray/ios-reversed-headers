/*
 * MobileWiFi framework header.
 */

#ifndef MOBILEWIFI_H_
#define MOBILEWIFI_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

/*
 * Opaque structure definitions.
 */

typedef struct __WiFiDeviceClient *WiFiDeviceClientRef;
typedef struct __WiFiNetwork      *WiFiNetworkRef;
typedef struct __WiFiManager      *WiFiManagerRef;

typedef void (*WiFiDeviceScanCallback)(WiFiDeviceClientRef device, CFArrayRef results, CFErrorRef error, void *token);
typedef void (*WiFiDeviceAssociateCallback)(WiFiDeviceClientRef device, WiFiNetworkRef network, CFDictionaryRef dict, CFErrorRef error, void *token);

#pragma mark - WiFi Manager Functions

WiFiManagerRef WiFiManagerClientCreate(CFAllocatorRef allocator, int flags);

CFArrayRef WiFiManagerClientCopyDevices(WiFiManagerRef manager);
CFArrayRef WiFiManagerClientCopyNetworks(WiFiManagerRef manager);

WiFiDeviceClientRef WiFiManagerClientGetDevice(WiFiManagerRef manager);

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

__END_DECLS

#endif /* MOBILEWIFI_H_ */
