# Trim

A lightweight, efficient C library for trimming whitespace from strings in-place.

## Features

- **In-place trimming**: Modifies the original string without allocating new memory
- **Comprehensive whitespace handling**: Removes spaces, tabs, newlines, carriage returns, form feeds, and vertical tabs
- **Safe**: Includes NULL pointer checking and proper error handling
- **Fast**: Single-pass algorithm with minimal memory operations
- **Standard compliant**: Uses standard C library functions only

## Installation

### Using clib

```bash
$ clib install vendethiel/trim.c
```

### Manual Installation

1. Copy `trim.c` and `trim.h` to your project
2. Include `trim.h` in your source files
3. Compile `trim.c` with your project

## API Reference

### `char *trim(char *str)`

Trims leading and trailing whitespace from a string in-place.

**Parameters:**
- `str`: Pointer to the null-terminated string to trim. Must not be NULL.

**Returns:**
- Pointer to the trimmed string (same as input parameter)
- `NULL` if the input is `NULL`

**Whitespace characters removed:**
- Space (`' '`)
- Tab (`'\t'`)
- Newline (`'\n'`)
- Carriage return (`'\r'`)
- Form feed (`'\f'`)
- Vertical tab (`'\v'`)

**Important notes:**
- The function modifies the original string
- The input string must be mutable (not a string literal)
- Internal whitespace is preserved
- The function is safe with NULL input

## Examples

### Basic Usage

```c
#include "trim.h"
#include <stdio.h>

int main(void) {
    char str[] = "  hello world  ";
    printf("Before: '%s'\n", str);    // "  hello world  "
    trim(str);
    printf("After:  '%s'\n", str);    // "hello world"
    return 0;
}
```

### Various Whitespace Types

```c
char str1[] = "\t\n  example  \n\t";
trim(str1);  // Result: "example"

char str2[] = "   only spaces   ";
trim(str2);  // Result: "only spaces"

char str3[] = "no_spaces";
trim(str3);  // Result: "no_spaces" (unchanged)
```

### Edge Cases

```c
char empty[] = "";
trim(empty);  // Result: "" (unchanged)

char spaces[] = "   ";
trim(spaces);  // Result: "" (empty string)

char *null_ptr = NULL;
char *result = trim(null_ptr);  // Result: NULL
```

### Chaining Operations

```c
char str[] = "  example  ";
printf("Trimmed: '%s'\n", trim(str));  // Uses return value directly
```

## Building and Testing

### Build Test Suite

```bash
make test
make run
```

### Build Examples

```bash
make example
make run-example
```

### Clean Build Files

```bash
make clean
```

### Format Code

```bash
make fmt
```

## Performance Characteristics

- **Time Complexity**: O(n) where n is the string length
- **Space Complexity**: O(1) - no additional memory allocation
- **Memory Operations**: Minimal - only one `memmove` operation when necessary

## Thread Safety

The `trim` function is thread-safe as long as different threads operate on different strings. It is not safe for multiple threads to call `trim` on the same string simultaneously.

## Error Handling

- **NULL input**: Returns `NULL` safely without crashing
- **Empty string**: Returns the same empty string
- **Whitespace-only string**: Results in an empty string
- **No whitespace**: Returns the original string unchanged

## Compatibility

- **C Standard**: C99 and later
- **Dependencies**: Standard C library only (`ctype.h`, `string.h`)
- **Platforms**: Cross-platform (Windows, Linux, macOS, embedded systems)

## Common Use Cases

- Processing user input from forms or command line
- Cleaning data read from files
- Preprocessing strings before parsing
- Normalizing configuration values
- Preparing strings for comparison

## License

MIT License - see the license file for details.

## Contributing

Contributions are welcome! Please ensure:
- Code follows the existing style (use `make fmt`)
- All tests pass (`make run`)
- New features include appropriate tests
- Documentation is updated for API changes

## Changelog

### v0.0.1
- Initial release
- Basic trim functionality
- Comprehensive test suite
- Full documentation