/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 21:32:45 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 21:43:08
 * 题目
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
 */

// 思路
// 在后序遍历中，最后一个数是二叉树的跟节点值
// 数组前面的数字可以分为两部分：第一部分是左子树的节点值，均小于
// 根节点值；第二部分是右子树的节点值，均大于跟节点值。找到左右子树
// 部分，采用递归方式求解

#pragma once

#include <vector>

using std::vector;

class Solution25 {
public:
    bool verify_sequence_of_bst(const vector<int>& s)
    {
        if (s.empty()) return false;

        return helper(s);
    }

private:
    bool helper(const vector<int>& s)
    {
        if (s.empty() || s.size() == 1)
            return true;
        
        int root = s.back();
        size_t i = 0;
        vector<int> left;
        while (i < s.size() - 1)
        {
            if (s[i] > root)
                break;
            left.emplace_back(s[i]);
            ++i;
        }

        size_t j = i;
        vector<int> right;
        while (j < s.size() - 1)
        {
            if (s[j] < root)
                return false;
            right.emplace_back(s[j]);
            ++j;
        }

        return helper(left) && helper(right);
    }
};