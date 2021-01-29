
#conan_cmake_run(REQUIRES

                # Libraries to be installed locally
                #                gtest/1.8.1@bincrafters/stable

                #                BASIC_SETUP
                #                BUILD missing
                #                )

#========== Find Packages =====================#
#find_package(GTest REQUIRED)
#include(GoogleTest)
#add_executable(tests creational/Builder.cpp creational/FluentBuilder.cpp creational/GroovyBuilder.cpp
#                     ../src/creational/Builder.h ../src/creational/FluentBuilder.h ../src/creational/GroovyBuilder.h)

#add_executable(tests ${SOURCES})
#target_link_libraries(tests GTest::GTest GTest::Main -lpthread)
#gtest_discover_tests(tests)

enable_testing()
find_package(GTest REQUIRED)

set(BINARY ${CMAKE_PROJECT_NAME}_tst)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib GTest::GTest GTest::Main)
