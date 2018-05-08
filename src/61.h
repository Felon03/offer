/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 20:25:45 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 20:31:14
 * 题目
 * 给定一棵二叉搜索树，找出其中第k大的节点
 */

// 思路
// 可以先得到二叉搜索树的中序遍历(结果由小到大排列)
// 然后找出第k个位置的数即可

#pragma once

#include <vector>
#include "TreeNode.h"

using std::vector;
using tree::TreeNode;

class Solution61 {
public:
    TreeNode* kth_node(TreeNode* root, int k)
    {
        if (!root) return root;
        return in_order(root, k);
    }

public:
    TreeNode* in_order(TreeNode* root, int& k)
    {
        TreeNode* ret = nullptr;
        if (root->left)
            ret = in_order(root->left, k);
        if (ret == nullptr)
        {
            if (k == 1)
                ret = root;
            --k;
        }
        if (ret == nullptr && root->right)
            ret = in_order(root->right, k);
        return ret;
    }
};