/*************************************************************************
**文件: UniquePtr.cpp
**作者: shyfan
**日期: 2023/07/25 15:40:15
**功能: 独占指针
*************************************************************************/

#include <memory>
#include <iostream>

#include "PointTest.h"

int main()
{
    std::unique_ptr<CPointTest> ptr = std::make_unique<CPointTest>();
    // 使用ptr指向的对象
    std::cout << ptr << std::endl;

    // 尝试赋值给其他
    // std::unique_ptr<CPointTest> ptr2 = ptr; // error

    // 转移所有权
    std::cout << "ptr2 = std::move(ptr)" << std::endl;
    std::unique_ptr<CPointTest> ptr2 = std::move(ptr); // ptr2指向ptr指向的对象
    std::cout << ptr << std::endl;                     // ptr为空

    std::cout << "ptr nullptr" << std::endl;
    ptr = nullptr; // 释放ptr指向的对象
    std::cout << ptr << std::endl;

    std::cout << "ptr2 nullptr" << std::endl;
    ptr2 = nullptr;                 // 释放ptr2指向的对象
    std::cout << ptr2 << std::endl; // ptr2为空

    std::cout << "end" << std::endl;

    return 0;
}
