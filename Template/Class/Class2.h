/*************************************************************************
**文件: Class.h
**作者: shyfan
**日期: 2023/07/11 17:32:17
**功能: 类模板
*************************************************************************/

#include <iostream>

#pragma region 测试一

template <typename T, typename Y>
class A1
{
public:
    A1(T t, Y y)
    {
        std::cout << "A1: " << t << " " << y << std::endl;
    }
};

// 父类是类模板，子类是普通类
class B1 : public A1<int, double>
{
public:
    B1() : A1<int, double>(2, 2.1)
    {
        std::cout << "B1" << std::endl;
    }
};

#pragma endregion

#pragma region 测试二

template <typename T, typename Y>
class A2
{
public:
    A2(T t)
    {
        std::cout << "A2: " << t << std::endl;
    }
};

template <typename X, typename Z, typename P>
class B2 : public A2<X, P>
{
public:
    B2(X x, Z z, P p) : A2<X, P>(x)
    {
        std::cout << "B2: " << z << " " << p << std::endl;
    }
};

#pragma endregion
