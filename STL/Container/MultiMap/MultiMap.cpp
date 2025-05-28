/*************************************************************************
** 文件: STL\Container\MultiMap\MultiMap.cpp
** 作者: shyfan
** 日期: 2024/09/12 18:07:39
** 功能: multimap
*************************************************************************/

#include <iostream>
#include <map>

namespace CppLearn::STL::Container::MultiMap
{
    /*
        std::multimap 是一种基于红黑树（Red-Black Tree）实现的有序关联容器，
        它允许多个元素具有相同的键（即键不唯一）。

        操作	                时间复杂度      空间复杂度
        插入（Insertion）	    O(log n)	    O(1)
        查找（Lookup）	        O(log n)        O(1)
        删除（Deletion）	    O(log n)	    O(1)
        迭代（Iteration）	    O(n)	        O(1)
        大小（Size）	        O(1)	        O(1)
    */

    /**
     * 插入 Insertion
     * 时间复杂度：O(logN)
     *      插入操作需要首先找到正确的位置，然后进行插入，由于红黑树的高度为 O(log n)，因此插入操作的时间复杂度为 O(log n)
     * 空间复杂度：O(1)
     *      插入操作会导致树的节点增加一个固定的大小
     */
    void Test_Insertion()
    {
        std::cout << "Test_Insertion" << std::endl;

        std::multimap<int, std::string> multimap;

        std::cout << "multimap.size(): " << multimap.size() << std::endl;
        std::cout << std::endl;

        // 使用 insert() 方法插入元素
        multimap.insert({1, "one"});
        multimap.insert({1, "uno"});
        multimap.insert({2, "two"});
        multimap.insert({2, "dos"});
        multimap.insert({3, "three"});
        std::cout << "multimap.size(): " << multimap.size() << std::endl;
        std::cout << std::endl;

        // 使用 emplace() 方法插入元素 C++11
        multimap.emplace(4, "four");
        multimap.emplace(4, "cuatro");
        std::cout << "multimap.size(): " << multimap.size() << std::endl;
        std::cout << std::endl;

        // 插入重复键
        multimap.insert({1, "eins"});
        std::cout << "multimap.size(): " << multimap.size() << std::endl;
        std::cout << std::endl;

        // 遍历 multimap
        for (const auto &pair : multimap)
        {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
        std::cout << std::endl;
    }

    /**
     * 查找 Lookup
     * 时间复杂度：O(logN)
     *     查找操作通过比较键值沿树进行，红黑树的高度为 O(log n)，因此查找的时间复杂度为 O(log n)
     * 空间复杂度：O(1)
     *    查找操作并不增加或减少 multimap 的内存使用
     */
    void Test_Lookup()
    {
        std::cout << "Test_Lookup" << std::endl;

        std::multimap<int, std::string> multimap = {{1, "one"}, {1, "uno"}, {2, "two"}, {3, "three"}};

        // 使用 find() 方法查找元素
        auto it = multimap.find(1);
        if (it != multimap.end())
        {
            std::cout << "Found key 1: " << it->second << std::endl;
        }
        std::cout << std::endl;

        // 使用 equal_range() 方法查找键的范围
        auto range = multimap.equal_range(1);
        std::cout << "All values for key 1:" << std::endl;
        for (auto i = range.first; i != range.second; ++i)
        {
            std::cout << "Key: " << i->first << ", Value: " << i->second << std::endl;
        }
        std::cout << std::endl;

        // 使用 count() 方法统计键的数量
        std::cout << "Count of key 1: " << multimap.count(1) << std::endl;
        std::cout << std::endl;
    }

    /**
     * 删除 Deletion
     * 时间复杂度：O(logN)
     *     删除操作需要首先找到要删除的节点，然后重新平衡红黑树，其时间复杂度为 O(log n)
     * 空间复杂度：O(1)
     *     删除操作会导致树的节点减少一个固定的大小
     */
    void Test_Deletion()
    {
        std::cout << "Test_Deletion" << std::endl;

        std::multimap<int, std::string> multimap = {{1, "one"}, {1, "uno"}, {2, "two"}, {3, "three"}};

        std::cout << "multimap.size(): " << multimap.size() << std::endl;
        std::cout << std::endl;

        // 删除指定键的所有元素
        multimap.erase(1);
        std::cout << "multimap.size() after erasing key 1: " << multimap.size() << std::endl;
        std::cout << std::endl;

        // 删除迭代器指向的元素
        auto it = multimap.find(2);
        if (it != multimap.end())
        {
            multimap.erase(it);
        }
        std::cout << "multimap.size() after erasing key 2: " << multimap.size() << std::endl;
        std::cout << std::endl;

        // 删除所有元素
        multimap.clear();
        std::cout << "multimap.size() after clearing: " << multimap.size() << std::endl;
        std::cout << std::endl;
    }

    /**
     * 迭代 Iteration
     * 时间复杂度：O(N)
     *     遍历整个 multimap，时间复杂度为 O(n)
     * 空间复杂度：O(1)
     *     迭代操作不增加 multimap 的内存使用
     */
    void Test_Iteration()
    {
        std::cout << "Test_Iteration" << std::endl;

        std::multimap<int, std::string> multimap = {{1, "one"}, {1, "uno"}, {2, "two"}, {3, "three"}};

        // 正向迭代
        std::cout << "Forward iteration:" << std::endl;
        for (const auto &pair : multimap)
        {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
        std::cout << std::endl;

        // 反向迭代
        std::cout << "Reverse iteration:" << std::endl;
        for (auto it = multimap.rbegin(); it != multimap.rend(); ++it)
        {
            std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        }
        std::cout << std::endl;
    }

    /**
     * 大小 Size
     * 时间复杂度：O(1)
     *     multimap 会维护一个大小变量，因此获取 multimap 的大小的时间复杂度为 O(1)
     * 空间复杂度：O(1)
     *     获取 multimap 的大小并不会增加 multimap 的内存使用
     */
    void Test_Size()
    {
        std::cout << "Test_Size" << std::endl;

        std::multimap<int, std::string> multimap = {{1, "one"}, {1, "uno"}, {2, "two"}, {3, "three"}};

        // empty
        std::cout << "multimap.empty(): " << (multimap.empty() ? "true" : "false") << std::endl;
        std::cout << std::endl;

        // size
        std::cout << "multimap.size(): " << multimap.size() << std::endl;
        std::cout << std::endl;

        // max_size
        std::cout << "multimap.max_size(): " << multimap.max_size() << std::endl;
        std::cout << std::endl;
    }

    /**
     * 创建 Create
     * 时间复杂度：O(N)
     *     创建 multimap 的时间复杂度取决于初始化的元素数量。
     * 空间复杂度：O(N)
     *     创建 multimap 需要为每个元素分配内存。
     */
    void Test_Create()
    {
        std::cout << "Test_Create" << std::endl;

        // 空 multimap
        std::multimap<int, std::string> multimap1;
        std::cout << "multimap1.size(): " << multimap1.size() << std::endl;
        std::cout << std::endl;

        // 使用初始化列表创建 multimap
        std::multimap<int, std::string> multimap2 = {{1, "one"}, {2, "two"}, {3, "three"}};
        std::cout << "multimap2.size(): " << multimap2.size() << std::endl;
        for (const auto &pair : multimap2)
        {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
        std::cout << std::endl;

        // 使用复制构造函数
        std::multimap<int, std::string> multimap3(multimap2);
        std::cout << "multimap3.size(): " << multimap3.size() << std::endl;
        std::cout << std::endl;

        // 使用移动构造函数
        std::multimap<int, std::string> multimap4(std::move(multimap3));
        std::cout << "multimap4.size(): " << multimap4.size() << std::endl;
        std::cout << "multimap3.size(): " << multimap3.size() << std::endl;
        std::cout << std::endl;

        // 使用范围构造函数
        std::multimap<int, std::string> multimap5(multimap2.begin(), multimap2.end());
        std::cout << "multimap5.size(): " << multimap5.size() << std::endl;
        std::cout << std::endl;
    }

    /**
     * 赋值 Assignment
     * 时间复杂度：O(N)
     *     赋值操作需要遍历整个 multimap，将所有元素复制或移动到目标 multimap 中。
     * 空间复杂度：O(N)
     *     赋值操作需要为目标 multimap 分配与源 multimap 相同数量的内存。
     */
    void Test_Assignment()
    {
        std::cout << "Test_Assignment" << std::endl;

        std::multimap<int, std::string> multimap1 = {{1, "one"}, {2, "two"}, {3, "three"}};
        std::multimap<int, std::string> multimap2;

        // 使用赋值操作符
        multimap2 = multimap1;
        std::cout << "multimap2.size(): " << multimap2.size() << std::endl;
        for (const auto &pair : multimap2)
        {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
        std::cout << std::endl;

        // 使用移动赋值操作符 C++11
        std::multimap<int, std::string> multimap3;
        multimap3 = std::move(multimap2);
        std::cout << "multimap3.size(): " << multimap3.size() << std::endl;
        std::cout << "multimap2.size(): " << multimap2.size() << std::endl;
        std::cout << std::endl;

        // 使用初始化列表赋值 C++11
        std::multimap<int, std::string> multimap4;
        multimap4 = {{1, "one"}, {2, "two"}, {3, "three"}};
        std::cout << "multimap4.size(): " << multimap4.size() << std::endl;
        for (const auto &pair : multimap4)
        {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
        std::cout << std::endl;
    }

    /**
     * 数量 Count
     * 时间复杂度：O(logN)
     *     count 操作通过比较键值沿树进行，红黑树的高度为 O(log n)，因此时间复杂度为 O(log n)。
     * 空间复杂度：O(1)
     *     count 操作不增加或减少 multimap 的内存使用。
     */
    void Test_Count()
    {
        std::cout << "Test_Count" << std::endl;

        std::multimap<int, std::string> multimap = {{1, "one"}, {1, "uno"}, {2, "two"}, {3, "three"}};

        // 使用 count() 方法统计键的数量
        std::cout << "Count of key 1: " << multimap.count(1) << std::endl;
        std::cout << "Count of key 2: " << multimap.count(2) << std::endl;
        std::cout << "Count of key 4: " << multimap.count(4) << std::endl;
        std::cout << std::endl;

        // 遍历 multimap 并统计每个键的数量
        for (const auto &pair : multimap)
        {
            std::cout << "Key: " << pair.first << ", Count: " << multimap.count(pair.first) << std::endl;
        }
        std::cout << std::endl;
    }

    /**
     * 比较器 Compare
     * 时间复杂度：O(1)
     *     比较器的调用是常数时间操作。
     * 空间复杂度：O(1)
     *     比较器的调用不增加 multimap 的内存使用。
     */
    void Test_Compare()
    {
        std::cout << "Test_Compare" << std::endl;

        std::multimap<int, std::string> multimap = {{1, "one"}, {2, "two"}, {3, "three"}};

        // 使用 key_comp 比较器
        std::multimap<int, std::string>::key_compare key_comp = multimap.key_comp();
        std::cout << "key_comp(1, 2): " << key_comp(1, 2) << std::endl;
        std::cout << "key_comp(2, 1): " << key_comp(2, 1) << std::endl;
        std::cout << std::endl;

        // 使用 value_comp 比较器
        std::multimap<int, std::string>::value_compare value_comp = multimap.value_comp();
        std::cout << "value_comp({1, \"one\"}, {2, \"two\"}): " << value_comp({1, "one"}, {2, "two"}) << std::endl;
        std::cout << "value_comp({2, \"two\"}, {1, \"one\"}): " << value_comp({2, "two"}, {1, "one"}) << std::endl;
        std::cout << std::endl;

        // 遍历 multimap 并使用比较器
        for (auto it = multimap.begin(); it != multimap.end(); ++it)
        {
            if (key_comp(it->first, 3))
            {
                std::cout << "Key " << it->first << " is less than 3" << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    CppLearn::STL::Container::MultiMap::Test_Insertion();

    CppLearn::STL::Container::MultiMap::Test_Lookup();

    CppLearn::STL::Container::MultiMap::Test_Deletion();

    CppLearn::STL::Container::MultiMap::Test_Iteration();

    CppLearn::STL::Container::MultiMap::Test_Size();

    CppLearn::STL::Container::MultiMap::Test_Create();

    CppLearn::STL::Container::MultiMap::Test_Assignment();

    CppLearn::STL::Container::MultiMap::Test_Count();

    CppLearn::STL::Container::MultiMap::Test_Compare();

    return 0;
}
