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
#include <stack>

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

// 先序遍历非递归
void pre_order_iter(TreeNode* root)
{
    stack<TreeNode*> stk;
    TreeNode* p = root;

    while (p || !stk.empty())
    {
        while (p)
        {
            cout << p->val << " ";
            stk.push(p);
            p = p->left;
        }
        if (!stk.empty())
        {
            p = stk.top();
            stk.pop();
            p = p->right;
        }
    }
}

// 中序遍历二叉树
void in_order(TreeNode* root)
{
    if (!root) return;
    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}

// 中序遍历非递归
void in_order_iter(TreeNode* root)
{
    stack<TreeNode*> stk;
    TreeNode* p = root;
    
    while (p || !stk.empty())
    {
        while (p)
        {
            stk.push(p);
            p = p->left;
        }
        if (!stk.empty())
        {
            p = stk.top();
            cout << p->val << " ";
            stk.pop();
            p = p->right;
        }
    }
}

// 后序遍历二叉树
void post_order(TreeNode* root)
{
    if (!root) return;
    post_order(root->left);
    post_order(root->right);
    cout << root->val << " ";
}

// 后序遍历非递归
void post_order_iter(TreeNode* root)
{
    if (!root) return;
    stack<TreeNode*> stk;
    TreeNode* cur;
    TreeNode* pre = nullptr;
    stk.push(root);

    while (!stk.empty())
    {
        cur = stk.top();
        if ((!cur->left && !cur->right) || (pre && (pre == cur->left || pre == cur->right)))
        {
            // 如果当前节点没有左右孩子或者孩子节点已经被访问过
            cout << cur->val << " ";
            stk.pop();
            pre = cur;
        }
        else
        {
            if (cur->right)
                stk.push(cur->right);
            if (cur->left)
                stk.push(cur->left);
        }
    }
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



