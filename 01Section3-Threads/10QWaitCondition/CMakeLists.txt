cmake_minimum_required(VERSION 3.14)

project(10QWaitCondition LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(10QWaitCondition
  main.cpp
  producer.h producer.cpp
  consumer.h consumer.cpp
)
target_link_libraries(10QWaitCondition Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS 10QWaitCondition
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
