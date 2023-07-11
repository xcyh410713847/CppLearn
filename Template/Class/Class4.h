/*************************************************************************
**文件: Class.h
**作者: shyfan
**日期: 2023/07/11 17:32:17
**功能: 类模板
*************************************************************************/

#include <iostream>

template <typename T1, typename T2>
class A5
{
public:
    A5()
    {
        std::cout << "T1 and T2" << std::endl;
    }
};

// 部分具体化
template <typename T1>
class A5<T1, int>
{
public:
    A5()
    {
        std::cout << "T1 and int" << std::endl;
    }
};

// 部分具体化
template <typename T2>
class A5<long, T2>
{
public:
    A5()
    {
        std::cout << "long and T2" << std::endl;
    }
};

// 全具体化
// 部分具体化
template <>
class A5<long, int>
{
public:
    A5()
    {
        std::cout << "long and int" << std::endl;
    }
};
