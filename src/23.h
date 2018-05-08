/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 21:07:10 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 21:20:33
 * 题目
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
 * 否为该栈的弹出顺序
 */

// 思路
// 判断一个序列是不是栈的弹出序列的规律如下
// 如果下一个弹出的数字不在栈顶，我们把延展序列中还没有入栈的数字
// 压入辅助栈，直到把下一个需要弹出的数字压入栈顶为止。如果所有
// 数字都压入栈了仍然没有找到下一个要弹出的数字，那么该序列不可能
// 是一个弹出序列

#pragma once

#include <stack>
#include <vector>

using std::stack;
using std::vector;

class Solution23 {
public:
    bool is_pop_order(const vector<int>& push_v, const vector<int>& pop_v)
    {
        bool flag = false;
        if (push_v.empty() || pop_v.empty() || push_v.size() != pop_v.size())
            return flag;

        stack<int> s;
        vector<int>::const_iterator p1 = push_v.begin();
        vector<int>::const_iterator p2 = pop_v.begin();

        while (p2 != pop_v.end())
        {
            while (s.empty() || s.top() != *p2)
            {
                if (p1 == push_v.end())
                    break;
                s.push(*p1);
                ++p1;
            }
            if (s.top() != *p2)
                break;
            s.pop();
            ++p2;
        }

        if (s.empty() && p2 == pop_v.end())
            flag = true;

        return flag;
    }
};
