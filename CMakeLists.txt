cmake_minimum_required(VERSION 3.2.0)

project(figures VERSION 0.1.01)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

set(PROJECT_DIR ${CMAKE_SOURCE_DIR})

set(PROJECT_INCLUDE_DIR ${PROJECT_DIR}/include)

set(PROJECT_SOURCE_DIR ${PROJECT_DIR}/src)

set(PROJECT_LIBS 
    ${PROJECT_INCLUDE_DIR}/lib/glad.h
    ${PROJECT_INCLUDE_DIR}/lib/glfw3.h
    ${PROJECT_INCLUDE_DIR}/lib/glfw3native.h
    ${PROJECT_INCLUDE_DIR}/lib/khrplatform.h
    ${PROJECT_INCLUDE_DIR}/lib/glad.c
    ${PROJECT_INCLUDE_DIR}/lib/imconfig.h
    ${PROJECT_INCLUDE_DIR}/lib/imgui.h
    ${PROJECT_INCLUDE_DIR}/lib/imgui.cpp
    ${PROJECT_INCLUDE_DIR}/lib/imgui_impl_glfw.h
    ${PROJECT_INCLUDE_DIR}/lib/imgui_impl_glfw.cpp
    ${PROJECT_INCLUDE_DIR}/lib/imgui_impl_opengl3.h
    ${PROJECT_INCLUDE_DIR}/lib/imgui_impl_opengl3.cpp
    ${PROJECT_INCLUDE_DIR}/lib/imgui_impl_opengl3_loader.h
    ${PROJECT_INCLUDE_DIR}/lib/imstb_rectpack.h
    ${PROJECT_INCLUDE_DIR}/lib/imstb_textedit.h
    ${PROJECT_INCLUDE_DIR}/lib/imstb_truetype.h
    ${PROJECT_INCLUDE_DIR}/lib/imgui_internal.h
    ${PROJECT_INCLUDE_DIR}/lib/imgui_tables.cpp
    ${PROJECT_INCLUDE_DIR}/lib/imgui_widgets.cpp
    ${PROJECT_INCLUDE_DIR}/lib/imgui_draw.cpp)

set(PROJECT_INCLUDES 
    ${PROJECT_INCLUDE_DIR}/mainWindow.hpp
    ${PROJECT_INCLUDE_DIR}/figure.hpp
    ${PROJECT_INCLUDE_DIR}/triangle.hpp
    ${PROJECT_INCLUDE_DIR}/rectangle.hpp
    ${PROJECT_INCLUDE_DIR}/circle.hpp
    ${PROJECT_INCLUDE_DIR}/helper.hpp)

set(PROJECT_SOURCES 
    main.cpp
    ${PROJECT_SOURCE_DIR}/mainWindow.cpp
    ${PROJECT_SOURCE_DIR}/figure.cpp
    ${PROJECT_SOURCE_DIR}/triangle.cpp
    ${PROJECT_SOURCE_DIR}/rectangle.cpp
    ${PROJECT_SOURCE_DIR}/circle.cpp
    ${PROJECT_SOURCE_DIR}/helper.cpp)

add_executable(figures
    ${PROJECT_LIBS}
    ${PROJECT_INCLUDES}
    ${PROJECT_SOURCES})

target_link_libraries(figures 
    GL
    GLU
    glut
    glfw)