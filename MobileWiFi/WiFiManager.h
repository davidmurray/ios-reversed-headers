/*
 * MobileWiFi manager header.
 *
 * Copyright (c) 2013-2014 Cykey (David Murray)
 * All rights reserved.
 */

#ifndef WIFIMANAGER_H_
#define WIFIMANAGER_H_

#include <CoreFoundation/CoreFoundation.h>
#include "WiFiNetwork.h"
#include "WiFiDeviceClient.h"

#if __cplusplus
extern "C" {
#endif

#pragma mark - Definitions

	typedef struct __WiFiManager *WiFiManagerRef;

#pragma mark - API

	WiFiManagerRef WiFiManagerClientCreate(CFAllocatorRef allocator, int flags);

	CFArrayRef WiFiManagerClientCopyDevices(WiFiManagerRef manager);
	CFArrayRef WiFiManagerClientCopyNetworks(WiFiManagerRef manager);

	void WiFiManagerClientRemoveNetwork(WiFiManagerRef manager, WiFiNetworkRef network);

	WiFiDeviceClientRef WiFiManagerClientGetDevice(WiFiManagerRef manager);

	void WiFiManagerClientScheduleWithRunLoop(WiFiManagerRef manager, CFRunLoopRef runLoop, CFStringRef mode);
	void WiFiManagerClientUnscheduleFromRunLoop(WiFiManagerRef manager);
	void WiFiManagerClientSetProperty(WiFiManagerRef manager, CFStringRef property, CFPropertyListRef value);

	CFPropertyListRef WiFiManagerClientCopyProperty(WiFiManagerRef manager, CFStringRef property);

	void WiFiManagerClientQuiesceWiFi(WiFiManagerRef manager, int state);

	void WiFiManagerClientSetMISState(WiFiManagerRef manager, int state);
	void WiFiManagerClientSetMisPassword(WiFiManagerRef manager, CFStringRef password);
	void WiFiManagerClientSetMISDiscoveryState(WiFiManagerRef manager, int state);

	int WiFiManagerClientGetMISState(WiFiManagerRef manager);
	int WiFiManagerClientGetMISDiscoveryState(WiFiManagerRef manager);

#if __cplusplus
}
#endif

#endif /* WIFIMANAGER_H_ */
