# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\fedor\CLionProjects\Aisd152

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\fedor\CLionProjects\Aisd152\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Aisd152.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Aisd152.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Aisd152.dir/flags.make

CMakeFiles/Aisd152.dir/main.cpp.obj: CMakeFiles/Aisd152.dir/flags.make
CMakeFiles/Aisd152.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fedor\CLionProjects\Aisd152\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Aisd152.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Aisd152.dir\main.cpp.obj -c C:\Users\fedor\CLionProjects\Aisd152\main.cpp

CMakeFiles/Aisd152.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Aisd152.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\fedor\CLionProjects\Aisd152\main.cpp > CMakeFiles\Aisd152.dir\main.cpp.i

CMakeFiles/Aisd152.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Aisd152.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\fedor\CLionProjects\Aisd152\main.cpp -o CMakeFiles\Aisd152.dir\main.cpp.s

CMakeFiles/Aisd152.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Aisd152.dir/main.cpp.obj.requires

CMakeFiles/Aisd152.dir/main.cpp.obj.provides: CMakeFiles/Aisd152.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Aisd152.dir\build.make CMakeFiles/Aisd152.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Aisd152.dir/main.cpp.obj.provides

CMakeFiles/Aisd152.dir/main.cpp.obj.provides.build: CMakeFiles/Aisd152.dir/main.cpp.obj


# Object files for target Aisd152
Aisd152_OBJECTS = \
"CMakeFiles/Aisd152.dir/main.cpp.obj"

# External object files for target Aisd152
Aisd152_EXTERNAL_OBJECTS =

Aisd152.exe: CMakeFiles/Aisd152.dir/main.cpp.obj
Aisd152.exe: CMakeFiles/Aisd152.dir/build.make
Aisd152.exe: CMakeFiles/Aisd152.dir/linklibs.rsp
Aisd152.exe: CMakeFiles/Aisd152.dir/objects1.rsp
Aisd152.exe: CMakeFiles/Aisd152.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\fedor\CLionProjects\Aisd152\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Aisd152.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Aisd152.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Aisd152.dir/build: Aisd152.exe

.PHONY : CMakeFiles/Aisd152.dir/build

CMakeFiles/Aisd152.dir/requires: CMakeFiles/Aisd152.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Aisd152.dir/requires

CMakeFiles/Aisd152.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Aisd152.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Aisd152.dir/clean

CMakeFiles/Aisd152.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\fedor\CLionProjects\Aisd152 C:\Users\fedor\CLionProjects\Aisd152 C:\Users\fedor\CLionProjects\Aisd152\cmake-build-debug C:\Users\fedor\CLionProjects\Aisd152\cmake-build-debug C:\Users\fedor\CLionProjects\Aisd152\cmake-build-debug\CMakeFiles\Aisd152.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Aisd152.dir/depend

