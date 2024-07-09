/*************************************************************************
**文件: Array\Array.cpp
**作者: shyfan
**日期: 2024/07/09 17:12:27
**功能: 数组
*************************************************************************/

#include <iostream>

int main()
{
    int *arrNumber[10];
    memset(arrNumber, 0, sizeof(arrNumber));

    for (int i = 0; i < 10; ++i)
    {
        std::cout << arrNumber[i] << std::endl;
    }

    return 0;
}
