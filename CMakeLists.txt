# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.26)

set(CMAKE_SKIP_ALL_BUILD NO)

# 项目名称
project(CppLearn)

# 设置 C++ 标准为 C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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

add_subdirectory(Socket)

add_subdirectory(Vector)

add_subdirectory(MoveConstructor)

add_subdirectory(MoveAssignmentOperator)

add_subdirectory(CopyConstructor)
