/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 21:55:51 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 22:30:42
 * 题目
 * 设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
 * 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵的左、
 * 右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径
 * 不能再次进入该格子
 */

// 思路
// 采用回溯法。首先在矩阵中任选一个格子作为路径起点，假设矩阵中某个
// 格子的字符为ch并且这个格子将对应于路径上的第i个字符。如果路径上
// 的第i个字符不是ch，那么这个格子不可能处于路径上的第i个位置。如果
// 路径上的第i个字符正好是ch，那么往相邻的格子寻找路径上的第i+1个字
// 符。除在矩阵边界外，其他格子都有四个相邻的格子。重复这个过程直到
// 路径上的所有字符都在矩阵中找到相应的位置
#pragma once

#include <vector>

using std::vector;

class Solution64 {
public:
    bool has_path(const vector<vector<char>>& matrix, const string& str)
    {
        if (matrix.empty() || str.empty())
            return false;

        int rows = static_cast<int>(matrix.size());
        int cols = static_cast<int>(matrix[0].size());
        vector<bool> visited(rows * cols, 0);

        int path_length = 0;
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (helper(matrix, rows, cols, row, col, str, path_length, visited))
                    return true;
            }
        }
        return false;
        
    }

private:
    bool helper(const vector<vector<char>>& matrix, int rows, int cols,
                int row, int col, const string &str, int &path_length, vector<bool> &visited)
    {
        if (path_length == static_cast<int>(str.size()))
            return true;
        bool has_path = false;

        if (row >= 0 && row < rows && col >= 0 && col < cols &&
            matrix[row][col] == str[path_length] && !visited[row * cols + col])
        {
            ++path_length;
            visited[row * cols + col] = true;

            has_path = helper(matrix, rows, cols, row - 1, col, str, path_length, visited) ||
                       helper(matrix, rows, cols, row, col - 1, str, path_length, visited) ||
                       helper(matrix, rows, cols, row + 1, col, str, path_length, visited) ||
                       helper(matrix, rows, cols, row, col + 1, str, path_length, visited);
            if (!has_path)
            {
                --path_length;
                visited[row * cols + col] = false;
            }
        }
        return has_path;
    }
};
