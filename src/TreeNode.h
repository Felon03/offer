/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 21:06:57 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 19:45:15
 * 二叉树节点定义
 */

#pragma once
#include <iostream>
#include <queue>

using std::cout;
using std::queue;

namespace tree {
    
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

void destroy_tree(TreeNode* root)
{
    if (root != nullptr)
    {
        destroy_tree(root->left);
        destroy_tree(root->right);
        delete root;
        root = nullptr;
    }
}

// 层次遍历二叉树并输出
void level_order(TreeNode* root)
{
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* tmp = q.front();
        q.pop();
        cout << tmp->val << " ";
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
}

// 先序遍历二叉树
void pre_order(TreeNode* root)
{
    if (!root) return;
    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}

// 中序遍历二叉树
void in_order(TreeNode* root)
{
    if (!root) return;
    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}

// 后序遍历二叉树
void post_order(TreeNode* root)
{
    if (!root) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->val << " ";
}

// 层次遍历二叉树
// void level_order(TreeNode* root)
// {
//     print(root);
// }

// Tree node has parent
struct TreeNodeP {
    int val;
    TreeNodeP* left;
    TreeNodeP* right;
    TreeNodeP* parent;

    TreeNodeP(int x)
        : val(x), left(nullptr), right(nullptr), parent(nullptr) { }
};

void destroy_tree_p(TreeNodeP* root)
{
    if (root != nullptr)
    {
        destroy_tree_p(root->left);
        destroy_tree_p(root->right);
        delete root;
        root = nullptr;
    }
}

}



