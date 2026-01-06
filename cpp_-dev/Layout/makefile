# Target name
TARGET = layout

# Debug switch: 1 for debug (-g), 0 for release (-O2)
DEBUG = 1

# Build directory
BUILD_DIR = build

# Directories
CXX_HEADERS = ./include
CXX_SOURCES = ./src

# Sources and objects
SRCS := $(wildcard $(CXX_SOURCES)/*.cpp)
OBJS := $(patsubst $(CXX_SOURCES)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Compiler and flags
CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++17 -pedantic-errors -Wconversion -Weffc++ -Werror -Wsign-conversion -I$(CXX_HEADERS) \
		   -isystem /usr/include/c++/$(shell $(CXX) -dumpversion) \
		   -isystem /usr/lib/gcc/x86_64-pc-linux-gnu/$(shell $(CXX) -dumpversion)/include

ifeq ($(DEBUG), 1)
	CXXFLAGS += -ggdb
else
	CXXFLAGS += -O2
endif

# Build rules
all: $(BUILD_DIR) $(TARGET)
	@echo "---Build complete---"

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@
	@echo "Linked: $@ ---"

$(BUILD_DIR)/%.o: $(CXX_SOURCES)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled: $< ---"

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

.PHONY: all clean

