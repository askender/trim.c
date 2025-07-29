CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = test
EXAMPLE = example
SOURCES = trim.c test.c
EXAMPLE_SOURCES = trim.c example.c

all: $(TARGET) $(EXAMPLE)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

$(EXAMPLE): $(EXAMPLE_SOURCES)
	$(CC) $(CFLAGS) -o $(EXAMPLE) $(EXAMPLE_SOURCES)

run: $(TARGET)
	./$(TARGET)

run-example: $(EXAMPLE)
	./$(EXAMPLE)

clean:
	rm -f $(TARGET) $(EXAMPLE)

fmt:
	find . -regex '.*\.\(c\|h\)' -exec clang-format -i -style=file {} \;

.PHONY: all run run-example clean fmt
