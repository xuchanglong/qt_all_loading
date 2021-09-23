cmake_minimum_required(VERSION 3.0)
set(TARGET_NAME "all_loading")
project(${TARGET_NAME} LANGUAGES CXX)

# 设置自动生成 ui.h 文件。
set(CMAKE_AUTOUIC ON)
# 设置自动生成 moc 文件。
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(RCC_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/resources/all.qrc)

# 收集指定目录中所有源文件的名称，并将列表存储在提供的变量中。
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_FILES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_FILES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/core SRC_FILES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/common SRC_FILES)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src/baseGui SRC_FILES)

# 添加编译选项
add_definitions(-std=c++11)
add_definitions(-g)

# 设置最终的目标文件是可执行程序以及其名称。
add_executable(${TARGET_NAME} ${SRC_FILES} ${RCC_FILE})

# 添加头文件搜索目录，方便编写代码时头文件查找。
target_include_directories(
    ${TARGET_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/baseGui
    ${CMAKE_CURRENT_SOURCE_DIR}/src/common
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core
)

find_package(Qt5 COMPONENTS Core Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui)