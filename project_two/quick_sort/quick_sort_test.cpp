/*************************************************************************
	> File Name: quick_sort_test.cpp
	> Author: zhangfb
	> Mail: 1819067326
	> Created Time: 四  4/29 13:22:20 2021
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include "mytest.h"
#include "quick_sort.h"
using namespace std;

int main() {
    #define MAX_N 10000000
    int *arr = getRandData(MAX_N);
    TEST(quick_sort_v1, arr, MAX_N);
    TEST(quick_sort_v2, arr, MAX_N);
    TEST(quick_sort_v3, arr, MAX_N);
    TEST(quick_sort_v4, arr, MAX_N);
    TEST(quick_sort_v5, arr, MAX_N);
    TEST(quick_sort_v6, arr, MAX_N);
    free(arr);
    #undef MAX_N
    #define MAX_N 50000
    arr = getOrderData(MAX_N);
    TEST(quick_sort_v1, arr, MAX_N);
    TEST(quick_sort_v2, arr, MAX_N);
    TEST(quick_sort_v3, arr, MAX_N);
    TEST(quick_sort_v4, arr, MAX_N);
    TEST(quick_sort_v5, arr, MAX_N);
    TEST(quick_sort_v6, arr, MAX_N);
    #undef MAX_N
    return 0;
}
