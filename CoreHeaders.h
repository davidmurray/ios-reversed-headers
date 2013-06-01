/*
 * Core header file.
 */

#ifndef _CORE_HEADERS_H_
#define _CORE_HEADERS_H_

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

#include <CoreFoundation/CoreFoundation.h>
#include <sys/types.h>
#include <sys/cdefs.h>
#include <stdint.h>

#endif
