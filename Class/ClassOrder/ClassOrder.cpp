/*************************************************************************
**文件: Class\ClassOrder\ClassOrder.cpp
**作者: shyfan
**日期: 2024/07/09 17:08:38
**功能: 类的初始化顺序
*************************************************************************/

#include <iostream>

// 基类
class Base
{
public:
    Base()
    {
        std::cout << "Base()" << std::endl;
    }

    ~Base()
    {
        std::cout << "~Base()" << std::endl;
    }
};

// 子类
class Derived : public Base
{
public:
    Derived()
    {
        std::cout << "Derived()" << std::endl;
    }

    ~Derived()
    {
        std::cout << "~Derived()" << std::endl;
    }
};

void PrintOrder()
{
    Derived d = Derived();
}

int main() { PrintOrder(); }
