/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 14:27:47 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 14:31:38
 * 题目
 * 输入两棵二叉树A和B，判断 B 是不是 A 的子结构
 * note: 我们约定空树不是任意一棵树的子结构
 */

#pragma once

#include "TreeNode.h"

using tree::TreeNode;

class Solution19 {
public:
    bool has_subtree(TreeNode* t1, TreeNode* t2)
    {
        bool ret = false;

        if (t1 && t2)
        {
            if (t1->val == t2->val)
                ret = does_t1_has_t2(t1, t2);
            if (!ret)
                ret = has_subtree(t1->left, t2);
            if (!ret)
                ret = has_subtree(t1->right, t2);
        }
        return ret;
    }

private:
    bool does_t1_has_t2(TreeNode* t1, TreeNode * t2)
    {
        if (!t2) return true;
        if (!t1) return false;
        if (t1->val != t2->val) return false;

        return does_t1_has_t2(t1->left, t2->left) &&
               does_t1_has_t2(t1->right, t2->right);
    }
};
