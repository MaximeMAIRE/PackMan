cmake_minimum_required(VERSION 3.7)

project(PacMan LANGUAGES CXX)


find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME} "" Pack.cpp Map.cpp Person.cpp Game.cpp Ghost.cpp )
target_sources(${PROJECT_NAME} PRIVATE pacman.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_compile_definitions(${PROJECT_NAME} PRIVATE "SDL_MAIN_HANDLED")
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/pacman_sprites.bmp
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)	

IF (MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
ENDIF()
