# -*- CMake -*-
# ┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework
# ├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira
# ┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3
#  Copyright (c) 2016 - Luís Ferreira. All right reserved
#  More information in: https://github.com/ljmf00/ (Github Page)

# Set minimum version of cmake required to build this project
cmake_minimum_required (VERSION 2.8)
project (aurorafw)

message("┌─┐┬ ┬┬─┐┌─┐┬─┐┌─┐  ┌─┐┬─┐┌─┐┌┬┐┌─┐┬ ┬┌─┐┬─┐┬┌─ | Powerful, Scalable and Cross Platform Framework")
message("├─┤│ │├┬┘│ │├┬┘├─┤  ├┤ ├┬┘├─┤│││├┤ ││││ │├┬┘├┴┐ | @author Luís Ferreira")
message("┴ ┴└─┘┴└─└─┘┴└─┴ ┴  └  ┴└─┴ ┴┴ ┴└─┘└┴┘└─┘┴└─┴ ┴ | @license GNU Public License v3")
#message(STATUS "Aurora Framework is building...")

# Check for dependencies
find_package(PkgConfig REQUIRED)
find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenAL REQUIRED)
find_package(Vulkan)
find_package(CUDA)

pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

if (NOT CONFIGURED_ONCE)
    add_definitions(-DAURORA_IS_COMPILING)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -std=c++14")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -std=c++14")
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++14"
    #    CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(ROOT_DIR ..)
    set(SOURCE_DIR ${ROOT_DIR}/src)
    if(CMAKE_BUILD_TYPE MATCHES Debug)
        set(LIBRARY_OUTPUT_PATH ${ROOT_DIR}/bin/dbg)
        set(EXECUTABLE_OUTPUT_PATH ${ROOT_DIR}/bin/dbg)
    else()
        set(LIBRARY_OUTPUT_PATH ${ROOT_DIR}/bin)
        set(EXECUTABLE_OUTPUT_PATH ${ROOT_DIR}/bin)
    endif()

    #if compiled from source code
    #set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    #set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    #set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
endif()

if(CUDA_FOUND)
    add_definitions(-DAURORA_NVIDIA_CUDA_FOUND)
endif()
if(OPENGL_FOUND)
    add_definitions(-DAURORA_OPENGL_FOUND)
endif()
if(OPENGL_XMESA_FOUND)
    add_definitions(-DAURORA_OPENGL_XMESA_FOUND)
endif()
if(OPENGL_GLU_FOUND)
    add_definitions(-DAURORA_OPENGL_GLU_FOUND)
endif()
if(Vulkan_FOUND)
    add_definitions(-DAURORA_VULKAN_FOUND)
endif()

include_directories(${ROOT_DIR}/include ${GTK3_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
add_definitions(${GTK3_CFLAGS_OTHER})

add_library (aurora-core-tlib SHARED ${SOURCE_DIR}/aurora-core-tlib/CircularShift.cpp
                                     ${SOURCE_DIR}/aurora-core-tlib/Endian.cpp
                                     ${SOURCE_DIR}/aurora-core-tlib/IOStream.cpp
                                     ${SOURCE_DIR}/aurora-core-tlib/String.cpp
                                     ${SOURCE_DIR}/aurora-core-tlib/Memory.c)

add_library (aurora-core SHARED ${SOURCE_DIR}/aurora-core/Application.cpp
                                ${SOURCE_DIR}/aurora-core/Debug.cpp)

add_library (aurora-cli-core SHARED ${SOURCE_DIR}/aurora-cli-core/Color.cpp
                                    ${SOURCE_DIR}/aurora-cli-core/Input.cpp
                                    ${SOURCE_DIR}/aurora-cli-core/Output.cpp)

add_library (aurora-io SHARED ${SOURCE_DIR}/aurora-io/InfoOS.cpp
                              ${SOURCE_DIR}/aurora-io/InfoRAM.cpp)

add_library (aurora-crypto SHARED ${SOURCE_DIR}/aurora-crypto/AES.cpp
                                  #${SOURCE_DIR}/aurora-crypto/MD5.cpp
                            )

add_library (aurora-gengine-core SHARED ${SOURCE_DIR}/aurora-gengine-core/Window.cpp
                                        ${SOURCE_DIR}/aurora-gengine-core/Application.cpp
                                        ${SOURCE_DIR}/aurora-gengine-core/Input.cpp
                            )

add_library (aurora-gengine-opengl SHARED ${SOURCE_DIR}/aurora-gengine-opengl/OpenGL.cpp)

add_library (aurora-gui SHARED ${SOURCE_DIR}/aurora-gui/Application.cpp
                               ${SOURCE_DIR}/aurora-gui/Label.cpp
                               ${SOURCE_DIR}/aurora-gui/Style.cpp
                               ${SOURCE_DIR}/aurora-gui/Window.cpp)

add_library (aurora-math-parser SHARED ${SOURCE_DIR}/aurora-math-parser/Math.cpp)

target_link_libraries(aurora-core-tlib aurora-io)
target_link_libraries(aurora-crypto aurora-core)
target_link_libraries(aurora-gengine-core aurora-gengine-opengl
                      aurora-core
                      ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} glfw)
target_link_libraries(aurora-core aurora-cli-core)
target_link_libraries(aurora-gui aurora-core ${GTK3_LIBRARIES})

set_target_properties(aurora-core-tlib PROPERTIES OUTPUT_NAME aurora-core-tlib)
set_target_properties(aurora-core PROPERTIES OUTPUT_NAME aurora-core)

set_target_properties(aurora-gui PROPERTIES OUTPUT_NAME aurora-gui
                                            COMPILE_FLAGS "`pkg-config --cflags --libs gtk+-3.0`")

if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_executable(test_crypto ${SOURCE_DIR}/aurora-examples/test_crypto.cpp)
    add_executable(test_gengine ${SOURCE_DIR}/aurora-examples/test_gengine.cpp)
    add_executable(test_gui ${SOURCE_DIR}/aurora-examples/test_gui.cpp)
    add_executable(test_shell ${SOURCE_DIR}/aurora-examples/test_shell.cpp)
    add_executable(test_string ${SOURCE_DIR}/aurora-examples/test_string.cpp)

    target_link_libraries(test_crypto aurora-core aurora-cli-core aurora-crypto)
    target_link_libraries(test_gengine aurora-core aurora-gengine-core)
    target_link_libraries(test_gui aurora-core aurora-cli-core aurora-gui)
    target_link_libraries(test_string aurora-core aurora-core-tlib aurora-cli-core)
    target_link_libraries(test_shell aurora-core aurora-cli-core aurora-io)

    set_target_properties(test_crypto PROPERTIES OUTPUT_NAME test_crypto.out)
    set_target_properties(test_gengine PROPERTIES OUTPUT_NAME test_gengine.out)
    set_target_properties(test_gui PROPERTIES OUTPUT_NAME test_gui.out)
    set_target_properties(test_shell PROPERTIES OUTPUT_NAME test_shell.out)
    set_target_properties(test_string PROPERTIES OUTPUT_NAME test_string.out)
endif()

# DEBUG !!!
#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()
