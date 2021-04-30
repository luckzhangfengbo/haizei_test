/*************************************************************************
	> File Name: mytest.h
	> Author: zhangfb
	> Mail: 1819067326
	> Created Time: 四  4/29 17:40:57 2021
 ************************************************************************/

#ifndef _MYTEST_H
#define _MYTEST_H

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

#include <stdlib.h>
#include <time.h>

int *getRandData(int n) {
    int *arr = (int *)malloc(sizeof(int) * n) ;
    for (int i = 0; i < n; i++) arr[i] = rand() % n;
    return arr;
}
int *getOrderData(int n) { 
    int *arr = (int *)malloc(sizeof(int) * n) ;
    for (int i = 0; i < n; i++) arr[i] = i;
    return arr;
}

bool check(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}


#define TEST(func, arr, n)  __TEST(func, #func, arr, n)


void __TEST (
    void (*func)(int *, int, int), 
    const char *func_name, 
    int *arr, 
    int n) {
        int *temp =  (int *) malloc(sizeof(int) * n);
        memcpy(temp, arr, sizeof(int) * n);
        long long b = clock();
        func(temp, 0, n - 1);
        long long e = clock();
        if (check(temp, n)) {
            printf(GREEN("[    OK     ]"));
        } else {
            printf(RED("[     FAILED    ]"));
        }
        printf("%s " YELLOW ("(%lld ms)\n"), func_name, (1000 * (e - b) / CLOCKS_PER_SEC));
        free(temp);
        return ;
}


#endif
