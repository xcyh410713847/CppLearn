/*************************************************************************
**文件: Library\Static\TestStaticLib.h
**作者: shyfan
**日期: 2023/07/31 16:02:41
**功能:
*************************************************************************/

#pragma once

#include <iostream>

#include "ITestStaticLib.h"

class TestStaticLib : public ITestStaticLib
{
public:
    TestStaticLib();
    ~TestStaticLib();

    void Test();
};

ITestStaticLib *CreateTestStaticLib()
{
    return new TestStaticLib();
}
