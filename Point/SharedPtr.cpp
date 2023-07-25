/*************************************************************************
**文件: SharedPtr.cpp
**作者: shyfan
**日期: 2023/07/25 15:40:30
**功能: 共享指针
*************************************************************************/

#include <memory>
#include <iostream>

#include "PointTest.h"

int main()
{
    std::shared_ptr<CPointTest> ptr1 = std::make_shared<CPointTest>();
    std::shared_ptr<CPointTest> ptr2 = ptr1; // 复制ptr1指向的对象
    // 使用ptr1和ptr2指向的对象
    std::cout << ptr1 << std::endl;
    std::cout << ptr2 << std::endl;

    std::cout << ptr1.use_count() << std::endl;
    std::cout << ptr2.use_count() << std::endl;

    std::cout << "ptr1 nullptr" << std::endl;
    ptr1 = nullptr; // 释放ptr1指向的对象
    std::cout << ptr1 << std::endl;
    std::cout << ptr2 << std::endl;
    std::cout << ptr1.use_count() << std::endl;
    std::cout << ptr2.use_count() << std::endl;

    std::cout << "ptr2 nullptr" << std::endl;
    ptr2 = nullptr; // 释放ptr2指向的对象
    std::cout << ptr1 << std::endl;
    std::cout << ptr2 << std::endl;
    std::cout << ptr1.use_count() << std::endl;
    std::cout << ptr2.use_count() << std::endl;

    std::cout << "end" << std::endl;

    return 0;
}
