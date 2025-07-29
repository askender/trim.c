#ifndef TRIM_H
#define TRIM_H

/*
 * Trim Library - Version 0.1.0
 * A lightweight, efficient C library for trimming whitespace from strings in-place.
 */

#include <stddef.h>

/**
 * Trims leading and trailing whitespace from a string in-place.
 * 
 * This function removes all leading and trailing whitespace characters
 * (space, tab, newline, carriage return, form feed, vertical tab) from
 * the input string. The string is modified in-place.
 * 
 * @param str Pointer to the null-terminated string to trim. Must not be NULL.
 * @return Pointer to the trimmed string (same as input parameter).
 *         Returns NULL if the input is NULL.
 * 
 * @note The function modifies the original string.
 * @note The input string must be mutable (not a string literal).
 * 
 * Example:
 *   char text[] = "  hello world  ";
 *   trim(text);  // text now contains "hello world"
 */
char *trim(char *str);

#endif /* TRIM_H */
