# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/d/Electronics/Monitor Controller/Monitor-Controller-Firmware/firmware/PGA2310"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/d/Electronics/Monitor Controller/Monitor-Controller-Firmware/firmware/PGA2310/build"

# Utility rule file for Monitor-Control-Firmware_PGA2310_pio_h.

# Include any custom commands dependencies for this target.
include CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/progress.make

CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h: PGA2310.pio.h

PGA2310.pio.h: ../PGA2310.pio
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="/mnt/d/Electronics/Monitor Controller/Monitor-Controller-Firmware/firmware/PGA2310/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Generating PGA2310.pio.h"
	pioasm/pioasm -o c-sdk /mnt/d/Electronics/Monitor\ Controller/Monitor-Controller-Firmware/firmware/PGA2310/PGA2310.pio /mnt/d/Electronics/Monitor\ Controller/Monitor-Controller-Firmware/firmware/PGA2310/build/PGA2310.pio.h

Monitor-Control-Firmware_PGA2310_pio_h: CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h
Monitor-Control-Firmware_PGA2310_pio_h: PGA2310.pio.h
Monitor-Control-Firmware_PGA2310_pio_h: CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/build.make
.PHONY : Monitor-Control-Firmware_PGA2310_pio_h

# Rule to build all files generated by this target.
CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/build: Monitor-Control-Firmware_PGA2310_pio_h
.PHONY : CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/build

CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/clean

CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/depend:
	cd "/mnt/d/Electronics/Monitor Controller/Monitor-Controller-Firmware/firmware/PGA2310/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/d/Electronics/Monitor Controller/Monitor-Controller-Firmware/firmware/PGA2310" "/mnt/d/Electronics/Monitor Controller/Monitor-Controller-Firmware/firmware/PGA2310" "/mnt/d/Electronics/Monitor Controller/Monitor-Controller-Firmware/firmware/PGA2310/build" "/mnt/d/Electronics/Monitor Controller/Monitor-Controller-Firmware/firmware/PGA2310/build" "/mnt/d/Electronics/Monitor Controller/Monitor-Controller-Firmware/firmware/PGA2310/build/CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Monitor-Control-Firmware_PGA2310_pio_h.dir/depend
