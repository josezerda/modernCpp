cmake_minimum_required(VERSION 3.16)

project(MyCppProject
  VERSION 1.0
  LANGUAGES CXX
)

# Require C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define source and include directories
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

# Create a library target for reusable code
add_library(math_utils
  ${SRC_DIR}/math_utils.cpp
)

target_include_directories(math_utils
  PUBLIC ${INCLUDE_DIR}
)

# Create the main executable
add_executable(MyCppApp
  ${SRC_DIR}/main.cpp
)

target_link_libraries(MyCppApp
  PRIVATE math_utils
)

# Optional: Enable warnings for GCC/Clang/MSVC
if (MSVC)
  target_compile_options(math_utils PRIVATE /W4)
  target_compile_options(MyCppApp PRIVATE /W4)
else()
  target_compile_options(math_utils PRIVATE -Wall -Wextra -pedantic)
  target_compile_options(MyCppApp PRIVATE -Wall -Wextra -pedantic)
endif()

# (Optional) Add a simple test executable
add_executable(TestMath tests/test_math.cpp)
target_link_libraries(TestMath PRIVATE math_utils)
