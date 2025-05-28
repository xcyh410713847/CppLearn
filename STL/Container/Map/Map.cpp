/*************************************************************************
**文件: STL\Container\map\map.cpp
**作者: shyfan
**日期: 2024/09/12 18:07:39
**功能: map
*************************************************************************/

#include <iostream>
#include <map>

namespace CppLearn::STL::Container::Map
{
    /*
        std::map 是一种基于红黑树（Red-Black Tree）实现的有序关联容器
        有序关联容器（如 std::map）通常在缓存性能方面不如无序容器（如 std::unordered_map）。
        这是因为在 std::map 中，元素根据键的顺序进行存储，可能导致数据在内存中分散，
        而 std::unordered_map 使用哈希表，通过哈希函数将键值对分布在固定大小的桶中，有时可以提供更好的缓存命中率

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

        std::map<int, std::string> map;

        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用下标插入元素
        map[1] = "one";
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用 insert() 方法插入元素(初始化列表)
        map.insert({2, "two"});
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用 insert() 方法插入元素
        map.insert(std::make_pair(3, "three"));
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用 insert() 方法插入元素
        map.insert(std::pair<int, std::string>(4, "four"));
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用 emplace() 方法插入元素 C++11
        map.emplace(5, "five");
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用 emplace() 方法插入元素 C++11
        map.emplace(std::make_pair(6, "six"));
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用 emplace() 方法插入元素 C++11
        map.emplace(std::pair<int, std::string>(7, "seven"));
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        std::map<int, std::string> map2 = {{8, "eight"}, {9, "nine"}, {10, "ten"}};

        // 使用 insert() 方法插入元素(范围)
        map.insert(map2.begin(), map2.end());
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 赋值插入 C++17
        map.insert_or_assign(11, "eleven");
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用 insert(std::make_pair()) 方法插入元素，如果已存在则不插入
        std::cout << "map[1]: " << map.at(1) << std::endl;
        map.insert(std::make_pair(1, "1"));
        std::cout << "map[1]: " << map.at(1) << std::endl;
        map[1] = "1";
        std::cout << "map[1]: " << map.at(1) << std::endl;
        std::cout << std::endl;

        // 使用 emplace_hint() 方法插入元素 C++11
        auto it = map.emplace_hint(map.begin(), 12, "twelve");
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << "map.begin()->first: " << map.begin()->first << ", second: " << map.begin()->second << std::endl;
        std::cout << "it->first: " << it->first << ", second: " << it->second << std::endl;
        std::cout << std::endl;

        // 使用 try_emplace() 方法插入元素 C++17
        map.try_emplace(13, "thirteen");
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用 try_emplace() 方法插入元素 C++17
        map.try_emplace(13, "13");
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << "map[13]: " << map.at(13) << std::endl;
        std::cout << std::endl;
    }

    /**
     * 查找 Lookup
     * 时间复杂度：O(logN)
     *     查找操作通过比较键值沿树进行，红黑树的高度为 O(log n)，因此查找的时间复杂度为 O(log n)
     * 空间复杂度：O(1)
     *    查找操作并不增加或减少 map 的内存使用
     */
    void Test_Lookup()
    {
        std::cout << "Test_Lookup" << std::endl;

        std::map<int, int> map = {{1, 1}, {2, 2}, {3, 3}};

        // 使用下标访问元素
        std::cout << "map[1]: " << map[1] << std::endl;
        std::cout << "map[3]: " << map[3] << std::endl;
        std::cout << std::endl;

        // 使用 at() 方法访问元素
        std::cout << "map.at(1): " << map.at(1) << std::endl;
        std::cout << "map.at(3): " << map.at(3) << std::endl;
        std::cout << std::endl;

        // 使用迭代器访问元素
        std::cout << "map.find(1): " << map.find(1)->second << std::endl;
        std::cout << "map.find(3): " << map.find(3)->second << std::endl;
        std::cout << std::endl;

        // 访问不存在的元素
        std::cout << "map[4]: " << map[4] << std::endl; // 会插入一个默认值
        // std::cout << "map.at(5): " << map.at(5) << std::endl; // 会抛出异常
        // std::cout << "map.find(5): " << map.find(5)->second << std::endl; // 会抛出异常
        std::cout << std::endl;

        // 访问第一个不小于给定键的元素
        std::cout << "map.lower_bound(2): " << map.lower_bound(2)->second << std::endl;
        std::cout << "map.lower_bound(3): " << map.lower_bound(3)->second << std::endl;
        std::cout << std::endl;

        // 访问第一个大于给定键的元素
        std::cout << "map.upper_bound(2): " << map.upper_bound(2)->second << std::endl;
        std::cout << "map.upper_bound(3): " << map.upper_bound(3)->second << std::endl;
        std::cout << std::endl;

        // 访问给定键范围内的元素
        auto range = map.equal_range(2);
        std::cout << "map.equal_range(2): " << range.first->second << ", " << range.second->second << std::endl;
        range = map.equal_range(3);
        std::cout << "map.equal_range(3): " << range.first->second << ", " << range.second->second << std::endl;
        std::cout << std::endl;

        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 使用 extract 方法 C++17
        std::map<int, int>::node_type node = map.extract(2);
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << "node.key(): " << node.key() << ", value: " << node.mapped() << std::endl;
        std::cout << std::endl;

        // 使用 extract 方法 C++17
        std::map<int, int>::node_type node2 = map.extract(map.find(3));
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << "node2.key(): " << node2.key() << ", value: " << node2.mapped() << std::endl;
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

        std::map<int, int> map = {{1, 1}, {2, 2}, {3, 3}};

        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 通过键删除元素
        map.erase(1);
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 删除迭代器指向的元素
        map.erase(map.find(2));
        std::cout << "map.size(): " << map.size() << std::endl;

        // 删除所有元素
        map.clear();
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // 删除指定范围的元素
        std::map<int, int> map2 = {{1, 1}, {2, 2}, {3, 3}};
        map2.erase(map2.begin(), map2.end());
        std::cout << "map2.size(): " << map2.size() << std::endl;
        std::cout << std::endl;
    }

