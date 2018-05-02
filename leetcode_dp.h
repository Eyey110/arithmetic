//
// Created by Eyey on 2018/5/2.
//

#ifndef ARITHMETIC_LEETCODE_DP_H
#define ARITHMETIC_LEETCODE_DP_H


#include <vector>
#include <cmath>

using namespace std;


namespace leetcode_dp {

    // 假如用minimus[i][j]来表示从第i行第j列处的数字开始往下到最后一层的最小路径和，那么有：
    // minimus[i][j]=data[i][j]+min(minimums[i+1][j]+minimums[i+1][j+1])
    // 求minimus[0][0]
    //    [2],
    //    [3,4],
    //    [6,5,7],
    //    [4,1,8,3]
    //过程
    //1、res:[4,1,8,3]
    //2、res:[7,6,11]
    //3、res:[9,10]
    //4、res:[11]
    int minimumTotal120(vector<vector<int>> &triangle) {
        int *res = new int[triangle.size()];
        for (int i = 0; i < triangle.size(); i++) {
            res[i] = triangle[triangle.size() - 1][i];
        }
        auto rowSize = static_cast<int>(triangle.size());
        for (int i = rowSize - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                res[j] = min(res[j], res[j + 1]) + triangle[i][j];
            }
        }
        return res[0];
    };


    //给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
    //说明：每次只能向下或者向右移动一步。
    //输入:
    //    [1,3,1],
    //    [1,5,1],
    //    [4,2,1]
    //    输出: 7
    //    解释: 因为路径 1→3→1→1→1 的总和最小。
    //    pathSum[i][j] =  data[i][j]+min(pathSum[i-1][j],pathSum[i][j-1])
    //    pathSum[0][0] =  data[i][j]
    //    求pathSum[w-1][j-1]
    int minPathSum64(vector<vector<int>> &grid) {
        auto width = grid.size();
        auto height = grid[0].size();
        int *pathSum = new int[width*height];
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (i == 0 && j == 0) {
                    pathSum[0] = grid[0][0];
                } else if (i == 0) {
                    pathSum[j * width + i] =
                            pathSum[i + (j - 1) * width] + grid[i][j];
                } else if (j == 0) {
                    pathSum[j * width + i] =
                            pathSum[(i - 1) + j * width] + grid[i][j];
                } else {
                    pathSum[j * width + i] =
                            min(pathSum[i - 1 + j * width], pathSum[i + (j - 1) * width]) + grid[i][j];
                }

            }
        }
        return pathSum[(height - 1) * width + width - 1];
    }
};


#endif //ARITHMETIC_LEETCODE_DP_H
