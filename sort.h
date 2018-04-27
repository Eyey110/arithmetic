//
// Created by Eyey on 2018/4/26.
//

#ifndef ARITHMETIC_SORT_H
#define ARITHMETIC_SORT_H

#include <cassert>
#include "log_utils.h"

namespace sort {

    template<typename T>
    void mergearray(T a[], int first, int mid, int last, T temp[]) {
        int i = first, j = mid + 1;
        int m = mid, n = last;
        int k = 0;


        while (i <= m && j <= n) {
            if (a[i] <= a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
        }

        while (i <= m)
            temp[k++] = a[i++];

        while (j <= n)
            temp[k++] = a[j++];

        for (i = 0; i < k; i++)
            a[first + i] = temp[i];
    }

    template<typename T>
    void __mergesort(T a[], int first, int last, T temp[]) {
        if (first < last) {
            int mid = (first + last) / 2;
            __mergesort(a, first, mid, temp);    //左边有序
            __mergesort(a, mid + 1, last, temp); //右边有序
            mergearray(a, first, mid, last, temp); //再将二个有序数列合并
        }
    }

    template<typename T>
    void merge_sort(T arr[], int n) {
        T *p = new T[n];
        __mergesort(arr, 0, n - 1, p);
        delete[] p;
    }

    template<typename T>
    void selection_sort(T arr[], int n) {
        assert(arr != NULL);
        for (int i = 0; i < n; i++) {
            int temp = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[temp])
                    temp = j;
            }
            swap(arr[temp], arr[i]);
        }
    };


    template<typename T>
    void insert_sort(T arr[], int n) {
        assert(arr != NULL);
        if (n == 1)
            return;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j > 0; j--) {
                if (arr[j] < arr[j - 1])
                    swap(arr[j], arr[j - 1]);
            }
        }
    }

    template<typename T>
    void bubble_sort(T arr[], int n) {
        assert(arr != NULL);
        if (n == 1)
            return;
        for (int i = n - 1; i > 0; i--) {
            for (int j = i; j > 0; j--) {
                if (arr[j] < arr[j - 1])
                    swap(arr[j], arr[j - 1]);
            }
        }
    }
}

#endif //ARITHMETIC_SORT_H
