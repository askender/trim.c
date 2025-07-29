CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = test
SOURCES = trim.c test.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

fmt:
	find . -regex '.*\.\(c\|h\)' -exec clang-format -i -style=file {} \;

.PHONY: all run clean fmt
