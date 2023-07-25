/*************************************************************************
**文件: Set.cpp
**作者: shyfan
**日期: 2023/07/14 10:03:21
**功能: 集合
*************************************************************************/

#include <iostream>

#include <set>

int main()
{
    std::set<int> set1;
    for (int i = 0; i < 10; ++i)
    {
        set1.insert(i);
    }

    for (auto it = set1.begin(); it != set1.end(); ++it)
    {
        std::cout << *it << std::endl;
        set1.erase(it);
        set1.erase(9 - *it);
    }

    return 0;
}
