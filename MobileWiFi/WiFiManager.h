/*
 * MobileWiFi manager header.
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

	void WiFiManagerClientSetMISState(WiFiManagerRef manager, int state);
	void WiFiManagerClientSetMisPassword(WiFiManagerRef manager, CFStringRef password);
	void WiFiManagerClientSetMISDiscoveryState(WiFiManagerRef manager, int state);

	int WiFiManagerClientGetMISState(WiFiManagerRef manager);
	int WiFiManagerClientGetMISDiscoveryState(WiFiManagerRef manager);

#if __cplusplus
}
#endif

#endif /* WIFIMANAGER_H_ */
