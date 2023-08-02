/*************************************************************************
**文件: Library\main.cpp
**作者: shyfan
**日期: 2023/07/31 15:34:59
**功能:
*************************************************************************/

#include "Static\ITestStaticLib.h"

int main(int argc, char *argv[])
{
    ITestStaticLib *pTestStaticLib = CreateTestStaticLib();
    pTestStaticLib->Test();

    return 0;
}
