/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 15:25:42 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 15:42:19
 * 题目
 * 输入一个矩阵，按照从外向里以顺时针的吮吸一次打印出每个数字
 */

// note: 注意边界条件判断

#pragma once

#include <vector>

using std::vector;

class Solution21 {
public:
    vector<int> print_matrix(const vector<vector<int>>& matrix)
    {
        vector<int> ret;

        if (matrix.empty()) return ret;
        
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, down = m - 1, left = 0, right = n - 1;

        while (1)
        {
            // left --> right
            for (int col = left; col <= right; ++col)
                ret.emplace_back(matrix[top][col]);
            if (++top > down) break;

            // top --> down
            for (int row = top; row <= down; ++row)
                ret.emplace_back(matrix[row][right]);
            if (--right < left) break;

            // right --> left
            for (int col = right; col >= left; --col)
                ret.emplace_back(matrix[down][col]);
            if (--down < top) break;

            // down --> top
            for (int row = down; row >= top; --row)
                ret.emplace_back(matrix[row][left]);
            if (++left > right) break;
        }
        return ret;
    }
};
