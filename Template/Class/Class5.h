/*************************************************************************
**文件: Class.h
**作者: shyfan
**日期: 2023/07/11 17:32:17
**功能: 类模板
*************************************************************************/

#include <iostream>

class A6
{
};
class A7
{
};

class B6 : public A6
{
};
class B7 : public A7
{
};

template <typename T1, typename T2>
class Pair
{
public:
    T1 t1;
    T2 t2;

    Pair(T1 t1, T2 t2) : t1(t1), t2(t2)
    {
    }

    // 类模板中的成员模板
    template <typename U1, typename U2>
    Pair(const Pair<U1, U2> &pair) : t1(pair.t1), t2(pair.t2)
    {
    }
};
