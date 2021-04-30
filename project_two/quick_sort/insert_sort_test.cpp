/*************************************************************************
	> File Name: insert_sort_test.cpp
	> Author: zhangfb
	> Mail: 1819067326
	> Created Time: 五  4/30 11:46:16 2021
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include "mytest.h"
#include "insert_sort.h"
using namespace std;


int main() {
    #define MAX_N 50000
    int *arr = getRandData(MAX_N);
    TEST(insert_sort, arr, MAX_N);
    TEST(unguarded_insert_sort, arr, MAX_N);
    #undef MAX_N
    return 0;
}


