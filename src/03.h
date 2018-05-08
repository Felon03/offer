/*
 * @Author: FreedomLy 
 * @Date: 2018-04-23 21:01:41 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 21:48:50
 * 题目
 * 输入一个链表的头节点，从尾到头反过来打印出每个节点的值
 */

// 思路
// 要求从尾到头打印节点值，我们可以遍历每个节点，然后逆序打印
// 这是个典型的LIFO(后进先出)，我们可以采用栈来实现
// 和栈的思路类似，我们也可以采用递归的方法，需要注意递归层数

#pragma once

#include <vector>
#include <iostream>
#include "ListNode.h"

using std::vector;
using std::cout;
using std::endl;
using list::ListNode;

// // 节点定义
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) { }
// };


class Solution03 {
public:
    vector<int> reverse_print(ListNode* head)
    {
        vector<int> ret;
        helper1(head, ret);
        return ret;
    }

    // 辅助函数，打印输出结果
    void print(const vector<int>& v)
    {
        for (const auto e : v)
            cout << e << " ";
    }

private:
    // 类似与stack的操作，每接受一个新元素，就插入到最前面
    void helper0(ListNode* head, vector<int>& v)
    {
        if (!head)
            return;
        while (head)
        {
            v.insert(v.begin(), head->val);
            head = head->next;
        }
    }

    // 递归
    void helper1(ListNode* head, vector<int>& v)
    {
        if (!head)
            return;
        helper1(head->next, v);
        v.emplace_back(head->val);
    }
};