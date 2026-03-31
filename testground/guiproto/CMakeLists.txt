cmake_minimum_required(VERSION 3.28.0)

set (project_name "guiproto")
project(${project_name} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(${project_name}
    ${project_name}.cpp
    page_type_a.h page_type_a.cpp
    test_page_a1.h test_page_a1.cpp
    page_data_base.h page_data_base.cpp
    data_source.h data_source.cpp
)

target_link_libraries(${project_name} PRIVATE Qt6::Widgets)
