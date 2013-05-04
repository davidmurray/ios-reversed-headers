/*
 * CoreTelephony setting.
 */

#ifndef _CTSetting_H_
#define _CTSetting_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

CFStringRef CTSettingCopyMyPhoneNumber();
CFDictionaryRef CTSettingCopyMyPhoneNumberExtended();

__END_DECLS

#endif /* _CTSetting_H_ */
