/*************************************************************************
**文件: Class\ClassSize\ClassSize.cpp
**作者: shyfan
**日期: 2024/07/09 17:09:41
**功能: 类的大小
*************************************************************************/

#include <iostream>

// 空类
class Empty
{
};

// 带虚函数的类
class Virtual
{
public:
    virtual void func()
    {
        std::cout << "Virtual::func()" << std::endl;
    }
};

// 带函数的类
class NonVirtual
{
public:
    void func()
    {
        std::cout << "NonVirtual::func()" << std::endl;
    }
};

// 带成员变量的类
class Member
{
public:
    int a;
};

int main()
{
    std::cout << "空类大小 " << sizeof(Empty) << std::endl;
    std::cout << "带虚函数的类大小 " << sizeof(Virtual) << std::endl;
    std::cout << "带函数的类大小 " << sizeof(NonVirtual) << std::endl;
    std::cout << "带成员变量的类大小 " << sizeof(Member) << std::endl;

    Empty e = Empty();
    Virtual v = Virtual();
    NonVirtual nv = NonVirtual();
    Member m = Member();
    std::cout << "空类对象大小 " << sizeof(e) << std::endl;
    std::cout << "带虚函数的类对象大小 " << sizeof(v) << std::endl;
    std::cout << "带函数的类对象大小 " << sizeof(nv) << std::endl;
    std::cout << "带成员变量的类对象大小 " << sizeof(m) << std::endl;
}
