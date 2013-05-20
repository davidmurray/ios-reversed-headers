/*
 * SpringBoardServices framework header.
 */

#ifndef _SpringBoardServices_H_
#define _SpringBoardServices_H_

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

#endif /* _SpringBoardServices_H_ */
