# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.15)

set(CMAKE_SKIP_ALL_BUILD NO)

# 项目名称
project(CppLearn)

# 增加GTest子目录
# add_subdirectory(googletest-1.13.0)

# 增加工程目录
add_subdirectory(Template)

# 增加测试目录
# add_subdirectory(tests)
add_subdirectory(Set)

add_subdirectory(Array)

add_subdirectory(ChatGPT)

add_subdirectory(Point)

add_subdirectory(Map)

add_subdirectory(Library)
