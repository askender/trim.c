# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -O2
DEBUG_CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -g -O0 -DDEBUG
COVERAGE_CFLAGS = -Wall -Wextra -Wpedantic -std=c99 -g -O0 --coverage

# Targets
TARGET = test
EXAMPLE = example
DEBUG_TARGET = test_debug
COVERAGE_TARGET = test_coverage

# Source files
TRIM_SOURCES = trim.c
TEST_SOURCES = $(TRIM_SOURCES) test.c
EXAMPLE_SOURCES = $(TRIM_SOURCES) example.c

# Object files
TRIM_OBJS = $(TRIM_SOURCES:.c=.o)
TEST_OBJS = $(TEST_SOURCES:.c=.o)
EXAMPLE_OBJS = $(EXAMPLE_SOURCES:.c=.o)

# Default target
all: $(TARGET) $(EXAMPLE)

# Main test executable
$(TARGET): $(TEST_SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(TEST_SOURCES)

# Example executable
$(EXAMPLE): $(EXAMPLE_SOURCES)
	$(CC) $(CFLAGS) -o $(EXAMPLE) $(EXAMPLE_SOURCES)

# Debug build
debug: $(DEBUG_TARGET)
$(DEBUG_TARGET): $(TEST_SOURCES)
	$(CC) $(DEBUG_CFLAGS) -o $(DEBUG_TARGET) $(TEST_SOURCES)

# Coverage build (requires gcov)
coverage: $(COVERAGE_TARGET)
$(COVERAGE_TARGET): $(TEST_SOURCES)
	$(CC) $(COVERAGE_CFLAGS) -o $(COVERAGE_TARGET) $(TEST_SOURCES)

# Static library
libtrim.a: $(TRIM_OBJS)
	ar rcs libtrim.a $(TRIM_OBJS)

# Shared library
libtrim.so: $(TRIM_SOURCES)
	$(CC) $(CFLAGS) -fPIC -shared -o libtrim.so $(TRIM_SOURCES)

# Object file compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Run tests
run: $(TARGET)
	./$(TARGET)

# Run example
run-example: $(EXAMPLE)
	./$(EXAMPLE)

# Run debug version
run-debug: $(DEBUG_TARGET)
	./$(DEBUG_TARGET)

# Run with valgrind (memory check)
valgrind: $(DEBUG_TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(DEBUG_TARGET)

# Generate coverage report
coverage-report: $(COVERAGE_TARGET)
	./$(COVERAGE_TARGET)
	gcov $(COVERAGE_TARGET)-*.gcda
	@echo "Coverage report generated. Check *.gcov files"

# Static analysis with cppcheck (if available)
static-check:
	@if command -v cppcheck >/dev/null 2>&1; then \
		cppcheck --enable=all --std=c99 --suppress=missingIncludeSystem $(TRIM_SOURCES) $(TEST_SOURCES:.c=.c) $(EXAMPLE_SOURCES:.c=.c); \
	else \
		echo "cppcheck not found. Install it for static analysis."; \
	fi

# Format code with clang-format
fmt:
	@if command -v clang-format >/dev/null 2>&1; then \
		find . -regex '.*\.\(c\|h\)$$' -exec clang-format -i -style=file {} \; && \
		echo "Code formatted successfully."; \
	else \
		echo "clang-format not found. Install it for code formatting."; \
	fi

# Check code format without modifying files
check-fmt:
	@if command -v clang-format >/dev/null 2>&1; then \
		find . -regex '.*\.\(c\|h\)$$' -exec clang-format -style=file --dry-run --Werror {} \; && \
		echo "Code format is correct."; \
	else \
		echo "clang-format not found. Install it for format checking."; \
	fi

# Install to system (requires sudo)
install: libtrim.a
	@echo "Installing to /usr/local..."
	sudo mkdir -p /usr/local/include /usr/local/lib
	sudo cp trim.h /usr/local/include/
	sudo cp libtrim.a /usr/local/lib/
	@echo "Installation complete. Use -ltrim to link against the library."

# Uninstall from system
uninstall:
	@echo "Uninstalling from /usr/local..."
	sudo rm -f /usr/local/include/trim.h
	sudo rm -f /usr/local/lib/libtrim.a
	sudo rm -f /usr/local/lib/libtrim.so
	@echo "Uninstallation complete."

# Clean all generated files
clean:
	rm -f $(TARGET) $(EXAMPLE) $(DEBUG_TARGET) $(COVERAGE_TARGET)
	rm -f *.o *.a *.so
	rm -f *.gcno *.gcda *.gcov
	rm -f core vgcore.*

# Deep clean (including backup files)
distclean: clean
	rm -f *~ .*~
	rm -f *.orig *.rej

# Show help
help:
	@echo "Available targets:"
	@echo "  all           - Build test and example (default)"
	@echo "  test          - Build test executable"
	@echo "  example       - Build example executable"
	@echo "  debug         - Build debug version of test"
	@echo "  coverage      - Build coverage-enabled test"
	@echo "  libtrim.a     - Build static library"
	@echo "  libtrim.so    - Build shared library"
	@echo ""
	@echo "  run           - Run test executable"
	@echo "  run-example   - Run example executable"
	@echo "  run-debug     - Run debug version"
	@echo "  valgrind      - Run test with valgrind"
	@echo "  coverage-report - Generate coverage report"
	@echo ""
	@echo "  fmt           - Format code with clang-format"
	@echo "  check-fmt     - Check code format"
	@echo "  static-check  - Run static analysis"
	@echo ""
	@echo "  install       - Install library to system"
	@echo "  uninstall     - Remove library from system"
	@echo ""
	@echo "  clean         - Remove built files"
	@echo "  distclean     - Remove all generated files"
	@echo "  help          - Show this help"

# Phony targets
.PHONY: all debug coverage run run-example run-debug valgrind coverage-report
.PHONY: static-check fmt check-fmt install uninstall clean distclean help
