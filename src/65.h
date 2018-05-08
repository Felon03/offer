/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 22:32:33 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 22:45:44
 * 题目
 * 地上有一个m行n列的方格。一个机器人从坐标(0,0)的格子开始移动，它
 * 每一次可以向上、下、左、右移动一格，但不能进入行坐标和列坐标的位
 * 数之和大于k的格子。求该机器人能够到达多少格子
 */

// 思路
// 使用回溯法，如果机器人能够进入(i,j)，那我们就继续判断
// (i-1,j), (i,j-1), (i+1,j), (i,j+1)

#pragma once

#include <vector>

using std::vector;

class Solution65 {
public:
    int moving_count(int threshold, int rows, int cols)
    {
        vector<bool> visited(rows * cols, 0);
        int count = helper(threshold, rows, cols, 0, 0, visited);
        return count;
    }


private:
    // 得到坐标的位数和
    int get_sum(int x)
    {
        int ans = 0;
        while (x)
        {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }

    // 判断机器人能否进入(row, col)
    bool check(int threshold, int rows, int cols, int row, int col, vector<bool>& visited)
    {
        if (row >= 0 && row < rows && col >= 0 && col < cols &&
            get_sum(row) + get_sum(col) <= threshold && !visited[row * cols + col])
        {
            return true;
        }
        return false;
    }

    int helper(int threshold, int rows, int cols, int row, int col, vector<bool>& visited)
    {
        int count = 0;
        if (check(threshold, rows, cols, row, col, visited))
        {
            visited[row * cols + col] = true;
            // visited标记不需要回溯，因为只要被访问即可
            // 如果能访问，访问就会加1；不能访问，也会标记为访问过
            count = 1 + helper(threshold, rows, cols, row - 1, col, visited) +
                    helper(threshold, rows, cols, row, col - 1, visited) +
                    helper(threshold, rows, cols, row + 1, col, visited) +
                    helper(threshold, rows, cols, row, col + 1, visited);
        }
        return count;
    }
};
