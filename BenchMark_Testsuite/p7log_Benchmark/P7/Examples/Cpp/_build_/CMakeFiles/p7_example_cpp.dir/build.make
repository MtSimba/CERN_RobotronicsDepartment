# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/_build_

# Include any dependencies generated for this target.
include CMakeFiles/p7_example_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p7_example_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p7_example_cpp.dir/flags.make

CMakeFiles/p7_example_cpp.dir/Main.cpp.o: CMakeFiles/p7_example_cpp.dir/flags.make
CMakeFiles/p7_example_cpp.dir/Main.cpp.o: ../Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/_build_/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p7_example_cpp.dir/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p7_example_cpp.dir/Main.cpp.o -c /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/Main.cpp

CMakeFiles/p7_example_cpp.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p7_example_cpp.dir/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/Main.cpp > CMakeFiles/p7_example_cpp.dir/Main.cpp.i

CMakeFiles/p7_example_cpp.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p7_example_cpp.dir/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/Main.cpp -o CMakeFiles/p7_example_cpp.dir/Main.cpp.s

CMakeFiles/p7_example_cpp.dir/Main.cpp.o.requires:

.PHONY : CMakeFiles/p7_example_cpp.dir/Main.cpp.o.requires

CMakeFiles/p7_example_cpp.dir/Main.cpp.o.provides: CMakeFiles/p7_example_cpp.dir/Main.cpp.o.requires
	$(MAKE) -f CMakeFiles/p7_example_cpp.dir/build.make CMakeFiles/p7_example_cpp.dir/Main.cpp.o.provides.build
.PHONY : CMakeFiles/p7_example_cpp.dir/Main.cpp.o.provides

CMakeFiles/p7_example_cpp.dir/Main.cpp.o.provides.build: CMakeFiles/p7_example_cpp.dir/Main.cpp.o


# Object files for target p7_example_cpp
p7_example_cpp_OBJECTS = \
"CMakeFiles/p7_example_cpp.dir/Main.cpp.o"

# External object files for target p7_example_cpp
p7_example_cpp_EXTERNAL_OBJECTS =

p7_example_cpp: CMakeFiles/p7_example_cpp.dir/Main.cpp.o
p7_example_cpp: CMakeFiles/p7_example_cpp.dir/build.make
p7_example_cpp: CMakeFiles/p7_example_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/_build_/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable p7_example_cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p7_example_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p7_example_cpp.dir/build: p7_example_cpp

.PHONY : CMakeFiles/p7_example_cpp.dir/build

CMakeFiles/p7_example_cpp.dir/requires: CMakeFiles/p7_example_cpp.dir/Main.cpp.o.requires

.PHONY : CMakeFiles/p7_example_cpp.dir/requires

CMakeFiles/p7_example_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p7_example_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p7_example_cpp.dir/clean

CMakeFiles/p7_example_cpp.dir/depend:
	cd /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/_build_ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/_build_ /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/_build_ /home/robotronics/Desktop/Repository/research/BenchMark_Testsuite/p7log_Benchmark/P7/Examples/Cpp/_build_/CMakeFiles/p7_example_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p7_example_cpp.dir/depend
