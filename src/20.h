/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 14:43:59 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 14:47:50
 * 题目
 * 请完成一个函数，输入一棵二叉树，该函数输出它的镜像
 */

#pragma once

#include <algorithm>
#include "TreeNode.h"

using tree::TreeNode;

class Solution20 {
public:
    // 递归构造镜像二叉树
    void mirror(TreeNode* root)
    {
        if (!root) return;
        if (!root->left && !root->right) return;

        std::swap(root->left, root->right);

        if (root->left)
            mirror(root->left);
        if (root->right)
            mirror(root->right);
    }
};
