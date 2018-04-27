//
// Created by Eyey on 2018/4/26.
//

#ifndef ARITHMETIC_MAXHEAP_H
#define ARITHMETIC_MAXHEAP_H

template<typename Item>
class MaxHeap {
private:
    Item *data;
    int count;

public:
    MaxHeap(int capacity);

    ~MaxHeap();

    int size();

    bool isEmpty();
};


#endif //ARITHMETIC_MAXHEAP_H