    /**
     * 迭代 Iteration
     * 时间复杂度：O(N)
     *     遍历整个 map，时间复杂度为 O(n)
     * 空间复杂度：O(1)
     *     迭代操作不增加 map 的内存使用
     */
    void Test_Iteration()
    {
        std::cout << "Test_Iteration" << std::endl;

        std::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

        // begin
        std::cout << "map.begin() first: " << map.begin()->first << ", second: " << map.begin()->second << std::endl;
        std::cout << std::endl;

        // end
        // std::cout << "map.end() first: " << map.end()->first << ", second: " << map.end()->second << std::endl; // 会抛出异常

        // rBegin
        std::cout << "map.rbegin() first: " << map.rbegin()->first << ", second: " << map.rbegin()->second << std::endl;
        std::cout << std::endl;

        // rEnd
        // std::cout << "map.rend() first: " << map.rend()->first << ", second: " << map.rend()->second << std::endl; // 会抛出异常
    }

    /**
     * 大小 Size
     * 时间复杂度：O(1)
     *     map 会维护一个大小变量，因此获取 map 的大小的时间复杂度为 O(1)
     * 空间复杂度：O(1)
     *     获取 map 的大小并不会增加 map 的内存使用
     */
    void Test_Size()
    {
        std::cout << "Test_Size" << std::endl;

        std::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

        // empty
        std::cout << "map.empty(): " << (map.empty() ? "true" : "false") << std::endl;
        std::cout << std::endl;

        // size
        std::cout << "map.size(): " << map.size() << std::endl;
        std::cout << std::endl;

        // max_size
        std::cout << "map.max_size(): " << map.max_size() << std::endl;
        std::cout << std::endl;
    }

