/*************************************************************************
**文件: Array\Array.cpp
**作者: shyfan
**日期: 2024/07/09 17:12:27
**功能: 数组
*************************************************************************/

#include <iostream>

/**
 * 获取当月的最大天数
 */
int GetMonthDayCount(int64_t llTime)
{
    struct tm tmTime;
    localtime_s(&tmTime, &llTime);

    // 算出 tmTime 下个月的第一天
    tmTime.tm_mon += 1;
    if (tmTime.tm_mon > 11)
    {
        tmTime.tm_mon = 0;
        tmTime.tm_year += 1;
    }
    tmTime.tm_mday = 1;
    tmTime.tm_hour = 0;
    tmTime.tm_min = 0;
    tmTime.tm_sec = 0;
    auto llNextMonthTime = mktime(&tmTime);

    // 通过 nextMonthTime 算出当月的最后一天
    llNextMonthTime -= 1;
    localtime_s(&tmTime, &llNextMonthTime);

    return tmTime.tm_mday;
}

/**
 * 算出当月结算日的时间
 */
int64_t GetMonthSettleDayTime(int64_t llTime, int iSettleDay)
{
    struct tm tmSettleTime;
    localtime_s(&tmSettleTime, &llTime);

    // 算出 tmSettleTime 下个月的第一天
    tmSettleTime.tm_mon += 1;
    if (tmSettleTime.tm_mon > 11)
    {
        tmSettleTime.tm_mon = 0;
        tmSettleTime.tm_year += 1;
    }
    tmSettleTime.tm_mday = 1;
    tmSettleTime.tm_hour = 0;
    tmSettleTime.tm_min = 0;
    tmSettleTime.tm_sec = 0;
    auto llSettleTime = mktime(&tmSettleTime);

    // 通过 settleTime 算出上个月的最后一天
    llSettleTime -= 1;
    localtime_s(&tmSettleTime, &llSettleTime);

    if (tmSettleTime.tm_mday > iSettleDay)
    {
        tmSettleTime.tm_mday = iSettleDay;
    }
    tmSettleTime.tm_hour = 0;
    tmSettleTime.tm_min = 0;
    tmSettleTime.tm_sec = 0;

    return mktime(&tmSettleTime);
}

/**
 * 算出当前时间的下一次的月结算日的时间
 */
int64_t GetNextMonthSettleDayTime(int64_t llTime, int iSettleDay)
{
    int iMonthDayCount = GetMonthDayCount(llTime);
    int iMonthSettleDay = iSettleDay > iMonthDayCount ? iMonthDayCount : iSettleDay;

    struct tm tmSettleTime;
    localtime_s(&tmSettleTime, &llTime);
    if (tmSettleTime.tm_mday >= iMonthSettleDay)
    {
        // 算出 tmSettleTime 下个月的第一天
        tmSettleTime.tm_mon += 1;
        if (tmSettleTime.tm_mon > 11)
        {
            tmSettleTime.tm_mon = 0;
            tmSettleTime.tm_year += 1;
        }

        tmSettleTime.tm_mday = 1;
        tmSettleTime.tm_hour = 0;
        tmSettleTime.tm_min = 0;
        tmSettleTime.tm_sec = 0;

        // 算出下个月的结算日的时间
        return GetMonthSettleDayTime(mktime(&tmSettleTime), iSettleDay);
    }

    // 算出当月的结算日的时间
    return GetMonthSettleDayTime(llTime, iSettleDay);
}

/**
 * 根据结算日判断两个格林尼治时间是否是同一个月，结算日取值为 1 到 31
 */
bool IsSameMonth(int64_t llTime1, int64_t llTime2, int iSettleDay)
{
    if (iSettleDay < 1 || iSettleDay > 31)
    {
        printf("SettleDay Error, Must 1-31\n");
        return false;
    }

    if (llTime1 < 0 || llTime2 < 0)
    {
        printf("Time Error, Must > 0\n");
        return false;
    }

    if (llTime1 == llTime2)
    {
        return true;
    }

    auto llMaxTime = llTime1 > llTime2 ? llTime1 : llTime2;
    auto llMinTime = llTime1 > llTime2 ? llTime2 : llTime1;

    // 获取小时间的下一次的月结算日的时间
    auto llMinSettleTime = GetNextMonthSettleDayTime(llMinTime, iSettleDay);

    return llMaxTime < llMinSettleTime;
}

