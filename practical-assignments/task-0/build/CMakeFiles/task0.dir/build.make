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
CMAKE_SOURCE_DIR = /home/gecoga98/Escritorio/4º/FSIV/task-0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gecoga98/Escritorio/4º/FSIV/task-0/build

# Include any dependencies generated for this target.
include CMakeFiles/task0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/task0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/task0.dir/flags.make

CMakeFiles/task0.dir/task0.cpp.o: CMakeFiles/task0.dir/flags.make
CMakeFiles/task0.dir/task0.cpp.o: ../task0.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gecoga98/Escritorio/4º/FSIV/task-0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/task0.dir/task0.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/task0.dir/task0.cpp.o -c /home/gecoga98/Escritorio/4º/FSIV/task-0/task0.cpp

CMakeFiles/task0.dir/task0.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task0.dir/task0.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gecoga98/Escritorio/4º/FSIV/task-0/task0.cpp > CMakeFiles/task0.dir/task0.cpp.i

CMakeFiles/task0.dir/task0.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task0.dir/task0.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gecoga98/Escritorio/4º/FSIV/task-0/task0.cpp -o CMakeFiles/task0.dir/task0.cpp.s

CMakeFiles/task0.dir/task0.cpp.o.requires:

.PHONY : CMakeFiles/task0.dir/task0.cpp.o.requires

CMakeFiles/task0.dir/task0.cpp.o.provides: CMakeFiles/task0.dir/task0.cpp.o.requires
	$(MAKE) -f CMakeFiles/task0.dir/build.make CMakeFiles/task0.dir/task0.cpp.o.provides.build
.PHONY : CMakeFiles/task0.dir/task0.cpp.o.provides

CMakeFiles/task0.dir/task0.cpp.o.provides.build: CMakeFiles/task0.dir/task0.cpp.o


# Object files for target task0
task0_OBJECTS = \
"CMakeFiles/task0.dir/task0.cpp.o"

# External object files for target task0
task0_EXTERNAL_OBJECTS =

task0: CMakeFiles/task0.dir/task0.cpp.o
task0: CMakeFiles/task0.dir/build.make
task0: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
task0: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
task0: CMakeFiles/task0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gecoga98/Escritorio/4º/FSIV/task-0/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable task0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/task0.dir/build: task0

.PHONY : CMakeFiles/task0.dir/build

CMakeFiles/task0.dir/requires: CMakeFiles/task0.dir/task0.cpp.o.requires

.PHONY : CMakeFiles/task0.dir/requires

CMakeFiles/task0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/task0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/task0.dir/clean

CMakeFiles/task0.dir/depend:
	cd /home/gecoga98/Escritorio/4º/FSIV/task-0/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gecoga98/Escritorio/4º/FSIV/task-0 /home/gecoga98/Escritorio/4º/FSIV/task-0 /home/gecoga98/Escritorio/4º/FSIV/task-0/build /home/gecoga98/Escritorio/4º/FSIV/task-0/build /home/gecoga98/Escritorio/4º/FSIV/task-0/build/CMakeFiles/task0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/task0.dir/depend
