//
// Created by Eyey on 2018/4/26.
//

#include "MaxHeap.h"

template<typename Item>
MaxHeap::MaxHeap(int capacity) {
    data = new Item[capacity + 1];
}

MaxHeap::~MaxHeap() {
    delete[] data;
}

int MaxHeap::size() {
    return count;
}

template<typename Item>
bool MaxHeap<Item>::isEmpty() {
    return count == 0;
}