char *GetTimeSte(int64_t llTime1)
{
    struct tm tmTime;
    localtime_s(&tmTime, &llTime1);
    char *szTime = new char[20];
    sprintf_s(szTime, 20, "%d-%d-%d %d:%d:%d",
              tmTime.tm_year + 1900,
              tmTime.tm_mon + 1,
              tmTime.tm_mday,
              tmTime.tm_hour,
              tmTime.tm_min,
              tmTime.tm_sec);
    return szTime;
}

void TestIsSameMonth(int64_t llTime1, int64_t llTime2, int iSettleDay, bool bExpect)
{
    static int iTestIndex = 0;

    iTestIndex++;

    printf("[Test %d]Time1:%lld(%s), Time2:%lld(%s), SettleDay:%d, Expect:%s\n",
           iTestIndex,
           llTime1,
           GetTimeSte(llTime1),
           llTime2,
           GetTimeSte(llTime2),
           iSettleDay,
           bExpect ? "true" : "false");
    printf("Expect Result %s \n", IsSameMonth(llTime1, llTime2, iSettleDay) == bExpect ? "true" : "false");
}

int main()
{
#pragma region 测试用例 特殊情况

    // // 测试用例 相同时间
    // TestIsSameMonth(1625760000, 1625760000, 1, true);

    // // 测试用例 错误的结算日
    // TestIsSameMonth(1625760000, 1625760000, 0, false);
    // TestIsSameMonth(1625760000, 1625760000, 32, false);

    // // 测试用例 错误的时间
    // TestIsSameMonth(-1, 1625760000, 1, false);
    // TestIsSameMonth(1625760000, -1, 1, false);

#pragma endregion 测试用例 特殊情况

#pragma region 测试用例 正常情况

    // // 测试用例 2021-07-09 00:00:00 2021-07-10 00:00:00 结算日 1
    // TestIsSameMonth(1625760000, 1625846400, 1, true);

    // // 测试用例 2021-07-09 00:00:00 2021-07-10 00:00:00 结算日 9
    // TestIsSameMonth(1625760000, 1625846400, 9, true);

    // // 测试用例 2021-07-09 00:00:00 2021-07-10 00:00:00 结算日 10
    // TestIsSameMonth(1625760000, 1625846400, 10, false);

    // // 测试用例 2021-07-09 00:00:00 2021-07-10 00:00:00 结算日 31
    // TestIsSameMonth(1625760000, 1625846400, 31, true);

#pragma endregion 测试用例 正常情况

#pragma region 测试用例 跨月

    // 测试用例 2021-02-28 00:00:00 2021-03-01 00:00:00 结算日 1
    TestIsSameMonth(1614441600, 1614528000, 1, false);

    // 测试用例 2021-02-28 00:00:00 2021-03-01 00:00:00 结算日 28
    TestIsSameMonth(1614441600, 1614528000, 28, true);

    // 测试用例 2021-02-28 00:00:00 2021-03-01 00:00:00 结算日 31
    TestIsSameMonth(1614441600, 1614528000, 31, true);

#pragma endregion 测试用例 跨月

#pragma region 测试用例 跨年

    // 测试用例 2021-12-31 00:00:00 2022-01-01 00:00:00 结算日 1
    TestIsSameMonth(1640880000, 1640966400, 1, false);

    // 测试用例 2021-12-31 00:00:00 2022-01-01 00:00:00 结算日 31
    TestIsSameMonth(1640880000, 1640966400, 31, true);

    // 测试用例 2021-12-20 00:00:00 2022-01-01 00:00:00 结算日 31
    TestIsSameMonth(1639958400, 1641081600, 31, false);

    // 测试用例 2021-12-20 00:00:00 2022-01-01 00:00:00 结算日 20
    TestIsSameMonth(1639958400, 1641081600, 20, true);

#pragma endregion 测试用例 跨年

    return 0;
}
