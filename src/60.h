/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 19:49:12 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 20:06:11
 * 题目
 * 实现两个函数，分别用来序列化和反序列化二叉树
 */

// 思路
// 采用前序遍历，当左右子节点为nullptr时，采用'#'代替

#pragma once

#include <string>
#include <sstream>
#include "TreeNode.h"

using std::string;
using std::ostringstream;
using std::istringstream;
using tree::TreeNode;


class Solution60 {
public:
    const string serialize(TreeNode* root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(const string& str)
    {
        istringstream in(str);
        return deserialize(in);
    }


private:
    void serialize(TreeNode* root, ostringstream& out)
    {
        if (root)
        {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in)
    {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
