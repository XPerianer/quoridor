cmake_minimum_required (VERSION 3.16)
project(quoridoraner)

set(CMAKE_CXX_STANDARD 20)

##### BUILD TYPES #####
set(ALLOWED_BUILD_TYPES Asan Tsan Debug Release RelWithDebInfo MinSizeRel)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${ALLOWED_BUILD_TYPES}")

if(CMAKE_BUILD_TYPE AND NOT CMAKE_BUILD_TYPE IN_LIST ALLOWED_BUILD_TYPES)
  message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}. Allowed types: ${ALLOWED_BUILD_TYPES}")
endif()

set(CMAKE_CXX_FLAGS_ASAN "-Og -g -fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined" CACHE STRING "" FORCE)
set(CMAKE_EXE_LINKER_FLAGS_ASAN "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} -fsanitize=address -fsanitize=undefined" CACHE STRING "" FORCE)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3 -D_GLIBCXX_ASSERTIONS" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O3 -g3 -DNDEBUG" CACHE STRING "" FORCE)


##### COMPILE COMMANDS #####
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


##### INCLUDE DIRECTORIES #####
include_directories(SYSTEM)
include_directories(include)


##### COMPILER WARNINGS #####
set(COMPILER_WARNING_FLAGS "-Wall" "-Wextra" "-Werror" "-Wpedantic" "-Wextra-semi" "-Wnon-virtual-dtor" "-Wunused")
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # Additional checks not supported by GCC -- some are supported on GCC, but not ignorable / not filterable
  list(APPEND COMPILER_WARNING_FLAGS "-Wdocumentation" "-Wconditional-uninitialized" "-Wmissing-prototypes" "-Wundef"
    "-Wunused-exception-parameter" "-Wunused-member-function" "-Wshadow-all")
  list(APPEND COMPILER_WARNING_FLAGS "-Wno-gnu-zero-variadic-macro-arguments") # legal in c++20
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
  list(APPEND COMPILER_WARNING_FLAGS "-Wno-return-type") # https://gcc.gnu.org/bugzilla/show_bug.cgi?id=87950
endif()


##### EXECUTABLES #####
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(main ${SRC_FILES})
target_compile_options(main PRIVATE ${COMPILER_WARNING_FLAGS})

enable_testing()

add_subdirectory(tests)


##### FORMATTING AND LINTING ####
file(GLOB_RECURSE ALL_HEADER_FILES include/*.hpp tests/*.hpp)
file(GLOB_RECURSE ALL_CPP_FILES src/*.cpp tests/*.cpp)
list(APPEND ALL_SOURCE_FILES ${ALL_HEADER_FILES} ${ALL_CPP_FILES})

add_custom_target(clang-format COMMAND clang-format -style=file -i ${ALL_SOURCE_FILES})
add_custom_target(clang-format-check COMMAND clang-format -style=file --dry-run --Werror ${ALL_SOURCE_FILES})

add_custom_target(clang-tidy COMMAND run-clang-tidy -quiet ${ALL_CPP_FILES})

add_custom_target(tidy DEPENDS clang-tidy)
add_custom_target(format DEPENDS clang-format)
