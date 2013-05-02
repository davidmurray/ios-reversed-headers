/*
 * TelephonyUI header file.
 */

#ifndef _TelephonyUI_H_
#define _TelephonyUI_H_

#pragma once

#include "CoreHeaders.h"
#include "CoreTelephony/CTCall.h"

__BEGIN_DECLS

/*
 * Use 0 for __reserved.
 */

CTCallRef TPGetDisplayedCallFromCalls(uint32_t __reserved);

__END_DECLS

#endif /* _TelephonyUI_H_ */
