/*************************************************************************
	> File Name: main.cpp
	> Author: zhangfb
	> Mail: 1819067326
	> Created Time: 四 11/ 5 20:47:58 2020
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <gtest/gtest.h>
int add (int a, int b) {
    return a + b;
}

TEST(testFunc, add) {//测试用例
    EXPECT_EQ(add(5,  3), 8);//测试点
    EXPECT_EQ(add(5,  3), 9);
    EXPECT_EQ(add(6,  7), 9);
}

int main(int argc, char **argv) {
    //testing::InitGoogleTest(&argc, argv);//命令行参数初始化谷歌测试框架
    return RUN_ALL_TESTS();
}
