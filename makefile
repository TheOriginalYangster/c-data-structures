UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	CC = clang
else
	CC = gcc
endif

CFLAGS = -Wall -Wextra -std=c99
TARGET = main
SOURCE = main.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

debug: CFLAGS += -g
debug: $(TARGET)

info:
	@echo "Detected OS: $(UNAME_S)"
	@echo "Using compiler: $(CC)"

.PHONY: clean debug info