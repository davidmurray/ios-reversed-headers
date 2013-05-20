/*
 * MobileInstallation framework header.
 */

#ifndef _MobileInstallation_H_
#define _MobileInstallation_H_

#include "CoreHeaders.h"

__BEGIN_DECLS

/*
 * 'ReturnAttributes' is one (or an array) of the keys in the dictionary returned by MobileInstallationLookup(NULL).
 * Or 'BundleIDs' which tells installd to return only the bundle identifiers.
 * Extra keys:
 *  - SharedDirSize
 *  - StaticDiskUsage
 *  - DynamicDiskUsage
 *  - ApplicationSINF
 *  - iTunesMetadata
 *  - iTunesArtwork
 *  - GeoJSON
 *  - NewsstandArtwork
 * Example usage:
 *   NSDictionary *attributes = [NSDictionary dictionaryWithObjectsAndKeys:@"BundleIDs", @"ReturnAttributes", nil];
 *   CFDictionaryRef data = MobileInstallationLookup((CFDictionaryRef)attributes);
 */

CFDictionaryRef MobileInstallationLookup(CFDictionaryRef properties);

/*
 * Use 0 for all 3 unknown arguments.
 * Your program needs the "com.apple.private.mobileinstall.allowedSPI" entitlement to use this function with an array containing the 'Uninstall' string.
 *
 * Example:
 *  <key>com.apple.private.mobileinstall.allowedSPI</key>
 *  <true/>
 *  <array>
 *      <string>Uninstall</string>
 *  </array>
 *
 * Return values:
 *  -1: Something went wrong. E.g your program doesn't have the necessary entitlements.
 *   0: Everything is okay.
 */

int MobileInstallationUninstall(CFStringRef bundleIdentifier, int __unknown0, int __unknown1, int __unknown2);

__END_DECLS

#endif /* _MobileInstallation_H_ */
