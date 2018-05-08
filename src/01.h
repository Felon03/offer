/*
 * @Author: FreedomLy 
 * @Date: 2018-04-23 19:45:19 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-23 20:29:39
 * 题目
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断
 * 数组中是否含有该整数
 */

// 思路
// 首先选取数组右上角的数字，如果该数字等于要查找的数字，则查找结束
// 如果该数字大于要查找的数字，剔除该数字所在的列；如果该数字小于要
// 查找的数组，剔除该数字所在的行。也就是说如果要查找的数字不在数组
// 的右上角，则每次都在数组的查找范围剔除一行或一列，这样每一步都可
// 以缩小查找范围，直到找到要查找的数字，或者查找范围为空

#pragma once

#include <vector>

using std::vector;

class Solution01 {
public:
    bool find(const vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool found = false;

        if (matrix.empty())
            return found;

        int row = 0, col = cols - 1;
        while (row < rows && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                found = true;
                break;
            }
            else if (matrix[row][col] > target)
                --col;
            else
                ++row;
        }

        return found;
    }
    
};