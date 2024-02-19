/*************************************************************************
**文件: MoveAssignmentOperator\MoveAssignmentOperator.cpp
**作者: shyfan
**日期: 2023/11/29 11:57:51
**功能: 移动赋值运算符
*************************************************************************/

#include <iostream>

class TestA
{
public:
    TestA() { std::cout << "TestA Constructor" << std::endl; }
    TestA(const TestA &a) noexcept { std::cout << "TestA Copy Constructor" << std::endl; }
    ~TestA() { std::cout << "TestA Destructor" << std::endl; }

    TestA &operator=(const TestA &a) noexcept
    {
        std::cout << "TestA Copy Assignment Operator" << std::endl;
        return *this;
    }

    TestA &operator=(TestA &&a) noexcept
    {
        std::cout << "TestA Move Assignment Operator" << std::endl;
        return *this;
    }
};

int main(void)
{
    TestA a;
    TestA b;
    b = a;

    return 0;
}
