/*************************************************************************
**文件: Library\Static\ITestStaticLib.h
**作者: shyfan
**日期: 2023/07/31 16:03:08
**功能:
*************************************************************************/

#pragma once

struct ITestStaticLib
{
    virtual void Test() = 0;
};

extern "C" ITestStaticLib *CreateTestStaticLib();
