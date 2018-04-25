//
// Created by Eyey on 2018/4/24.
//

#ifndef ARITHMETIC_ARRAY_UTILS_H
#define ARITHMETIC_ARRAY_UTILS_H

#include <iostream>
#include <algorithm>
#include <cassert>


using namespace std;

namespace au {
    int *generateRandomArray(int n, int l, int r) {
        assert(n > 0 && l <= r);
        int *arr = new int[n];

        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (r - l + 1) + l;

        }
        return arr;
    }


    int *generateSortArray(int n, int offset = 0) {
        assert(n > 0);
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + offset;
        }
        return arr;
    }
}

#endif //ARITHMETIC_ARRAY_UTILS_H
