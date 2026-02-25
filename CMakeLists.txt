cmake_minimum_required(VERSION 3.16)
project(qtdock LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(qtdock
    main.cpp
    mainwindow.cpp
    mainwindow.h
)

target_link_libraries(qtdock PRIVATE Qt6::Widgets)
