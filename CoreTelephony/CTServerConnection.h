/*
 * CoreTelephony server connection support.
 *
 * Copyright (c) 2013-2016 Cykey (David Murray)
 * All rights reserved.
 */

#ifndef CTSERVERCONNECTION_H_
#define CTSERVERCONNECTION_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

	struct __CTServerConnection
	{
		int a;
		int b;
		CFMachPortRef port;
		int c;
		int d;
		int e;
		int f;
		int g;
		int h;
		int i;
	};
	
	typedef struct __CTServerConnection *CTServerConnectionRef;
	
	struct __CellInfo
	{
		int servingmnc;
		int network;
		int location;
		int cellid;
		int station;
		int freq;
		int rxlevel;
		int c1;
		int c2;
	};

	extern CFStringRef kCTIndicatorRadioTransmitNotification;
	extern CFStringRef kCTRadioTransmitDCHStatus;
	
	typedef struct __CellInfo CellInfo;
	
	typedef void (*CTServerConnectionCreateCallback)(CTServerConnectionRef serverConnection, CFStringRef string, CFDictionaryRef flags, void *unknown);
	typedef void (*CTServerConnectionNotificationCallback)(CTServerConnectionRef serverConnection, CFStringRef string, CFDictionaryRef flags, void *unknown);
	
	CTServerConnectionRef _CTServerConnectionCreate(CFAllocatorRef allocator, CTServerConnectionCreateCallback callback, int *unknown);
	CTServerConnectionRef _CTServerConnectionCreateWithIdentifier(CFAllocatorRef allocator, const char *identifier, CTServerConnectionCreateCallback callback, int *unknown);
	void _CTServerConnectionAddToRunLoop(CTServerConnectionRef connection, CFRunLoopRef runLoop);
	void _CTServerConnectionSetTargetQueue(CTServerConnectionRef serverConnection, dispatch_queue_t queue);
	
	mach_port_t _CTServerConnectionGetPort(CTServerConnectionRef connection);
	
	void _CTServerConnectionCellMonitorStart(CFMachPortRef *port, CTServerConnectionRef connection);
	
	void _CTServerConnectionRegisterForNotification(CTServerConnectionRef conncetion, CFStringRef notification, CTServerConnectionNotificationCallback);
	void kCTCellMonitorUpdateNotification();
	
	void _CTServerConnectionCellMonitorGetCellCount(CFMachPortRef *port, CTServerConnectionRef connection, int *cellInfoCount);
	void _CTServerConnectionCellMonitorGetCellInfo(CFMachPortRef *port, CTServerConnectionRef connection, int cellInfoNumber, void *buffer);

#if __cplusplus
}
#endif

#endif /* CTSERVERCONNECTION_H_ */
