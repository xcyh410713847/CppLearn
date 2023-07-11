/*************************************************************************
**文件: Class.h
**作者: shyfan
**日期: 2023/07/11 17:32:17
**功能: 类模板
*************************************************************************/

#include <iostream>

// 此处指定了模板默认参数，部分指定必须从右到左指定
template <typename T = int, typename Y = char>
class Test1
{
public:
    Test1(T t, Y y) : t(t), y(y) {}

    void TemplateFunc();

private:
    T t;
    Y y;
};

// 类模板的函数在类外实现，需要加上模板参数列表，但不需要加指定的默认模板参数
// 类外使用Test需要加模板参数
template <typename T, typename Y>
void Test1<T, Y>::TemplateFunc()
{
    std::cout << "t: " << t << " y: " << y << std::endl;
}

template <typename T, typename Y>
class Test2
{
public:
    Test2(T t, Y y) : t(t), y(y) {}

    void TemplateFunc();

private:
    T t;
    Y y;
};

template <typename T, typename Y>
void Test2<T, Y>::TemplateFunc()
{
    std::cout << "t: " << t << " y: " << y << std::endl;
}
