/*
 * CoreTelephony setting.
 */

#ifndef CTSETTING_H_
#define CTSETTING_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

CFStringRef CTSettingCopyMyPhoneNumber();
CFDictionaryRef CTSettingCopyMyPhoneNumberExtended();

__END_DECLS

#endif /* CTSETTING_H_ */
