#include <iostream>
#include "array_utils.h"
#include "log_utils.h"
#include "search.h"
#include "leetcode_array.h"
#include <vector>
#include "sort.h"
#include "performance_utils.h"
#include "MaxHeap.h"


const auto array_length = 100;
const auto lr = 0;
const auto rr = array_length + 100;

using namespace log;

int main() {

//    int *randomArr = au::generateRandomArray(array_length, lr, rr);
//    int *sortArr = au::generateSortArray(array_length, 10);

//    log::log_int_array(sortArr, 10);
//    log::log_line_break();
//    assert(0==search::binarySearch(sortArr, 10, array_length));
//    assert(9==search::binarySearch(sortArr, 19, array_length));
//    assert(-1==search::binarySearch(sortArr, 0, array_length));
//    assert(5==search::binarySearch(sortArr, 15, array_length));
//    std::cout<<endl;
//    ams::MergeSort(randomArr, 10);

//    int arr[] = {0, 1, 0, 0, 0, 13, 12, 0, 3, 0};

//    leetcode::move_zero(vec);
//    log_vector(vec);

//    int arr[] = {3, 2, 2, 3};
//    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
//    int result = leetcode::removeElement27(vec, 3);
//    assert(result == 2);
//    log_vector(vec);

//    int arr[] = {0,0,1,1,1,1,2,3,3};



    int *randomArr = au::generateRandomArray(array_length, lr, rr);
//    int a = sizeof(randomArr);
//    std::vector<int> vec(randomArr, randomArr + sizeof(randomArr) / sizeof(int));
//    int index = leetcode_array::removeDuplicates80(vec);
//    log_vector(vec, index);
//    sort::selection_sort::selection_sort(randomArr, array_length);
//    performance_utils::testSort("selection_sort", sort::selection_sort, randomArr, array_length);
//    performance_utils::testSort("insert_sort", sort::insert_sort, randomArr, array_length);
//    performance_utils::testSort("bubble_sort", sort::bubble_sort, randomArr, array_length);
//    performance_utils::testSort("merge_sort", sort::merge_sort, randomArr, array_length);

//    performance_utils::testSort("quick_sort", sort::quickSort, randomArr, array_length);
//    int result = leetcode::removeElement27(vec,2);
//    assert(result == 5);
    MaxHeap<int> maxHeap = MaxHeap<int>(randomArr, array_length);

//    srand(time(NULL));
//    for (int i = 0; i < array_length; i++) {
//        maxHeap.insert(rand() % (rr - lr + 1) + lr);
//    }
    for (int i = 0; i < array_length; i++) {
        std::cout << maxHeap.extractMax() << ",";
    }
    return 0;
}