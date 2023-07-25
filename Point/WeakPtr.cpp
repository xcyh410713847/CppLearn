/*************************************************************************
**文件: WeakPtr.cpp
**作者: shyfan
**日期: 2023/07/25 15:40:35
**功能: 弱指针
*************************************************************************/

#include <memory>
#include <iostream>

#include "PointTest.h"

int main()
{
    std::shared_ptr<CPointTest> sharedPtr = std::make_shared<CPointTest>();
    std::weak_ptr<CPointTest> weakPtr = sharedPtr; // weakPtr指向sharedPtr指向的对象
    // 使用sharedPtr和weakPtr指向的对象
    std::cout << sharedPtr << std::endl;
    std::cout << weakPtr.lock() << std::endl; // 通过lock方法获取强引用

    std::cout << sharedPtr.use_count() << std::endl;
    std::cout << weakPtr.use_count() << std::endl;

    std::cout << "sharedPtr nullptr" << std::endl;
    sharedPtr = nullptr; // 释放sharedPtr指向的对象
    std::cout << sharedPtr << std::endl;
    std::cout << weakPtr.lock() << std::endl; // 通过lock方法获取强引用
    std::cout << sharedPtr.use_count() << std::endl;
    std::cout << weakPtr.use_count() << std::endl;

    std::cout << "end" << std::endl;

    return 0;
}
