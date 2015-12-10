project(Game)
cmake_minimum_required(VERSION 2.8)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)


set(game_VERSION_MAJOR 0)
set(game_VERSION_MINOR 1)
set(game_DEFAULT_WIDTH 800)
set(game_DEFAULT_HEIGHT 600)
set(game_DEFAULT_BPP 32)
set(game_DEFAULT_FRAMELIMIT -1)

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)
include_directories("${PROJECT_BINARY_DIR}")
aux_source_directory(. SRC_LIST)
aux_source_directory(./scenes SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST} MainEngine.cpp MainEngine.h scenes/ptDaveScene.cpp scenes/ptDaveScene.h scenes/MainMenu.cpp scenes/MainMenu.h scenes/GameScene.cpp scenes/GameScene.h Objects/Character.cpp Objects/Character.h)

set(Assets
	${PROJECT_SOURCE_DIR}/assets/arial.ttf
	${PROJECT_SOURCE_DIR}/assets/particle.png
	${PROJECT_SOURCE_DIR}/assets/ptdave.png
	${PROJECT_SOURCE_DIR}/assets/spaceship.png
)
foreach(f ${Assets})
	get_filename_component(fname ${f} NAME)
	configure_file("${f}" "${CMAKE_BINARY_DIR}/assets/${fname}" COPYONLY)
endforeach()
# Define sources and executable
set(EXECUTABLE_NAME ${PROJECT_NAME})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()


list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)
