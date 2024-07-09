# 设置 Commone 目录
set(common_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../Commone)

# 包含 Commone 目录
include_directories(${common_DIR})

add_executable(UniquePtr
    UniquePtr.cpp
    ${common_DIR}/PointTest.cpp)
