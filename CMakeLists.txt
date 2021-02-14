cmake_minimum_required(VERSION 3.19)
project(ProjectManager)

set(CMAKE_PREFIX_PATH E:/Qt/6.0.0/msvc2019_64/lib/cmake)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(PROJECT_SOURCES WIN32
        main.cpp
        resource.rc
        icons.qrc
        manager.cpp manager.h manager.ui
        Project.cpp Project.h
        file.h
        filterwidget.cpp filterwidget.h filterwidget.ui
        AutoCalender.cpp AutoCalender.h
        aboutwidget.cpp aboutwidget.h aboutwidget.ui)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

include_directories(E:/json-develop/single_include)
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Gui Qt6::Widgets)