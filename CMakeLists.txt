# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (
	"42piscine-c07"
	VERSION 0.1.0
)

set(HEADER_FILES "c07/c07.h") 
set(
	SOURCE_FILES
	"c07/ft_strdup.c"
	"c07/ft_range.c"
	"c07/ft_ultimate_range.c"
	"c07/ft_strjoin.c"
)

# Include C07 project as library
# set the output destination
set(C07_LIB "${42piscine-c07_SOURCE_DIR}/c07/libc07.a")
# and will run each time you type make
add_custom_target(build_c07 ALL
					COMMAND ${CMAKE_MAKE_PROGRAM} all
					WORKING_DIRECTORY ${42piscine-c07_SOURCE_DIR}/c07
					COMMENT "Original C07 Makefile target")

# now create an imported static target
add_library(c07 STATIC ${HEADER_FILES} ${SOURCE_FILES})
# Import target "c07" for configuration ""
set_property(TARGET c07 APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(c07 PROPERTIES IMPORTED_LOCATION_NOCONFIG "${C07_LIB}")

# now you can use c07 as if it were a regular cmake built target in your project
add_dependencies(c07 build_c07)

# Include sub-projects
add_subdirectory("deps/cunits42")
add_subdirectory("tests")

# IDE tree view
source_group(
	"Header_Files"
	FILES ${HEADER_FILES}
)

source_group(
	"Source_Files"
	FILES ${SOURCE_FILES}
)
