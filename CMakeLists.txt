cmake_minimum_required(VERSION 3.14)
project(Pixel)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories(${PROJECT_SOURCE_DIR}/src/)
include_directories(${PROJECT_SOURCE_DIR}/lib/SDL2/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/SDL2/lib)

set(source_files src/main.cpp src/math/vector2.h src/graphics/generic/itexture.h src/logic/interface.h src/logic/nocopy.h src/graphics/implementation/sdl2/sdl2texture.cpp src/graphics/implementation/sdl2/sdl2texture.h src/graphics/generic/irenderer.h src/graphics/implementation/sdl2/sdl2renderer.cpp src/graphics/implementation/sdl2/sdl2renderer.h src/graphics/generic/iwindow.h src/graphics/implementation/sdl2/sdl2window.cpp src/graphics/implementation/sdl2/sdl2window.h)

add_executable(Pixel  ${source_files})
target_link_libraries(Pixel SDL2main SDL2)