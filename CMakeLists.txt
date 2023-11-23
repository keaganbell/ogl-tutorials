cmake_minimum_required(VERSION 3.22.1)

project(ogl_tutorial)

find_library(GLEW GLEW REQUIRED)
find_library(GLUT glut REQUIRED)
find_library(OpenGL OpenGL REQUIRED)
find_library(SPDLOG spdlog REQUIRED)
find_library(FMT fmt REQUIRED)

if (${GLEW} STREQUAL GLEW-NOTFOUND)
    message(FATAL_ERROR "REQUIRED Dependency glew -  Missing!")
else()
    message(STATUS "${GLEW} - Found!")
endif()

if (${GLUT} STREQUAL GLUT-NOTFOUND)
    message(FATAL_ERROR "REQUIRED Dependency glut - Missing!")
else()
    message(STATUS "${GLUT} - Found!")
endif()

if (${OpenGL} STREQUAL OpenGL-NOTFOUND)
    message(FATAL_ERROR "REQUIRED Dependency OpenGL - Missing!")
else()
    message(STATUS "${OpenGL} - Found!")
endif()

if (${SPDLOG} STREQUAL SPDLOG-NOTFOUND)
    message(FATAL_ERROR "REQUIRED Dependency spdlog - Missing!")
else()
    message(STATUS "${SPDLOG} - Found!")
endif()

if (${FMT} STREQUAL FMT-NOTFOUND)
    message(FATAL_ERROR "REQUIRED Dependency fmt - Missing!")
else()
    message(STATUS "${FMT} - Found!")
endif()

set(GLUT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/vendor/glut-3.7/include/GL)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${GLUT_INCLUDE_DIR})

file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(ogl_tutorial ${SOURCES})
target_link_libraries(ogl_tutorial ${GLUT} ${OpenGL} ${GLEW} ${SPDLOG} ${FMT})
