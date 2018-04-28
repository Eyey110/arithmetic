//
// Created by Eyey on 2018/4/26.
//

#ifndef ARITHMETIC_MAXHEAP_H
#define ARITHMETIC_MAXHEAP_H

#include "array_utils.h"

using namespace std;

template<class Item>
class MaxHeap {
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int index) {
        while (index > 1) {
            if (this->data[index] > this->data[index / 2]) {
                au::swap(data[index], data[index / 2]);
                index /= 2;
            } else {
                break;
            }
        }
    };

    void shiftDown(int k) {
        int i = 1;
        while (2 * k <= count) {
            int j = 2 * k;
            if (j + 1 <= count && data[j + 1] > data[j])
                j++;
            if (data[k] >= data[j]) break;
            swap(data[k], data[j]);
            k = j;
        }
    };

public:
    MaxHeap(int capacity) {
        data = new Item[capacity + 1];
        this->capacity = capacity;
        this->count = 0;
    };


    MaxHeap(Item arr[], int n) {
        this->data = new Item[n + 1];
        for (int i = 0; i < n; i++) {
            this->data[i + 1] = arr[i];
        }
        this->count = n;
        this->capacity = n;
        for (int i = n / 2; i >= 1; i--) {
            shiftDown(i);
        }
    }


    ~MaxHeap() {
        delete[] data;

    };

    int size() {
        return count;

    };

    bool isEmpty() {
        return count == 0;

    };

    void insert(Item data) {
        assert(count < capacity);
        this->data[++count] = data;
        shiftUp(count);
    };

    Item extractMax() {
        assert(!isEmpty());
        Item maxItem = data[1];
        au::swap(data[1], data[count--]);
        shiftDown(1);
        return maxItem;
    };


    Item getMax() {
        assert(!isEmpty());
        return data[0];
    };
};


#endif //ARITHMETIC_MAXHEAP_H
