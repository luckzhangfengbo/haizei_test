#include <stdlib.h>
#define swap(a, b) {\
    __typeof(a) __c = a;\
    a = b, b = __c;\
}



void quick_sort_v1(int * arr, int l, int r) {
    if (l >= r) return ;
    int x= l, y = r, z = arr[l];
    while (x < y) {
        while (x < y && arr[y] >= z) --y;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) ++x;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort_v1(arr, l, x - 1);
    quick_sort_v1(arr, x + 1, r);
    return ;
}



//单边递归法
void quick_sort_v2(int * arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l];
        while (x < y) {
            while (x < y && arr[y] >= z) --y;
            if (x < y) arr[x++] = arr[y];
            while (x < y && arr[x] <= z) ++x;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = z;
        quick_sort_v2(arr, l, x - 1);
        l = x + 1;
    }
    return ;
}



//无监督优化
void quick_sort_v3(int * arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l];
        do {
            while (arr[x] < z)++x;
            while (arr[y] > z)--y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort_v3(arr, l, y);
        l = x;
    }
    return ;
}
//基准值选择优化
//随机选值优化
void quick_sort_v4(int * arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = arr[l + rand() % (r - l + 1)];
        do {
            while (arr[x] < z)++x;
            while (arr[y] > z)--y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort_v4(arr, l, y);
        l = x;
    }
    return ;
}

inline int median(int *arr, int l, int r) {
    int a = arr[l], b = arr[r], c = arr[(l + r) >> 1];
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

//三点取中法
void quick_sort_v5(int * arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = median(arr, l, r);
        do {
            while (arr[x] < z)++x;
            while (arr[y] > z)--y;
            if (x <= y) {
                swap(arr[x], arr[y]);
                ++x, --y;
            }
        } while (x <= y);
        quick_sort_v5(arr, l, y);
        l = x;
    }
    return ;
}
