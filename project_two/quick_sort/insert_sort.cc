
#define swap(a, b) {\
    __typeof(a) __c = a;\
    a = b, b = __c;\
}

//j > l 监督项
void insert_sort(int *arr, int l, int r) {
    for(int i = l + 1; i <= r; i++) {
        int j = i;
        while (j > l && arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            --j;
        }
    }
    return ;
}

void unguarded_insert_sort(int *arr, int l, int r) {
    int ind  = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    while (ind > l) {
        swap(arr[ind], arr[ind - 1]);
        --ind;
    }//保证插入排序的稳定性


    for(int i = l + 2; i <= r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            --j;
        }
    }
    return ;
}


