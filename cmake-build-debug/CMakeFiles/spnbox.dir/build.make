# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/halis/GitHub/spnbox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/halis/GitHub/spnbox/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/spnbox.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/spnbox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/spnbox.dir/flags.make

CMakeFiles/spnbox.dir/main.c.o: CMakeFiles/spnbox.dir/flags.make
CMakeFiles/spnbox.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/spnbox.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spnbox.dir/main.c.o -c /Users/halis/GitHub/spnbox/main.c

CMakeFiles/spnbox.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spnbox.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halis/GitHub/spnbox/main.c > CMakeFiles/spnbox.dir/main.c.i

CMakeFiles/spnbox.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spnbox.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halis/GitHub/spnbox/main.c -o CMakeFiles/spnbox.dir/main.c.s

CMakeFiles/spnbox.dir/src/sbox.c.o: CMakeFiles/spnbox.dir/flags.make
CMakeFiles/spnbox.dir/src/sbox.c.o: ../src/sbox.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/spnbox.dir/src/sbox.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spnbox.dir/src/sbox.c.o -c /Users/halis/GitHub/spnbox/src/sbox.c

CMakeFiles/spnbox.dir/src/sbox.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spnbox.dir/src/sbox.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halis/GitHub/spnbox/src/sbox.c > CMakeFiles/spnbox.dir/src/sbox.c.i

CMakeFiles/spnbox.dir/src/sbox.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spnbox.dir/src/sbox.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halis/GitHub/spnbox/src/sbox.c -o CMakeFiles/spnbox.dir/src/sbox.c.s

CMakeFiles/spnbox.dir/src/helper.c.o: CMakeFiles/spnbox.dir/flags.make
CMakeFiles/spnbox.dir/src/helper.c.o: ../src/helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/spnbox.dir/src/helper.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spnbox.dir/src/helper.c.o -c /Users/halis/GitHub/spnbox/src/helper.c

CMakeFiles/spnbox.dir/src/helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spnbox.dir/src/helper.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halis/GitHub/spnbox/src/helper.c > CMakeFiles/spnbox.dir/src/helper.c.i

CMakeFiles/spnbox.dir/src/helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spnbox.dir/src/helper.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halis/GitHub/spnbox/src/helper.c -o CMakeFiles/spnbox.dir/src/helper.c.s

CMakeFiles/spnbox.dir/src/spnbox.c.o: CMakeFiles/spnbox.dir/flags.make
CMakeFiles/spnbox.dir/src/spnbox.c.o: ../src/spnbox.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/spnbox.dir/src/spnbox.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spnbox.dir/src/spnbox.c.o -c /Users/halis/GitHub/spnbox/src/spnbox.c

CMakeFiles/spnbox.dir/src/spnbox.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spnbox.dir/src/spnbox.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halis/GitHub/spnbox/src/spnbox.c > CMakeFiles/spnbox.dir/src/spnbox.c.i

CMakeFiles/spnbox.dir/src/spnbox.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spnbox.dir/src/spnbox.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halis/GitHub/spnbox/src/spnbox.c -o CMakeFiles/spnbox.dir/src/spnbox.c.s

CMakeFiles/spnbox.dir/src/tableMng.c.o: CMakeFiles/spnbox.dir/flags.make
CMakeFiles/spnbox.dir/src/tableMng.c.o: ../src/tableMng.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/spnbox.dir/src/tableMng.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spnbox.dir/src/tableMng.c.o -c /Users/halis/GitHub/spnbox/src/tableMng.c

CMakeFiles/spnbox.dir/src/tableMng.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spnbox.dir/src/tableMng.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halis/GitHub/spnbox/src/tableMng.c > CMakeFiles/spnbox.dir/src/tableMng.c.i

CMakeFiles/spnbox.dir/src/tableMng.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spnbox.dir/src/tableMng.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halis/GitHub/spnbox/src/tableMng.c -o CMakeFiles/spnbox.dir/src/tableMng.c.s

CMakeFiles/spnbox.dir/src/spn/spn16.c.o: CMakeFiles/spnbox.dir/flags.make
CMakeFiles/spnbox.dir/src/spn/spn16.c.o: ../src/spn/spn16.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/spnbox.dir/src/spn/spn16.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spnbox.dir/src/spn/spn16.c.o -c /Users/halis/GitHub/spnbox/src/spn/spn16.c

CMakeFiles/spnbox.dir/src/spn/spn16.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spnbox.dir/src/spn/spn16.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halis/GitHub/spnbox/src/spn/spn16.c > CMakeFiles/spnbox.dir/src/spn/spn16.c.i

CMakeFiles/spnbox.dir/src/spn/spn16.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spnbox.dir/src/spn/spn16.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halis/GitHub/spnbox/src/spn/spn16.c -o CMakeFiles/spnbox.dir/src/spn/spn16.c.s

