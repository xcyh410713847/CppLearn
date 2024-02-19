/*************************************************************************
**文件: MoveConstructor\MoveConstructor.cpp
**作者: shyfan
**日期: 2023/11/29 11:46:21
**功能: 移动构造函数
*************************************************************************/

#include <iostream>

class TestA
{
public:
    TestA() { std::cout << "TestA Constructor" << std::endl; }
    TestA(TestA &&a) noexcept { std::cout << "TestA Move Constructor" << std::endl; }
    TestA(TestA &a) { std::cout << "TestA Copy Constructor" << std::endl; }
    ~TestA() { std::cout << "TestA Destructor" << std::endl; }
};

class TestB
{
};

int main(void)
{
    TestA a;
    TestA b = std::move(a); // move constructor
    TestA c(std::move(a));  // move constructor

    TestA d = a; // copy constructor
    TestA e(a);  // copy constructor


    int Count = 10000000;
    std::cout << "For " << Count << std::endl;

    int Start = clock();
    for (int i = 0; i < Count; ++i)
    {
        TestA f = std::move(a); // move constructor
    }
    int End = clock();
    std::cout << "Move Constructor: " << End - Start << std::endl;

    Start = clock();
    for (int i = 0; i < Count; ++i)
    {
        TestA g = a; // copy constructor
    }
    End = clock();
    std::cout << "Copy Constructor: " << End - Start << std::endl;

    return 0;
}
