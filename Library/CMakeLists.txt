add_subdirectory(Static)

add_executable(Library
    main.cpp)

target_link_libraries(Library
    PRIVATE
    TestStaticLib
)