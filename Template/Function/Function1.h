/*************************************************************************
**文件: Function1.h
**作者: shyfan
**日期: 2023/07/11 17:37:03
**功能: 函数模板针对特殊数据类型具体化
*************************************************************************/

#include <iostream>

struct Node
{
    int val;
    Node *next;
};

// 函数模板
template <typename T>
void TemplateFunc1(const T &t)
{
    std::cout << "template: " << t << std::endl;
}

// 函数模板具体化(用于处理Node类型数据)
template <>
void TemplateFunc1<Node>(const Node &t)
{
    std::cout << "template<Node>: " << t.val << std::endl;
}

// 函数模板具体化(用处处理int类型数据)
template <>
void TemplateFunc1<int>(const int &t)
{
    std::cout << "template<int>: " << t << std::endl;
}

// 普通函数
void TemplateFunc1(const int &t)
{
    std::cout << "TemplateFunc1: " << t << std::endl;
}
