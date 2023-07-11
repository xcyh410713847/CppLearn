/*************************************************************************
**文件: Class.h
**作者: shyfan
**日期: 2023/07/11 17:32:17
**功能: 类模板
*************************************************************************/

#include <iostream>

#pragma region 测试一: 父类是类模板，子类是普通类，在多态情况下父类需要指定模板参数，子类就不用了

template <typename T, typename Y>
class A3
{
public:
    virtual void TemplateFunc(T t, Y y) = 0;
};

class B3 : public A3<int, double>
{
public:
    virtual void TemplateFunc(int t, double y)
    {
        std::cout << "B3: " << t << " " << y << std::endl;
    }
};

#pragma endregion

#pragma region 测试二: 父类是类模板，子类是类模板，在多态情况下父类和子类都需要指定模板参数

template <typename T, typename Y>
class A4
{
public:
    virtual void TemplateFunc(T t, Y y) = 0;
};

template <typename X, typename Z, typename P>
class B4 : public A4<X, P>
{
public:
    virtual void TemplateFunc(X x, P p)
    {
        std::cout << "B4: " << x << " " << p << std::endl;
    }
};

#pragma endregion
