//
// Created by Eyey on 2018/4/24.
//

#ifndef ARITHMETIC_SEARCH_H
#define ARITHMETIC_SEARCH_H


namespace search {

    //return target index or -1
    template<typename T>
    int binarySearch(const T arr[], int target, T n) {
        int l = 0, r = n;
        while (l < r) {

            int mid = (r + l) / 2;
            if (arr[mid] == target) return mid;
            if (arr[mid] > target) r = mid;
            else l = mid + 1;
        }

        return -1;
    }
}

#endif //ARITHMETIC_SEARCH_H