    /**
     * 创建
     */
    void Test_Create()
    {
        std::cout << "Test_Create" << std::endl;

        // 创建一个空 map
        std::map<int, std::string> map1;
        std::cout << "map1 size: " << map1.size() << std::endl;
        std::cout << std::endl;

        // 使用初始化列表创建 map C++11
        std::map<int, std::string> map2 = {{1, "one"}, {2, "two"}, {3, "three"}};
        std::cout << "map2 size: " << map2.size() << std::endl;
        std::cout << std::endl;

        // 复制 map
        std::map<int, std::string> map3(map2);
        std::cout << "map3 size: " << map3.size() << std::endl;
        std::cout << "map2 size: " << map2.size() << std::endl;
        std::cout << std::endl;

        // 移动构造函数 map C++11
        std::map<int, std::string> map4(std::move(map3));
        std::cout << "map4 size: " << map4.size() << std::endl;
        std::cout << "map3 size: " << map3.size() << std::endl;
        std::cout << std::endl;

        // 使用迭代器创建 map
        std::map<int, std::string> map5(map2.begin(), map2.end());
        std::cout << "map5 size: " << map5.size() << std::endl;
        std::cout << std::endl;

        // 交换 map
        map1.swap(map2);
        std::cout << "map1 size: " << map1.size() << std::endl;
        std::cout << "map2 size: " << map2.size() << std::endl;
        std::cout << std::endl;

        // 合并 merge C++17
        std::map<int, std::string> map6 = {{3, "three3"}, {4, "four"}, {5, "five"}};
        map5.merge(map6);
        std::cout << "map5 size: " << map5.size() << std::endl;
        std::cout << "map5[3]: " << map5.at(3) << std::endl;
        std::cout << "map6 size: " << map6.size() << std::endl;
        std::cout << "map6[3]: " << map6.at(3) << std::endl;
        std::cout << std::endl;

        // 合并 merge C++17
        std::map<int, std::string> map7 = {{5, "five7"}, {6, "six"}, {7, "seven"}};
        map5.merge(std::move(map7));
        std::cout << "map5 size: " << map5.size() << std::endl;
        std::cout << "map5[5]: " << map5.at(5) << std::endl;
        std::cout << "map7 size: " << map7.size() << std::endl;
        std::cout << "map7[5]: " << map7.at(5) << std::endl;
        std::cout << std::endl;
    }

    /**
     * 赋值操作
     */
    void Test_Assignment()
    {
        std::cout << "Test_Assignment" << std::endl;

        std::map<int, std::string> map1 = {{1, "one"}, {2, "two"}, {3, "three"}};
        std::map<int, std::string> map2;

        // 使用赋值操作符
        map2 = map1;
        std::cout << "map2 size: " << map2.size() << std::endl;
        std::cout << std::endl;

        // 使用移动赋值操作符 C++11
        std::map<int, std::string> map3;
        map3 = std::move(map2);
        std::cout << "map3 size: " << map3.size() << std::endl;
        std::cout << "map2 size: " << map2.size() << std::endl;
        std::cout << std::endl;

        // 使用初始化列表赋值 C++11
        std::map<int, std::string> map4;
        map4 = {{1, "one"}, {2, "two"}, {3, "three"}};
        std::cout << "map4 size: " << map4.size() << std::endl;
        std::cout << std::endl;
    }

    /**
     * 数量
     */
    void Test_Count()
    {
        std::cout << "Test_Count" << std::endl;

        std::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

        // count
        std::cout << "map.count(1): " << map.count(1) << std::endl;
        std::cout << "map.count(4): " << map.count(4) << std::endl;
        std::cout << std::endl;
    }

    /**
     * 比较器
     */
    void Test_Compare()
    {
        std::cout << "Test_Compare" << std::endl;

        std::map<int, std::string> map = {{1, "one"}, {2, "two"}, {3, "three"}};

        // key_comp 比较器 key_comp() 返回一个用于比较键的函数对象
        // 该函数对象接受两个键值作为参数，并返回一个 bool 值，默认 std::less
        std::map<int, std::string>::key_compare key_comp = map.key_comp();
        std::cout << "key_comp(1, 2): " << key_comp(1, 2) << std::endl;
        std::cout << "key_comp(2, 1): " << key_comp(2, 1) << std::endl;
        std::cout << std::endl;

        // value_comp 比较器 value_comp() 返回一个用于比较值的函数对象
        std::map<int, std::string>::value_compare value_comp = map.value_comp();
        std::cout << "value_comp(1, 2): " << value_comp({1, "one"}, {2, "two"}) << std::endl;
        std::cout << "value_comp(2, 1): " << value_comp({2, "two"}, {1, "one"}) << std::endl;
        std::cout << std::endl;
    }
}

int main()
{
    // CppLearn::STL::Container::Map::Test_Insertion();

    // CppLearn::STL::Container::Map::Test_Lookup();

    // CppLearn::STL::Container::Map::Test_Deletion();

    // CppLearn::STL::Container::Map::Test_Iteration();

    // CppLearn::STL::Container::Map::Test_Size();

    CppLearn::STL::Container::Map::Test_Create();

    // CppLearn::STL::Container::Map::Test_Assignment();

    // CppLearn::STL::Container::Map::Test_Count();

    // CppLearn::STL::Container::Map::Test_Compare();

    return 0;
}
