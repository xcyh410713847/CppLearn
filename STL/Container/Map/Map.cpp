/*************************************************************************
**文件: Map.cpp
**作者: shyfan
**日期: 2023/07/29 12:23:07
**功能: Map
*************************************************************************/

#include <iostream>
#include <map>
#include <vector>

struct Data1
{
    int a;
    std::vector<int> vecInt;
};

struct Data2
{
    std::vector<Data1> vecData1;

    Data2()
    {
        memset(this, 0, sizeof(Data2));
    }
};

typedef std::map<int, Data2> MapData2;

int main()
{
    MapData2 mapData2;
    for (int i = 0; i < 10; ++i)
    {
        Data2 &data2 = mapData2[i];
        for (int j = 0; j < 10; ++j)
        {
            Data1 data1;
            data1.a = j;
            data2.vecData1.push_back(data1);
        }
    }

    for (auto it = mapData2.begin(); it != mapData2.end(); ++it)
    {
        std::cout << it->first << std::endl;
        for (auto it2 = it->second.vecData1.begin(); it2 != it->second.vecData1.end(); ++it2)
        {
            std::cout << it2->a << std::endl;
        }
    }

    return 0;
}
