enable_testing()

# 设置 gtest_force_shared_crt 选项
if(MSVC)
    # 以MSVC编译器为例
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# 添加测试目标
add_executable(
    test
    test.cpp
    )

# 链接测试库
target_link_libraries(
    test
    GTest::gtest_main
    )

include(GoogleTest)
gtest_discover_tests(test)
