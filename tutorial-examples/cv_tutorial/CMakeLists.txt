CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(cv_tutorial)
FIND_PACKAGE(OpenCV 	REQUIRED )
include_directories ("${OpenCV_INCLUDE_DIRS}")
#Required for uco thinstation. May not be required in your own pc
OPTION(THINSTATION	"Set to OFF at home" OFF)

IF(THINSTATION)
  SET(CMAKE_CXX_FLAGS " -D_GLIBCXX_USE_CXX11_ABI=0 -m32")
  SET(XRAND Xrandr)
  link_directories(/usr/local/X11R7/lib)
  MESSAGE( STATUS "USING THINSTATION OPTIONS" )
ENDIF()

LINK_LIBRARIES(${OpenCV_LIBS} ${XRAND})

add_executable(prg1 prg1.cpp)
add_executable(prg2 prg2.cpp)
add_executable(prg3 prg3.cpp)
add_executable(prg4 prg4.cpp)
add_executable(prg5 prg5.cpp)
add_executable(p1 p1.cpp)
