/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 10:10:38 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 10:37:20
 * 题目
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
 * 要求不能创建任何新节点，只能调整树中节点指针的指向
 */

// 思路
// 利用二叉树的中序遍历可以得到从大到小的顺序

#pragma once

#include "TreeNode.h"
#include <iostream>

using BinaryTreeNode = TreeNode;

class Solution28 {
public:
    BinaryTreeNode* convert(BinaryTreeNode* root)
    {
        // 记录双向链表的最后一个节点
        BinaryTreeNode* last_node = nullptr;
        // 递归转换为双向链表
        helper(root, &last_node);

        // 此时头节点指向双向链表的尾节点
        BinaryTreeNode* head = last_node;
        // 左移，直到头节点
        while (head && head->left)
            head = head->left;
        
        return head;
    }

    // 转换后其实是个双向链表，按照链表清空的方法
    void destroy_double_list(BinaryTreeNode* head)
    {
        while (head)
        {
            // right 相当于 next
            BinaryTreeNode *tmp = head->right;

            delete head;
            head = nullptr;

            head = tmp;
        }
    }

    void print_double_list(BinaryTreeNode* head)
    {
        if (!head)
            return;
        BinaryTreeNode *p = head;
        while (p)
        {
            std::cout << p->val << " ";
            p = p->right;
        }
        // delete p;
        // p = nullptr;
    }

private:
    void helper(BinaryTreeNode* root, BinaryTreeNode** last_node)
    {
        if (!root) return;

        BinaryTreeNode* current = root;
        // 递归左子树
        if (current->left)
            helper(current->left, last_node);

        // 左指针
        current->left = *last_node;
        // 右指针
        if (*last_node)
            (*last_node)->right = current;

        // 更新尾节点
        *last_node = current;

        // 递归右子树
        if (current->right)
            helper(current->right, last_node);
    }
};