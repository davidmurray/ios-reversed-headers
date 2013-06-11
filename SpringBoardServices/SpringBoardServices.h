/*
 * SpringBoardServices framework header.
 * Borrows work done by KennyTM.
 * See https://github.com/kennytm/iphone-private-frameworks/blob/master/SpringBoardServices/SpringBoardServices.h
 * for more information.
 */

#ifndef SPRINGBOARDSERVICES_H_
#define SPRINGBOARDSERVICES_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

#pragma mark - API

    void SBSOpenNewsstand();
    void SBSSuspendFrontmostApplication();

    CFStringRef SBSCopyBundlePathForDisplayIdentifier(CFStringRef displayIdentifier);
    CFStringRef SBSCopyExecutablePathForDisplayIdentifier(CFStringRef displayIdentifier);
    CFDataRef SBSCopyIconImagePNGDataForDisplayIdentifier(CFStringRef displayIdentifier);

    CFStringRef SBSCopyFrontmostApplicationDisplayIdentifier();
    CFStringRef SBSCopyDisplayIdentifierForProcessID(pid_t PID);
    CFArrayRef SBSCopyDisplayIdentifiersForProcessID(pid_t PID);
    BOOL SBSProcessIDForDisplayIdentifier(CFStringRef identifier, pid_t *pid);

    int SBSLaunchApplicationWithIdentifier(CFStringRef identifier, Boolean suspended);
    int SBSLaunchApplicationWithIdentifierAndLaunchOptions(CFStringRef identifier, CFDictionaryRef launchOptions, BOOL suspended);
    CFStringRef SBSApplicationLaunchingErrorString(int error);

#if __cplusplus
}
#endif

#endif /* SPRINGBOARDSERVICES_H_ */
