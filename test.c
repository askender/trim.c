#include "trim.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char test1[] = "  hello world  ";
    char test2[] = "\t\n  test string  \n\t";
    char test3[] = "no spaces";
    char test4[] = "   ";
    char test5[] = "";

    printf("Testing trim function:\n");
    printf("Before: '%s' -> After: '%s'\n", "  hello world  ", trim(test1));
    printf("Before: '%s' -> After: '%s'\n", "\\t\\n  test string  \\n\\t",
           trim(test2));
    printf("Before: '%s' -> After: '%s'\n", "no spaces", trim(test3));
    printf("Before: '%s' -> After: '%s'\n", "   ", trim(test4));
    printf("Before: '%s' -> After: '%s'\n", "", trim(test5));

    return 0;
}
