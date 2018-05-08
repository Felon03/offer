/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 21:21:45 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 21:26:52
 * 题目
 * 从上往下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序
 * 打印，即层次遍历
 */

// 思路
// 层次遍历可以用一个队列来保存元素，当有元素出队时，检查其是否有
// 孩子节点，如果有，就将孩子节点入队

#pragma once

#include "TreeNode.h"
#include <queue>
#include <vector>

using tree::TreeNode;
using std::vector;
using std::queue;

class Solution24 {
public:
    vector<int> level_traverse(TreeNode* root)
    {
        if (!root) return {};

        queue<TreeNode*> nodes;
        vector<int> ret;
        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode* tmp = nodes.front();
            ret.emplace_back(tmp->val);
            nodes.pop();
            if (tmp->left)
                nodes.push(tmp->left);
            if (tmp->right)
                nodes.push(tmp->right);
        }
        
        return ret;
    }
};
