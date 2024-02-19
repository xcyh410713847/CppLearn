/*************************************************************************
**文件: Vector\push_back_emplace_back.h
**作者: shyfan
**日期: 2023/11/28 18:02:06
**功能:
*************************************************************************/

#include <iostream>
#include <vector>

class TestA
{
public:
    TestA() { std::cout << "TestA 构造函数" << std::endl; }
    TestA(const TestA &a) { std::cout << "TestA 拷贝构造函数" << std::endl; }
    TestA(TestA &&a) { std::cout << "TestA 移动构造函数" << std::endl; }
    ~TestA() { std::cout << "TestA 析构函数" << std::endl; }
};

void test_push_back()
{
    std::cout << "test_push_back ----------------------" << std::endl;
    std::vector<TestA> vec;
    TestA a;
    vec.push_back(a);
    std::cout << "----------------------" << std::endl;
}

void test_emplace_back()
{
    std::cout << "test_emplace_back ----------------------" << std::endl;
    std::vector<TestA> vec;
    TestA a;
    vec.emplace_back(a);
    std::cout << "----------------------" << std::endl;
}
