/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 18:47:31 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 19:14:25
 * 题目
 * 请实现一个函数，用来判断一棵二叉树是否是对称的
 * 如果一棵二叉树和它的镜像一样，那么它是对称的
 */

#pragma once

#include "TreeNode.h"

using tree::TreeNode;

class Solution58 {
public:
    bool is_symmetric(TreeNode* root)
    {
        if (!root) return true;
        return helper(root->left, root->right);
    }

private:
    bool helper(TreeNode* l, TreeNode* r)
    {
        if (!l && !r) return true;
        if (!l || !r) return false;

        return l->val == r->val &&
               helper(l->left, r->right) &&
               helper(l->right, r->left);
    }
};
