#ifndef TRIM_VERSION_H
#define TRIM_VERSION_H

/**
 * @file trim_version.h
 * @brief Version information for the trim library
 */

/** Major version number */
#define TRIM_VERSION_MAJOR 0

/** Minor version number */
#define TRIM_VERSION_MINOR 1

/** Patch version number */
#define TRIM_VERSION_PATCH 0

/** Version string */
#define TRIM_VERSION_STRING "0.1.0"

/** 
 * Version as a single integer for easy comparison
 * Format: MAJOR * 10000 + MINOR * 100 + PATCH
 */
#define TRIM_VERSION_NUMBER (TRIM_VERSION_MAJOR * 10000 + TRIM_VERSION_MINOR * 100 + TRIM_VERSION_PATCH)

/**
 * Get the version string of the trim library
 * @return Pointer to the version string
 */
static inline const char *trim_version(void) {
    return TRIM_VERSION_STRING;
}

/**
 * Get the version number of the trim library
 * @return Version number as integer
 */
static inline int trim_version_number(void) {
    return TRIM_VERSION_NUMBER;
}

/**
 * Check if the library version is at least the specified version
 * @param major Major version number
 * @param minor Minor version number  
 * @param patch Patch version number
 * @return 1 if current version >= specified version, 0 otherwise
 */
static inline int trim_version_check(int major, int minor, int patch) {
    int check_version = major * 10000 + minor * 100 + patch;
    return TRIM_VERSION_NUMBER >= check_version;
}

#endif /* TRIM_VERSION_H */