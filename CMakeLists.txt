cmake_minimum_required(VERSION 3.16)

project(MyCppProject
  VERSION 1.0
  LANGUAGES CXX
)

# =========================================
# C++ standard
# =========================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source directories
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

# =========================================
# Library: math_utils
# =========================================
add_library(math_utils
  ${SRC_DIR}/math_utils.cpp
)
target_include_directories(math_utils PUBLIC ${INCLUDE_DIR})

# Strict warnings for GCC/Clang
target_compile_options(math_utils PRIVATE -Wall -Wextra -pedantic)

# =========================================
# Executable: MyCppApp
# =========================================
add_executable(MyCppApp
  ${SRC_DIR}/main.cpp
)
target_link_libraries(MyCppApp PRIVATE math_utils)

target_compile_options(MyCppApp PRIVATE -Wall -Wextra -pedantic)

# =========================================
# GoogleTest + Testing
# =========================================
include(CTest)   # Provides BUILD_TESTING option (ON by default)

if (BUILD_TESTING)
  include(FetchContent)

  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
  )

  FetchContent_MakeAvailable(googletest)
  enable_testing()

  add_executable(TestMath tests/test_math.cpp)
  target_link_libraries(TestMath
    PRIVATE
      math_utils
      GTest::gtest_main
  )

  target_compile_options(TestMath PRIVATE -Wall -Wextra -pedantic)

  include(GoogleTest)
  gtest_discover_tests(TestMath)
endif()
