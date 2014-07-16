/*
 * Mobile Icons framework header.
 *
 * Copyright (c) 2013-2014 Cykey (David Murray)
 * All rights reserved.
 */

#ifndef MOBILEICONS_H_
#define MOBILEICONS_H_

#include <CoreFoundation/CoreFoundation.h>

#if __cplusplus
extern "C" {
#endif

    CFArrayRef LICopyIconPathsFromBundle(CFBundleRef bundle);
    CGImageRef LICreateDefaultIcon(int variant);
    CGImageRef LICreateIconForBundle(CFBundleRef bundle);
    CGImageRef LICreateIconForImage(CGImageRef image, int variant, int precomposed);

#if __cplusplus
}
#endif

#endif /* MEDIAREMOTE_H_ */
