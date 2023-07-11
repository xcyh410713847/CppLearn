/*************************************************************************
**文件: Template.cpp
**作者: shyfan
**日期: 2023/07/11 16:38:24
**功能: C++模板学习
*************************************************************************/
#include <iostream>

#include "Function.h"
#include "Class.h"

int main()
{
#pragma region 函数模板

    // 测试一：函数模板针对特殊数据类型具体化
    double d = 3.14;
    TemplateFunc1(d);
    Node node = {1, nullptr};
    TemplateFunc1(node);
    int i = 1;
    TemplateFunc1(i);
    TemplateFunc1(char(10));

    // 测试二：函数模板部分具体化
    TemplateFunc2(char('c'), char('c'));
    TemplateFunc2(char('c'), int(10));
    TemplateFunc2(long(10), char('c'));
    TemplateFunc2(short(10), int(10));

    // 测试三：函数模板实例化
    TemplateFunc3('c');
    TemplateFunc3(char(36));

#pragma endregion

#pragma region 类模板

    // 类模板
    int n = 2;
    // 此处如果使用默认模板参数可定义为 Test<> test(int(2), char('a'));
    Test1<int, double> test1(n, d);
    test1.TemplateFunc();
    Test1<> test2(1, 36);
    test2.TemplateFunc();
    // 必须指定模板类型
    Test2<int, int> test3(1, 36);
    test3.TemplateFunc();

#pragma endregion

#pragma region 类模板的继承

    // 类模板的继承 测试一
    B1();

    // 类模板的继承 测试二
    B2<int, double, char>(int(2), double(2.1), char('a'));

#pragma endregion

#pragma region 类模板的多态

    // 测试一: 父类是类模板，子类是普通类，在多态情况下父类需要指定模板参数，子类就不用了
    A3<int, double> *a3 = new B3;
    a3->TemplateFunc(2, 2.1);

    // 测试二: 父类是类模板，子类是类模板，在多态情况下父类和子类都需要指定模板参数
    A4<int, double> *a4 = new B4<int, char, double>;
    a4->TemplateFunc(2, 2.1);

#pragma endregion

#pragma region 类模板具体化

    A5<char, char>();
    A5<char, int>();
    A5<long, char>();
    A5<long, int>();

#pragma endregion

#pragma region 成员模板

    Pair<A6 *, A7 *>(Pair<B6 *, B7 *>(new B6, new B7));

#pragma endregion
}
