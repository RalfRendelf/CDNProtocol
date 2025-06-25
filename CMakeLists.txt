cmake_minimum_required(VERSION 3.14)

project(CDNProtocol LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(CDNProtocol SHARED
  CDNProtocol_global.h
  cdnprotocol.cpp
  cdnprotocol.h
)

target_link_libraries(CDNProtocol PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(CDNProtocol PRIVATE CDNPROTOCOL_LIBRARY)