CMakeFiles/spnbox.dir/src/spn/spn8.c.o: CMakeFiles/spnbox.dir/flags.make
CMakeFiles/spnbox.dir/src/spn/spn8.c.o: ../src/spn/spn8.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/spnbox.dir/src/spn/spn8.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spnbox.dir/src/spn/spn8.c.o -c /Users/halis/GitHub/spnbox/src/spn/spn8.c

CMakeFiles/spnbox.dir/src/spn/spn8.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spnbox.dir/src/spn/spn8.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halis/GitHub/spnbox/src/spn/spn8.c > CMakeFiles/spnbox.dir/src/spn/spn8.c.i

CMakeFiles/spnbox.dir/src/spn/spn8.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spnbox.dir/src/spn/spn8.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halis/GitHub/spnbox/src/spn/spn8.c -o CMakeFiles/spnbox.dir/src/spn/spn8.c.s

CMakeFiles/spnbox.dir/src/spn/spn24.c.o: CMakeFiles/spnbox.dir/flags.make
CMakeFiles/spnbox.dir/src/spn/spn24.c.o: ../src/spn/spn24.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/spnbox.dir/src/spn/spn24.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spnbox.dir/src/spn/spn24.c.o -c /Users/halis/GitHub/spnbox/src/spn/spn24.c

CMakeFiles/spnbox.dir/src/spn/spn24.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spnbox.dir/src/spn/spn24.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halis/GitHub/spnbox/src/spn/spn24.c > CMakeFiles/spnbox.dir/src/spn/spn24.c.i

CMakeFiles/spnbox.dir/src/spn/spn24.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spnbox.dir/src/spn/spn24.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halis/GitHub/spnbox/src/spn/spn24.c -o CMakeFiles/spnbox.dir/src/spn/spn24.c.s

CMakeFiles/spnbox.dir/src/spn/spn32.c.o: CMakeFiles/spnbox.dir/flags.make
CMakeFiles/spnbox.dir/src/spn/spn32.c.o: ../src/spn/spn32.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/spnbox.dir/src/spn/spn32.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/spnbox.dir/src/spn/spn32.c.o -c /Users/halis/GitHub/spnbox/src/spn/spn32.c

CMakeFiles/spnbox.dir/src/spn/spn32.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/spnbox.dir/src/spn/spn32.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/halis/GitHub/spnbox/src/spn/spn32.c > CMakeFiles/spnbox.dir/src/spn/spn32.c.i

CMakeFiles/spnbox.dir/src/spn/spn32.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/spnbox.dir/src/spn/spn32.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/halis/GitHub/spnbox/src/spn/spn32.c -o CMakeFiles/spnbox.dir/src/spn/spn32.c.s

# Object files for target spnbox
spnbox_OBJECTS = \
"CMakeFiles/spnbox.dir/main.c.o" \
"CMakeFiles/spnbox.dir/src/sbox.c.o" \
"CMakeFiles/spnbox.dir/src/helper.c.o" \
"CMakeFiles/spnbox.dir/src/spnbox.c.o" \
"CMakeFiles/spnbox.dir/src/tableMng.c.o" \
"CMakeFiles/spnbox.dir/src/spn/spn16.c.o" \
"CMakeFiles/spnbox.dir/src/spn/spn8.c.o" \
"CMakeFiles/spnbox.dir/src/spn/spn24.c.o" \
"CMakeFiles/spnbox.dir/src/spn/spn32.c.o"

# External object files for target spnbox
spnbox_EXTERNAL_OBJECTS =

spnbox: CMakeFiles/spnbox.dir/main.c.o
spnbox: CMakeFiles/spnbox.dir/src/sbox.c.o
spnbox: CMakeFiles/spnbox.dir/src/helper.c.o
spnbox: CMakeFiles/spnbox.dir/src/spnbox.c.o
spnbox: CMakeFiles/spnbox.dir/src/tableMng.c.o
spnbox: CMakeFiles/spnbox.dir/src/spn/spn16.c.o
spnbox: CMakeFiles/spnbox.dir/src/spn/spn8.c.o
spnbox: CMakeFiles/spnbox.dir/src/spn/spn24.c.o
spnbox: CMakeFiles/spnbox.dir/src/spn/spn32.c.o
spnbox: CMakeFiles/spnbox.dir/build.make
spnbox: CMakeFiles/spnbox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable spnbox"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spnbox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/spnbox.dir/build: spnbox
.PHONY : CMakeFiles/spnbox.dir/build

CMakeFiles/spnbox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spnbox.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spnbox.dir/clean

CMakeFiles/spnbox.dir/depend:
	cd /Users/halis/GitHub/spnbox/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/halis/GitHub/spnbox /Users/halis/GitHub/spnbox /Users/halis/GitHub/spnbox/cmake-build-debug /Users/halis/GitHub/spnbox/cmake-build-debug /Users/halis/GitHub/spnbox/cmake-build-debug/CMakeFiles/spnbox.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spnbox.dir/depend

