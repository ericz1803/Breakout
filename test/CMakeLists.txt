#test program
add_executable(runUnitTests ball_unittest.cpp rectangle_unittest.cpp)

#add googletest
add_subdirectory("${PROJECT_SOURCE_DIR}/libs/googletest-1.8.1/googletest" build)
#find_package(GTest REQUIRED)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src)

#find SFML
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${PROJECT_SOURCE_DIR}/libs/sfml-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

#find Box2D
add_library(Box2D STATIC IMPORTED)
set_target_properties(Box2D PROPERTIES
    IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/libs/Box2D/lib/libBox2D.a"
    INTERFACE_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/libs/Box2D/include"
)

#link pthread for gtest
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

target_link_libraries(runUnitTests gtest gtest_main sfml-graphics sfml-audio breakout_lib Threads::Threads Box2D)
add_test(runUnitTests runUnitTests)