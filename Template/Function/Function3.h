/*************************************************************************
**文件: Function3.h
**作者: shyfan
**日期: 2023/07/11 17:38:19
**功能: 函数模板实例化
*************************************************************************/

#include <iostream>

template <typename T>
void TemplateFunc3(const T &t)
{
    std::cout << "template: " << t << std::endl;
}

// 函数模板实例化，不用写函数的实现，编译器会生成该类型的模板具体化函数
template void TemplateFunc3<char>(const char &c);
