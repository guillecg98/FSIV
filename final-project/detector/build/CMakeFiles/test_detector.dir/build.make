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
CMAKE_SOURCE_DIR = /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/build

# Include any dependencies generated for this target.
include CMakeFiles/test_detector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_detector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_detector.dir/flags.make

CMakeFiles/test_detector.dir/test_detector.cpp.o: CMakeFiles/test_detector.dir/flags.make
CMakeFiles/test_detector.dir/test_detector.cpp.o: ../test_detector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_detector.dir/test_detector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_detector.dir/test_detector.cpp.o -c /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/test_detector.cpp

CMakeFiles/test_detector.dir/test_detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_detector.dir/test_detector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/test_detector.cpp > CMakeFiles/test_detector.dir/test_detector.cpp.i

CMakeFiles/test_detector.dir/test_detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_detector.dir/test_detector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/test_detector.cpp -o CMakeFiles/test_detector.dir/test_detector.cpp.s

CMakeFiles/test_detector.dir/test_detector.cpp.o.requires:

.PHONY : CMakeFiles/test_detector.dir/test_detector.cpp.o.requires

CMakeFiles/test_detector.dir/test_detector.cpp.o.provides: CMakeFiles/test_detector.dir/test_detector.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_detector.dir/build.make CMakeFiles/test_detector.dir/test_detector.cpp.o.provides.build
.PHONY : CMakeFiles/test_detector.dir/test_detector.cpp.o.provides

CMakeFiles/test_detector.dir/test_detector.cpp.o.provides.build: CMakeFiles/test_detector.dir/test_detector.cpp.o


CMakeFiles/test_detector.dir/common_code.cpp.o: CMakeFiles/test_detector.dir/flags.make
CMakeFiles/test_detector.dir/common_code.cpp.o: ../common_code.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_detector.dir/common_code.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_detector.dir/common_code.cpp.o -c /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/common_code.cpp

CMakeFiles/test_detector.dir/common_code.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_detector.dir/common_code.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/common_code.cpp > CMakeFiles/test_detector.dir/common_code.cpp.i

CMakeFiles/test_detector.dir/common_code.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_detector.dir/common_code.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/common_code.cpp -o CMakeFiles/test_detector.dir/common_code.cpp.s

CMakeFiles/test_detector.dir/common_code.cpp.o.requires:

.PHONY : CMakeFiles/test_detector.dir/common_code.cpp.o.requires

CMakeFiles/test_detector.dir/common_code.cpp.o.provides: CMakeFiles/test_detector.dir/common_code.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_detector.dir/build.make CMakeFiles/test_detector.dir/common_code.cpp.o.provides.build
.PHONY : CMakeFiles/test_detector.dir/common_code.cpp.o.provides

CMakeFiles/test_detector.dir/common_code.cpp.o.provides.build: CMakeFiles/test_detector.dir/common_code.cpp.o


CMakeFiles/test_detector.dir/lbp.cpp.o: CMakeFiles/test_detector.dir/flags.make
CMakeFiles/test_detector.dir/lbp.cpp.o: ../lbp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/test_detector.dir/lbp.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_detector.dir/lbp.cpp.o -c /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/lbp.cpp

CMakeFiles/test_detector.dir/lbp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_detector.dir/lbp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/lbp.cpp > CMakeFiles/test_detector.dir/lbp.cpp.i

CMakeFiles/test_detector.dir/lbp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_detector.dir/lbp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/lbp.cpp -o CMakeFiles/test_detector.dir/lbp.cpp.s

CMakeFiles/test_detector.dir/lbp.cpp.o.requires:

.PHONY : CMakeFiles/test_detector.dir/lbp.cpp.o.requires

CMakeFiles/test_detector.dir/lbp.cpp.o.provides: CMakeFiles/test_detector.dir/lbp.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_detector.dir/build.make CMakeFiles/test_detector.dir/lbp.cpp.o.provides.build
.PHONY : CMakeFiles/test_detector.dir/lbp.cpp.o.provides

CMakeFiles/test_detector.dir/lbp.cpp.o.provides.build: CMakeFiles/test_detector.dir/lbp.cpp.o


# Object files for target test_detector
test_detector_OBJECTS = \
"CMakeFiles/test_detector.dir/test_detector.cpp.o" \
"CMakeFiles/test_detector.dir/common_code.cpp.o" \
"CMakeFiles/test_detector.dir/lbp.cpp.o"

# External object files for target test_detector
test_detector_EXTERNAL_OBJECTS =

test_detector: CMakeFiles/test_detector.dir/test_detector.cpp.o
test_detector: CMakeFiles/test_detector.dir/common_code.cpp.o
test_detector: CMakeFiles/test_detector.dir/lbp.cpp.o
test_detector: CMakeFiles/test_detector.dir/build.make
test_detector: /usr/local/lib/libopencv_dnn.so.3.4.7
test_detector: /usr/local/lib/libopencv_highgui.so.3.4.7
test_detector: /usr/local/lib/libopencv_ml.so.3.4.7
test_detector: /usr/local/lib/libopencv_objdetect.so.3.4.7
test_detector: /usr/local/lib/libopencv_shape.so.3.4.7
test_detector: /usr/local/lib/libopencv_stitching.so.3.4.7
test_detector: /usr/local/lib/libopencv_superres.so.3.4.7
test_detector: /usr/local/lib/libopencv_videostab.so.3.4.7
test_detector: /usr/local/lib/libopencv_calib3d.so.3.4.7
test_detector: /usr/local/lib/libopencv_features2d.so.3.4.7
test_detector: /usr/local/lib/libopencv_flann.so.3.4.7
test_detector: /usr/local/lib/libopencv_photo.so.3.4.7
test_detector: /usr/local/lib/libopencv_video.so.3.4.7
test_detector: /usr/local/lib/libopencv_videoio.so.3.4.7
test_detector: /usr/local/lib/libopencv_imgcodecs.so.3.4.7
test_detector: /usr/local/lib/libopencv_imgproc.so.3.4.7
test_detector: /usr/local/lib/libopencv_core.so.3.4.7
test_detector: CMakeFiles/test_detector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable test_detector"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_detector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_detector.dir/build: test_detector

.PHONY : CMakeFiles/test_detector.dir/build

CMakeFiles/test_detector.dir/requires: CMakeFiles/test_detector.dir/test_detector.cpp.o.requires
CMakeFiles/test_detector.dir/requires: CMakeFiles/test_detector.dir/common_code.cpp.o.requires
CMakeFiles/test_detector.dir/requires: CMakeFiles/test_detector.dir/lbp.cpp.o.requires

.PHONY : CMakeFiles/test_detector.dir/requires

CMakeFiles/test_detector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_detector.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_detector.dir/clean

CMakeFiles/test_detector.dir/depend:
	cd /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/build /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/build /home/gecoga98/Desktop/4º/FSIV/practicas/final-project/detector/build/CMakeFiles/test_detector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_detector.dir/depend

