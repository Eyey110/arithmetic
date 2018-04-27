//
// Created by Eyey on 2018/4/26.
//

#ifndef ARITHMETIC_UTILS_H
#define ARITHMETIC_UTILS_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;
namespace performance_utils {

// 判断arr数组是否有序
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;
        return true;
    }

    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
        assert(isSorted(arr, n));
    }

}

#endif //ARITHMETIC_UTILS_H
