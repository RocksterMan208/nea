CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic
LDFLAGS :=
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
TARGET := nea

# Grab all .cpp files recursively
SOURCES := $(shell find $(SRC_DIR) -name "*.cpp")
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Raylib via pkg-config (Arch Linux default)
RAYLIB_CFLAGS := $(shell pkg-config --cflags raylib)
RAYLIB_LIBS := $(shell pkg-config --libs raylib)

# Include directories
INCLUDES := -I$(INCLUDE_DIR) $(RAYLIB_CFLAGS)

# Default target
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(OBJECTS) -o $@ $(RAYLIB_LIBS) $(LDFLAGS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Run
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
