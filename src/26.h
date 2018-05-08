/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 09:01:43 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 09:19:22
 * 题目
 * 输入一棵二叉树和一个整数，打印输出二叉树中节点值的和为输入整数的
 * 所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路
 * 径
 */

#pragma once

#include "TreeNode.h"

using tree::TreeNode;

class Solution26 {
public:
    vector<vector<int>> find_path(TreeNode* root, int val)
    {
        vector<vector<int>> ret;
        vector<int> path;
        helper(root, ret, path, val);
        
        return ret;
    }

private:
    // 递归求解
    void helper(TreeNode* root, vector<vector<int>>& res, vector<int>& path, int sum)
    {
        if (!root) return;
        path.emplace_back(root->val);
        sum -= root->val;

        if (sum == 0 && !root->left && !root->right)
            res.emplace_back(path);
        helper(root->left, res, path, sum);
        helper(root->right, res, path, sum);
        path.pop_back();
    }
};
