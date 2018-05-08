/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 14:24:40 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 14:36:53
 * 题目一
 * 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的
 * 节点(含根、叶节点)形成树的一条路径，最长路径的长度即为树的深度
 * 
 * 题目二
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中
 * 任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树
 */

// 思路一
// 深度遍历，递归求解，返回最长路径长度即可

// 思路二
// 深度遍历左右子数，当左右子数的高度查大于1时，就返回假
#pragma once

#include <algorithm>
#include "TreeNode.h"

using tree::TreeNode;

class Solution40 {
public:
    int tree_depth(TreeNode* root)
    {
        if (!root) return 0;
        int left = tree_depth(root->left) + 1;
        int right = tree_depth(root->right) + 1;
        return left > right ? left : right;
    }

    bool is_balanced(TreeNode* root)
    {
        return dfs(root) != -1;
    }

private:
    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int left = dfs(root->left);
        if (left == -1) return -1;

        int right = dfs(root->right);
        if (right == -1) return -1;

        if (std::abs(left - right) > 1) return -1;
        return std::max(left, right) + 1;
    }

};
