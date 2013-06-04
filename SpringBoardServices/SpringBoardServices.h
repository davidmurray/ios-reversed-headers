/*
 * SpringBoardServices framework header.
 */

#ifndef SPRINGBOARDSERVICES_H_
#define SPRINGBOARDSERVICES_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

#pragma mark - API

    void SBSOpenNewsstand();

    CFStringRef SBSCopyBundlePathForDisplayIdentifier(CFStringRef displayIdentifier);
    CFStringRef SBSCopyExecutablePathForDisplayIdentifier(CFStringRef displayIdentifier);
    CFDataRef SBSCopyIconImagePNGDataForDisplayIdentifier(CFStringRef displayIdentifier);

    CFStringRef SBSCopyFrontmostApplicationDisplayIdentifier();
    CFStringRef SBSCopyDisplayIdentifierForProcessID(pid_t PID);
    CFArrayRef SBSCopyDisplayIdentifiersForProcessID(pid_t PID);
	BOOL SBSProcessIDForDisplayIdentifier(CFStringRef identifier, pid_t *pid);

	int SBSLaunchApplicationWithIdentifierAndLaunchOptions(CFStringRef identifier, CFDictionaryRef launchOptions, BOOL suspended);	
    void SBSSuspendFrontmostApplication();

#if __cplusplus
}
#endif

#endif /* SPRINGBOARDSERVICES_H_ */
