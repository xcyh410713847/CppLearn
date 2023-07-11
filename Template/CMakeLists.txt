# 加载当前目录下的头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Function)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Class)

# 增加一个可执行的二进制
add_executable(Template
    Template.cpp)
