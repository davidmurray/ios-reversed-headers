/*
 * BackBoardServices framework header.
 *
 * Copyright (c) 2013-2014 Cykey (David Murray) and ProtoSphere (Joshua Kugelmann)
 * All rights reserved.
 */

#ifndef BACKBOARDSERVICES_H_
#define BACKBOARDSERVICES_H_

#import <CoreFoundation/CoreFoundation.h>


#if __cplusplus
extern "C" {
#endif

#pragma mark - Definitions

	#define BKSProcessAssertionFlagNone 0
	#define BKSProcessAssertionFlagPreventSuspend (1 << 0)
	#define BKSProcessAssertionFlagPreventThrottleDownCPU (1 << 1)
	#define BKSProcessAssertionFlagAllowIdleSleep (1 << 2)
	#define BKSProcessAssertionFlagWantsForegroundResourcePriority (1 << 3)

	typedef enum {
		BKSProcessAssertionReasonNone,
		BKSProcessAssertionReasonAudio,
		BKSProcessAssertionReasonLocation,
		BKSProcessAssertionReasonExternalAccessory,
		BKSProcessAssertionReasonFinishTask,
		BKSProcessAssertionReasonBluetooth,
		BKSProcessAssertionReasonNetworkAuthentication,
		BKSProcessAssertionReasonBackgroundUI,
		BKSProcessAssertionReasonInterAppAudioStreaming,
		BKSProcessAssertionReasonViewServices
	} BKSProcessAssertionReason;

	typedef void (^BKSProcessAssertionCompletion)(BOOL success);
	typedef struct BKSDisplayBrightnessTransaction *BKSDisplayBrightnessTransactionRef;

#pragma mark - API
	/*
	 * Level should be from 0.0 to 1.0.
	 * Use 1 for __unknown0.
	 */
	void BKSDisplayBrightnessSet(float level, int __unknown0);

	/* Returns a value from 0.0 to 1.0. */
	float BKSDisplayBrightnessGetCurrent();

	/* Follows the 'Create' rule. */
	BKSDisplayBrightnessTransactionRef BKSDisplayBrightnessTransactionCreate(CFAllocatorRef allocator);

	void BKSDisplayBrightnessSetAutoBrightnessEnabled(Boolean enabled);

	void BKSHIDServicesSetBacklightFactorWithFadeDuration(float factor, int duration);

	/*
	 * Check out http://iphonedevwiki.net/index.php/BackBoardServices.framework
	 * for more information on BKSTerminate functions.
	 */

	void BKSTerminateApplicationForReasonAndReportWithDescription(CFStringRef applicationIdentifier, int __unknown0, int __unknown1, CFStringRef description);
	void BKSTerminateApplicationGroupForReasonAndReportWithDescription(int __unknown0, int __unknown1, int __unknown2, CFStringRef description);

	void BKSHIDServicesLockOrientation();
	void BKSHIDServicesUnlockOrientation();

#if __cplusplus
}
#endif

#endif /* BACKBOARDSERVICES_H_ */
