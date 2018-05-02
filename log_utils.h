//
// Created by Eyey on 2018/4/24.
//

#ifndef ARITHMETIC_LOG_UTILS_H
#define ARITHMETIC_LOG_UTILS_H


#include <iostream>
#include <vector>

using namespace std;


namespace log_utils {


    template<typename T>
    void logd(T t) {
        cout << t;
    }

    void log_int_array(int *arr, int n) {
        cout << '[';
        for (int i = 0; i < n; i++) {

            if (i == n - 1) {
                cout << arr[i];
            } else {
                cout << arr[i] << ",";
            }
        }

        cout << ']';
    }

    void log_line_break() {
        cout << endl;
    }

    template<typename T>
    void log_vector(vector<T> vec, int n) {
        cout << '[';
        for (int i = 0; i < n; i++) {

            if (i == n - 1) {
                cout << vec[i];
            } else {
                cout << vec[i] << ",";
            }
        }
        cout << ']';
    }

    template<typename T>
    void log_vector(vector<T> vec) {
        log_vector(vec, static_cast<int>(vec.size()));
    }


}

#endif //ARITHMETIC_LOG_UTILS_H
