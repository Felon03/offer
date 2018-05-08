/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 19:25:05 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 19:49:54
 * 题目
 * 实现一个函数，按照之字形顺序打印二叉树，即第一行按照从左至右的
 * 顺序，第二行按照从右至左的顺序，第三行再按照从左至右的顺序。
 * 以此类推
 */

// 思路
// 对二叉树进行层次遍历，当层数为奇数是，从左至右保存
// 当层数为偶数时，从右至左保存
#pragma once

#include <queue>
#include <vector>
#include <algorithm>
#include "TreeNode.h"

using std::queue;
using std::vector;
using tree::TreeNode;

class Solution59 {
public:
    vector<vector<int>> print(TreeNode* root)
    {
        if (!root) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ret;

        int lv = 1;

        while (!q.empty())
        {
            vector<int> v;
            size_t sz = q.size();
            for (size_t i = 0; i < sz; ++i)
            {
                TreeNode* n = q.front();
                q.pop();
                v.emplace_back(n->val);
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
            if ((lv & 1) == 0)
                std::reverse(v.begin(), v.end());
            ret.emplace_back(v);
            ++lv;
        }
        return ret;
    }
};