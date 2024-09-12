/*************************************************************************
**文件: STL\Container\set\set.cpp
**作者: shyfan
**日期: 2024/09/12 19:51:27
**功能: set
*************************************************************************/

#include <iostream>
#include <set>

namespace CppLearn::STL::Container::Set
{
    /*
        std::set 存储唯一且有序的元素，底层通常采用红黑树这种自平衡二叉查找树结构

        操作	                时间复杂度      空间复杂度
        插入(Insertion)	        O(log n)	    O(1)
        查找(Lookup)	        O(log n)	    O(1)
        删除(Erase)	            O(log n)	    O(1)
        迭代(Iteration)         O(n)	        O(1)
        大小(Size)	            O(1)	        O(1)
    */
}

    int
    main()
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
