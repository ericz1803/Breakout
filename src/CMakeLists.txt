#find sfml
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${PROJECT_SOURCE_DIR}/libs/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

#find Box2D
add_library(Box2D STATIC IMPORTED)
set_target_properties(Box2D PROPERTIES
    IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/libs/Box2D/lib/libBox2D.a"
    INTERFACE_INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}/libs/Box2D/include"
)

#make non-main files a library
add_library(breakout_lib STATIC ball.cpp edge.cpp main.cpp rectangle.cpp paddle.cpp world.cpp)
target_link_libraries(breakout_lib sfml-graphics sfml-audio Box2D)
target_include_directories(breakout_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#actual program
add_executable(breakout_exec main.cpp)

target_link_libraries(breakout_exec sfml-graphics sfml-audio breakout_lib Box2D)