include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Src)

add_executable(SharedPtr
    SharedPtr.cpp
    Src/PointTest.cpp)

add_executable(UniquePtr
    UniquePtr.cpp
    Src/PointTest.cpp)

add_executable(WeakPtr
    WeakPtr.cpp
    Src/PointTest.cpp)
