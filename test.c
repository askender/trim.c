#include "trim.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Test helper function to compare strings
static void test_trim(const char *input, const char *expected,
                      const char *test_name) {
    char *test_str = malloc(strlen(input) + 1);
    if (test_str == NULL) {
        printf("✗ %s: FAILED (memory allocation failed)\n", test_name);
        return;
    }
    strcpy(test_str, input);

    char *result = trim(test_str);

    if (strcmp(test_str, expected) == 0 && result == test_str) {
        printf("✓ %s: PASSED\n", test_name);
    } else {
        printf("✗ %s: FAILED\n", test_name);
        printf("  Input: '%s'\n", input);
        printf("  Expected: '%s'\n", expected);
        printf("  Got: '%s'\n", test_str);
        printf("  Return value correct: %s\n",
               (result == test_str) ? "yes" : "no");
    }

    free(test_str);
}

int main(void) {
    printf("Running comprehensive trim function tests:\n\n");

    // Basic functionality tests
    test_trim("  hello world  ", "hello world",
              "Basic leading and trailing spaces");
    test_trim("\t\n  test string  \n\t", "test string",
              "Mixed whitespace characters");
    test_trim("no spaces", "no spaces", "No trimming needed");
    test_trim("   ", "", "Only spaces");
    test_trim("", "", "Empty string");

    // Edge cases
    test_trim(" ", "", "Single space");
    test_trim("\t", "", "Single tab");
    test_trim("\n", "", "Single newline");
    test_trim("\r", "", "Single carriage return");
    test_trim("\f", "", "Single form feed");
    test_trim("\v", "", "Single vertical tab");

    // Leading whitespace only
    test_trim("  hello", "hello", "Leading spaces only");
    test_trim("\t\nhello", "hello", "Leading tabs and newlines only");

    // Trailing whitespace only
    test_trim("hello  ", "hello", "Trailing spaces only");
    test_trim("hello\t\n", "hello", "Trailing tabs and newlines only");

    // Internal whitespace preservation
    test_trim("  hello world  ", "hello world", "Internal spaces preserved");
    test_trim("  hello\tworld  ", "hello\tworld", "Internal tabs preserved");
    test_trim("  hello\nworld  ", "hello\nworld",
              "Internal newlines preserved");

    // Single character tests
    test_trim(" a ", "a", "Single character with spaces");
    test_trim("a", "a", "Single character no spaces");
    test_trim(" a", "a", "Single character leading space");
    test_trim("a ", "a", "Single character trailing space");

    // Mixed whitespace combinations
    test_trim(" \t\n\r\f\v hello \t\n\r\f\v ", "hello", "All whitespace types");
    test_trim("  \t  hello world  \n  ", "hello world",
              "Mixed leading/trailing");

    // Longer strings
    test_trim("    this is a longer test string with multiple words    ",
              "this is a longer test string with multiple words",
              "Longer string test");

    // NULL pointer test
    printf("Testing NULL pointer handling:\n");
    const char *null_result = trim(NULL);
    if (null_result == NULL) {
        printf("✓ NULL input handling: PASSED\n");
    } else {
        printf("✗ NULL input handling: FAILED (should return NULL)\n");
    }

    // Test return value consistency
    printf("\nTesting return value consistency:\n");
    char test_return[] = "  test  ";
    char *original_ptr = test_return;
    const char *returned_ptr = trim(test_return);

    if (returned_ptr == original_ptr) {
        printf("✓ Return value consistency: PASSED (returns same pointer)\n");
    } else {
        printf("✗ Return value consistency: FAILED (should return same "
               "pointer)\n");
    }

    // Unicode/extended ASCII (if supported by locale)
    test_trim("  café  ", "café", "Non-ASCII characters");

    printf("\nAll tests completed!\n");
    printf("Note: This test suite checks comprehensive functionality.\n");
    printf("If any tests fail, review the trim implementation.\n");

    return 0;
}
