/*************************************************************************
**文件: CopyConstructor\CopyConstructor.cpp
**作者: shyfan
**日期: 2023/11/29 16:46:27
**功能: 拷贝构造函数
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
