CXX ?= g++

# path #
SRC_PATH = src
BUILD_PATH = build
BIN_PATH = $(BUILD_PATH)/bin
TESTS_PATH = tests

# executable #
BIN_NAME = SFML_App

# extensions #
SRC_EXT = cpp

# code lists #
# Find all source files in the source directory, sorted by
# most recently modified
SOURCES = $(shell find $(SRC_PATH) -name '*.$(SRC_EXT)' | sort -k 1nr | cut -f2-)
# Set the object file names, with the source directory stripped
# from the path, and the build path prepended in its place
OBJECTS = $(SOURCES:$(SRC_PATH)/%.$(SRC_EXT)=$(BUILD_PATH)/%.o)
# Set the dependency files that will be used to add header dependencies
DEPS = $(OBJECTS:.o=.d)

# flags #
OPTIMIZE = -O03
DEBUG = -g -D BACKTRACKING_PLAYER
COMPILE_FLAGS = -std=c++11 -Wall -Wextra
#COMPILE_FLAGS = -std=c++11 -Wall -Wextra -g
INCLUDES = -I include/
#INCLUDES = -I include/ -I /usr/local/include
# Space-separated pkg-config libraries used by this project
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: default_target debug release dirs clean all
default_target: release

debug: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS) $(DEBUG)
debug: dirs
	@$(MAKE) all

release: export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS) $(OPTIMIZE)
release: dirs
	@$(MAKE) all

dirs:
	@echo "Creating directories"
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BIN_PATH)

clean:
	@echo "Deleting $(BIN_NAME) symlink"
	@$(RM) $(BIN_NAME)
	@echo "Deleting directories"
	@$(RM) -r $(BUILD_PATH)
	@$(RM) -r $(BIN_PATH)

# checks the executable to the output
all: $(BIN_PATH)/$(BIN_NAME)
	
# Creation of the executable
$(BIN_PATH)/$(BIN_NAME): $(OBJECTS)
	@echo "Linking: $@"
	$(CXX) $(OBJECTS) -o $@ $(LIBS)

# Add dependency files, if they exist
-include $(DEPS)

# Source file rules
# After the first compilation they will be joined with the rules from the
# dependency files to provide header dependencies
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.$(SRC_EXT)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

run:
	./$(BIN_PATH)/$(BIN_NAME)
