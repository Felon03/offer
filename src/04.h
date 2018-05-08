/*
 * @Author: FreedomLy 
 * @Date: 2018-04-23 21:51:29 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 15:01:27
 * 题目
 * 输入某二叉树的前序遍历和中序遍历，请重建该二叉树
 * 假设输入的前序遍历和中序遍历的结果都不含重复的数字
 */

// 思路
// 在二叉树的前序序列中，第一个数字总是树的根节点的值
// 但在中序序列中，根节点的值在序列的中间，左子树的节
// 点值位于跟节点值的左边，而右子树的节点值位于根节点
// 值的右边。分别找到左右子树的范围，然后可以用递归的
// 方法，各自求左右子树的根节点，以此类推

#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"

using std::vector;
using std::queue;
using std::cout;
using std::endl;
using tree::TreeNode;

// // 二叉树节点定义
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
// };

class Solution04 {
public:
    TreeNode* rebuild_tree(const vector<int>& pre, const vector<int>& in)
    {
        if (pre.empty() || in.empty())
            return nullptr;
        
        // 前序遍历第一个节点就是根节点
        TreeNode *root = new TreeNode(pre[0]);
        // 查找根节点在中序遍历中的位置，中序遍历中，根节点左边为左子树，右边为右子树
        int root_pos = -1;
        for (size_t i = 0; i < in.size(); ++i)
        {
            if (in[i] == root->val)
            {
                root_pos = i;
                break;
            }
        }

        if (root_pos == -1)
        {
            cout << "Invalid Input!" << endl;
            return nullptr;
        }

        // 重建左子树
        vector<int> pre_left(pre.begin() + 1, pre.begin() + root_pos + 1);
        vector<int> in_left(in.begin(), in.begin() + root_pos);
        root->left = rebuild_tree(pre_left, in_left);

        // 重建右子树
        vector<int> pre_right(pre.begin() + root_pos + 1, pre.end());
        vector<int> in_right(in.begin() + root_pos + 1, in.end());
        root->right = rebuild_tree(pre_right, in_right);

        return root;
    }

    // 层次遍历二叉树并输出
    void print(TreeNode* root)
    {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp = nullptr;
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            cout << tmp->val << " ";
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
            // delete tmp;
            // tmp = nullptr;
        }
        tmp = nullptr;
    }

    // 释放二叉树节点
    // void destroy_tree(TreeNode*& root)
    // {
    //     if (root != nullptr)
    //     {
    //         destroy_tree(root->left);
    //         destroy_tree(root->right);
    //         delete root;
    //         root = nullptr;
    //     }
    // }
    // void delete_tree(TreeNode*& root)
    // {
    //     if (!root) return;
    //     delete_tree(root->left);
    //     delete_tree(root->right);
    //     delete root;
    //     root = nullptr;
    // }
};