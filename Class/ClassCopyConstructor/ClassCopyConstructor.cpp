/*************************************************************************
**文件: Class\ClassCopyConstructor\ClassCopyConstructor.cpp
**作者: shyfan
**日期: 2024/07/09 17:16:21
**功能: 类的拷贝构造函数
*************************************************************************/

#include <iostream>

class TestA
{
public:
    TestA()
    {
        std::cout << "TestA Constructor" << std::endl;
        p = new int(999);
    }
    ~TestA()
    {
        // delete p;
    }

    int *p;
};

int main(void)
{
    TestA a;
    std::cout << "a.p addr " << &(*a.p) << std::endl;
    std::cout << "a.p " << *a.p << std::endl;

    TestA b(a);
    *b.p = 998;
    std::cout << "b.p addr " << &(*b.p) << std::endl;
    std::cout << "b.p " << *b.p << std::endl;
    std::cout << "a.p " << *a.p << std::endl;

    return 0;
}
