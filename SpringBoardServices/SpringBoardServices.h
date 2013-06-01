/*
 * SpringBoardServices framework header.
 */

#ifndef SPRINGBOARDSERVICES_H_
#define SPRINGBOARDSERVICES_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

void SBSOpenNewsstand();

CFStringRef SBSCopyBundlePathForDisplayIdentifier(CFStringRef displayIdentifier);
CFStringRef SBSCopyExecutablePathForDisplayIdentifier(CFStringRef displayIdentifier);
CFDataRef SBSCopyIconImagePNGDataForDisplayIdentifier(CFStringRef displayIdentifier);

CFStringRef SBSCopyFrontmostApplicationDisplayIdentifier();
CFStringRef SBSCopyDisplayIdentifierForProcessID(pid_t PID);
CFArrayRef SBSCopyDisplayIdentifiersForProcessID(pid_t PID);

void SBSSuspendFrontmostApplication();

__END_DECLS

#endif /* SPRINGBOARDSERVICES_H_ */
