//
// Created by Eyey on 2018/4/24.
//

#ifndef ARITHMETIC_LEETCODE_H
#define ARITHMETIC_LEETCODE_H

#include <vector>
#include "log_utils.h"

using namespace std;
namespace leetcode_array {
    void move_zero(vector<int> &nums) {
        //method 1:时间复杂度O(n),空间复杂度O(n)
//        vector<int> temp;
//        for (int num : nums)
//            if (num)
//                temp.push_back(num);
//        int j = 0;
//        for (; j < temp.size(); j++) {
//            nums[j] = temp[j];
//        }
//        while (j < nums.size()) {
//            nums[j] = 0;
//            j++;
//        }
        //method 2:遍历，不停交换非零元素和0元素的位置
//        int k = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i]) {
//                nums[k] = nums[i];
//                k++;
//            }
//        }
//        for (; k < nums.size(); k++) {
//            nums[k] = 0;
//        }
        //method 3:
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] && i != k) {
                if (i != k) {
                    int temp = nums[i];
                    nums[i] = nums[k];
                    nums[k++] = temp;
                } else {
                    k++;
                }
            }
        }
    }

//    给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//    不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//    示例 1:
//    给定 nums = [3,2,2,3], val = 3,
//    函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
//    你不需要考虑数组中超出新长度后面的元素。
//    示例 2:
//    给定 nums = [0,1,2,2,3,0,4,2], val = 2,
//    函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
//    注意这五个元素可为任意顺序。
//    你不需要考虑数组中超出新长度后面的元素。

    int removeElement27(vector<int> &nums, int val) {

        int k = 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                if (i != k) {
                    int temp = nums[i];
                    nums[i] = nums[k];
                    nums[k++] = temp;
                } else {
                    k++;
                }

            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                result++;
            }
        }
        log::log_vector(nums);
        return result;
    }

//    给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//    不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//    示例 1:
//    给定数组 nums = [1,1,2],
//    函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
//    你不需要考虑数组中超出新长度后面的元素。
//    示例 2:
//    给定 nums = [0,0,1,1,1,2,2,3,3,4],
    // 0101122334

//    函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//    你不需要考虑数组中超出新长度后面的元素。
    int removeDuplicates26(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[index++] = nums[i];
                log::log_vector(nums);
                log::log_line_break();
            }


        }
        return index;
    }
//    给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
//    不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//    示例 1:
//    给定 nums = [1,1,1,2,2,3],
//    函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
//    你不需要考虑数组中超出新长度后面的元素。
//    示例 2:
//    给定 nums = [0,0,1,1,1,1,2,3,3],
//    函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
//    你不需要考虑数组中超出新长度后面的元素。

    int removeDuplicates80(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int index = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[index++] = nums[i];
                log::log_vector(nums);
                log::log_line_break();
                count++;
            } else if (count >= 1) {
                nums[index++] = nums[i];
                log::log_vector(nums);
                log::log_line_break();
                count = 0;
            }


        }
        return index;
    }


}
#endif //ARITHMETIC_LEETCODE_H
