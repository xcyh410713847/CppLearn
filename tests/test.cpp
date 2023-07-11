/*************************************************************************
**文件: test1.cpp
**作者: shyfan
**日期: 2023/07/11 18:27:58
**功能: 测试1
*************************************************************************/

#include <gtest/gtest.h>

int add(int a, int b)
{
    return a + b;
}

TEST(AddTest, PositiveNumbers)
{
    EXPECT_EQ(add(2, 3), 5);
}

TEST(AddTest, NegativeNumbers)
{
    EXPECT_EQ(add(-2, -3), -5);
}

TEST(AddTest, ZeroAndPositive)
{
    EXPECT_EQ(add(0, 5), 5);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
