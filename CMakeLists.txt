# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.26)

# 项目名称
project(CppLearn)

# 设置 C++ 标准为 C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Array)

add_subdirectory(BinaryTree)

add_subdirectory(Class)

add_subdirectory(Library)

add_subdirectory(MoveAssignmentOperator)

add_subdirectory(Pointer)

add_subdirectory(Socket)

add_subdirectory(STL)

add_subdirectory(Template)
