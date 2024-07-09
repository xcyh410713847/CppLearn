/*************************************************************************
**文件: Vector\push_back_emplace_back.h
**作者: shyfan
**日期: 2023/11/28 18:02:06
**功能:
*************************************************************************/

#include <iostream>
#include <vector>
#include <random>
#include <windows.h>

class TestA
{
public:
    TestA() { std::cout << "TestA 构造函数" << std::endl; }
    TestA(const TestA &a) { std::cout << "TestA 拷贝构造函数" << std::endl; }
    TestA(TestA &&a) { std::cout << "TestA 移动构造函数" << std::endl; }
    ~TestA() { std::cout << "TestA 析构函数" << std::endl; }
};

void test_push_back()
{
    std::cout << "test_push_back ----------------------" << std::endl;
    std::vector<TestA> vec;
    TestA a;
    vec.push_back(a);
    std::cout << "----------------------" << std::endl;
}

void test_emplace_back()
{
    std::cout << "test_emplace_back ----------------------" << std::endl;
    std::vector<TestA> vec;
    TestA a;
    vec.emplace_back(a);
    std::cout << "----------------------" << std::endl;
}

// 从vector中随机出指定个数的元素
void test_random()
{
    std::cout << "test_random ----------------------" << std::endl;
    // 获取当前tick
    auto start = GetTickCount64();

    std::vector<int> vec;
    for (int i = 0; i < 999999; ++i)
    {
        vec.push_back(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(vec.begin(), vec.end(), gen);

    for (int i = 0; i < 50; ++i)
    {
        std::cout << vec[i] << std::endl;
    }

    auto end = GetTickCount64();
    std::cout << "time: " << end - start << std::endl;
}
