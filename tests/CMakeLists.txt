cmake_minimum_required(VERSION 3.14)

# Project cho test
project(BankingCoreTests)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# Với MSVC cần static runtime cho gtest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Executable test duy nhất, gom tất cả test file
add_executable(BankingCoreTests
    test_main.cpp
    test_business.cpp
    test_data.cpp
)

# Link với gtest và lib core
target_link_libraries(BankingCoreTests
    PRIVATE
        gtest_main
        BankingCore_lib
)

# Đặt file exe ra folder release ở project root
set_target_properties(BankingCoreTests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/release
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/release
)

# Tự động discover test
include(GoogleTest)
gtest_discover_tests(BankingCoreTests)
