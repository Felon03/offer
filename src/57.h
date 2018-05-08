/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 16:09:54 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 19:20:29
 * 题目
 * 给定一棵二叉树和其中的一个节点，找出中序遍历顺序中的下一个节点
 * 树中的节点除了有两个分别指向左右子节点的指针外，还有指向父节点
 * 的指针
 */

// 思路
// 如果一个节点有右子树，那么它的下一个节点就是右子树中的最左子节点
// 如果一个节点没有右子树，则下一个节点就是其父节点
// 如果该节点没有右子树，且为父节点的右子节点，我们可以沿着父节点向// 上遍历，直到找到一个节点且该节点为其父节点的左子节点，如果这样的// 节点存在，则它的父节点就是下一个节点

#pragma once

#include "TreeNode.h"

using tree::TreeNodeP;

class Solution57 {
public:
    TreeNodeP* get_next(TreeNodeP* node)
    {
        if (!node) return node;

        TreeNodeP* next = nullptr;

        if (node->right)
        {
            TreeNodeP* right = node->right;
            while (right->left)
                right = right->left;
            next = right;
        }
        else if (node->parent)
        {
            TreeNodeP* cur = node;
            TreeNodeP* parent = node->parent;
            while (parent && cur == parent->right)
            {
                cur = parent;
                parent = parent->parent;
            }
            next = parent;
        }
        return next;
    }
};