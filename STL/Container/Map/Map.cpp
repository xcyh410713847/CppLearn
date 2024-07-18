/*************************************************************************
**文件: Map.cpp
**作者: shyfan
**日期: 2023/07/29 12:23:07
**功能: Map
*************************************************************************/

#include <iostream>
#include <map>

/*
    std::map是C++标准库中常用的一种关联容器
    使用红黑树（Red-Black Tree）实现，能够在对数时间内完成插入、删除、查找等操作
*/

/**
 * 增加元素
 */
void Test_Add()
{
    std::map<int, int> mapAdd;

    // 通过 insert 方法增加元素
    mapAdd.insert(std::pair<int, int>(1, 10));

    // 通过 [] 运算符增加元素
    mapAdd[2] = 20;

    // 引用方式增加元素
    auto &it = mapAdd[3];
    it = 30;

    for (auto &it : mapAdd)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
}

int main()
{
    Test_Add();

    return 0;
}
