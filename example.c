#include "trim.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    // Example 1: Basic trimming
    char str1[] = "  hello world  ";
    printf("Original: '%s'\n", str1);
    trim(str1);
    printf("Trimmed:  '%s'\n\n", str1);

    // Example 2: Trimming tabs and newlines
    char str2[] = "\t\n  example string  \n\t";
    printf("Original: '\\t\\n  example string  \\n\\t'\n");
    trim(str2);
    printf("Trimmed:  '%s'\n\n", str2);

    // Example 3: String with no leading/trailing spaces
    char str3[] = "no spaces";
    printf("Original: '%s'\n", str3);
    trim(str3);
    printf("Trimmed:  '%s'\n\n", str3);

    // Example 4: String with only spaces
    char str4[] = "   ";
    printf("Original: '   '\n");
    trim(str4);
    printf("Trimmed:  '%s'\n\n", str4);

    // Example 5: Empty string
    char str5[] = "";
    printf("Original: ''\n");
    trim(str5);
    printf("Trimmed:  '%s'\n\n", str5);

    // Example 6: Using return value for chaining
    char str6[] = "  chained example  ";
    printf("Chained usage: '%s'\n", trim(str6));

    return 0;
}
