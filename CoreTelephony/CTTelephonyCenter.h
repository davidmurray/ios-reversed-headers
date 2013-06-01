/*
 * CoreTelephony notification support.
 */

#ifndef CTTELEPHONYCENTER_H_
#define CTTELEPHONYCENTER_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

#pragma mark - API

CFNotificationCenterRef CTTelephonyCenterGetDefault(void);
void CTTelephonyCenterAddObserver(CFNotificationCenterRef center, const void *observer, CFNotificationCallback callBack, CFStringRef name, const void *object, CFNotificationSuspensionBehavior suspensionBehavior);
void CTTelephonyCenterRemoveObserver(CFNotificationCenterRef center, const void *observer, CFStringRef name, const void *object);
void CTTelephonyCenterRemoveEveryObserver(CFNotificationCenterRef center, const void *observer);

__END_DECLS

#endif /* CTTELEPHONYCENTER_H_ */
