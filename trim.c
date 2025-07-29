#include "trim.h"
#include <ctype.h>
#include <string.h>

char *trim(char *str) {
    char *start;
    const char *end;
    size_t len;

    // Check for NULL input
    if (str == NULL) {
        return NULL;
    }

    // Handle empty string
    if (*str == '\0') {
        return str;
    }

    // Find first non-whitespace character (ltrim)
    start = str;
    while (isspace((unsigned char)*start)) {
        start++;
    }

    // If string contains only whitespace
    if (*start == '\0') {
        *str = '\0'; // Make original string empty
        return str;
    }

    // Find last non-whitespace character (rtrim)
    end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    // Calculate length of trimmed string
    len = end - start + 1;

    // Move trimmed content to beginning if necessary
    if (start != str) {
        memmove(str, start, len);
    }

    // Null terminate the trimmed string
    str[len] = '\0';

    return str;
}
