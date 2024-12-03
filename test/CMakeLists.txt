CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(MachineLearning)
ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(runAllTests
    test.cpp
)

target_link_libraries(runAllTests gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)


ADD_EXECUTABLE(features
    ../src/main.cpp
    ../src/Evaluation.cpp
)
