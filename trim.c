#include <ctype.h>
#include <string.h>

char *trim(char *str) {
    char *start = str;
    char *end;

    // ltrim - find first non-space character
    while (isspace(*start)) {
        start++;
    }

    if (*start == 0) { // only spaces
        *str = 0;      // make original string empty
        return str;
    }

    // rtrim - find last non-space character
    end = start + strlen(start) - 1;
    while (end > start && isspace(*end)) {
        end--;
    }

    // move trimmed content to beginning and null terminate
    size_t len = end - start + 1;
    memmove(str, start, len);
    str[len] = 0;

    return str;
}
