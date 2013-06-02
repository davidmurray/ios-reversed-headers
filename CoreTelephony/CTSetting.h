/*
 * CoreTelephony setting.
 */

#ifndef CTSETTING_H_
#define CTSETTING_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

#pragma mark - API

    CFStringRef CTSettingCopyMyPhoneNumber();
    CFDictionaryRef CTSettingCopyMyPhoneNumberExtended();

#if __cplusplus
}
#endif

#endif /* CTSETTING_H_ */
