cmake_minimum_required(VERSION 3.20)

project(GPUSwitcher)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(gpu-switcher
    main.cpp
    MainWindow.cpp
    backend.cpp
    ${RESOURCES}
)

target_include_directories(gpu-switcher PRIVATE .)

target_link_libraries(gpu-switcher PRIVATE Qt6::Widgets)
