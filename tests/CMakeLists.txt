# tests/CMakeList.txt : CMake project for tests-c07, include source and define
# project specific logic here.
#

set(RUN_EXAMPLE OFF)
set(
	SOURCE_FILES
	"test_main.c"
	"test_ft_strdup.c"
	"test_ft_range.c"
	"test_ft_ultimate_range.c"
	"test_ft_strjoin.c"
)
set (HEADER_FILES "tests.h")
add_executable(tests ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(tests PRIVATE cunits42 c07)
target_include_directories(
	tests
	PUBLIC
	"${42piscine-c07_SOURCE_DIR}/c07"
)

# IDE tree view
source_group(
	"Header_Files"
	FILES ${HEADER_FILES}
)

source_group(
	"Source_Files"
	FILES ${SOURCE_FILES}
)
