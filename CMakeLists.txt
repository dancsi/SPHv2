cmake_minimum_required(VERSION 3.3)
project(SPHv2)

if(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    add_compile_options(/EHsc)
elseif(CMAKE_CXX_COMPILER_ID MATCHES GNU OR CMAKE_CXX_COMPILER_ID MATCHES Clang)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif()

include_directories(src)
include_directories(external)

set(Boost_ADDITIONAL_VERSIONS 1.59.0 1.60.0)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS iostreams filesystem program_options)
add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_subdirectory(external/glfw-3.1.2)
include_directories(external/glfw-3.1.2/include)
link_libraries(glfw ${GLFW_LIBRARIES})

set(SOURCE_FILES
    src/FileFrontend.h
    src/Frontend.h
    src/graphics/ASCIIArtFrontend.h
    src/graphics/GraphicalFrontend.h
    src/graphics/OpenGLFrontend.h
    src/graphics/OpenGLFrontend/Init.cpp
    src/graphics/OpenGLFrontend/Renderer.cpp
    src/main.cpp
    src/math/Line.h
    src/math/Vec2.h
    src/Particle.h
    src/Simulation.cpp
    src/Simulation.h
    src/Wall.h
    src/SimulationParameters.h
    src/SimulationParameters.cpp)

set(EXTERNAL_SOURCES
    external/glad/glad.c)

add_executable(SPHv2 ${SOURCE_FILES} ${EXTERNAL_SOURCES})
target_link_libraries(SPHv2 ${Boost_LIBRARIES})