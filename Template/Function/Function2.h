/*************************************************************************
**文件: Function2.h
**作者: shyfan
**日期: 2023/07/11 17:37:45
**功能: 函数模板部分具体化
*************************************************************************/

#include <iostream>

template <typename T1, typename T2>
void TemplateFunc2(const T1 &t1, const T2 &t2)
{
    std::cout << typeid(T1).name() << " and " << typeid(T2).name() << ": " << t1 << " " << t2 << std::endl;
}

template <typename T1>
void TemplateFunc2(const T1 &t1, const int &t2)
{
    std::cout << typeid(T1).name() << " and int: " << t1 << " " << t2 << std::endl;
}

template <typename T2>
void TemplateFunc2(const long &t1, const T2 &t2)
{
    std::cout << "long and " << typeid(T2).name() << ": " << t1 << " " << t2 << std::endl;
}

template <>
void TemplateFunc2<int>(const long &t1, const int &t2)
{
    std::cout << "long and int: " << t1 << " " << t2 << std::endl;
}
