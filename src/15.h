/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 09:19:39 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 09:55:23
 * 题目
 * 输入一个数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数
 * 位于数组的前半部分，所有偶数位于后半部分
 */

// 思路
// 不保证元素有序的解法
// 设置两个迭代器，分别指向第一个元素和最后一个元素
// 如果第一个迭代器所指元素为偶数且第二个迭代器所指
// 元素为奇数，则交换两个迭代器的值，直到两个迭代器
// 相同或交叉

// 保证元素有序的解法
// 设置一个迭代器，从头开始遍历元素，如果碰到偶数
// 就将其与后面的元素两两交换至尾端

#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

class Solution15 {
public:
    void reorder_array(vector<int>& arr)
    {
        if (arr.empty()) return;

        vector<int>::iterator p1 = arr.begin();
        vector<int>::iterator p2 = arr.end();
        --p2;

        while (p1 < p2)
        {
            if (((*p1) & 0x01) == 0 && ((*p2) & 0x01) == 1)
                iter_swap(p1++, p2--);
            else if (((*p1) & 0x01) == 0)
                --p2;
            else
                ++p1;
        }
    }

    void stable_reorder_array(vector<int>& arr)
    {
        int len = arr.size();
        int end = len;

        for (int i = 0; i < end; ++i)
        {
            if ((arr[i] & 0x01) == 0)
            {
                int j = i;
                for (; j < len - 1; ++j)
                    std::swap(arr[j], arr[j + 1]);
                --end, --i; // --i是因为交换后的数字还可能为偶数
            }
        }
    }

    template <typename Fn>
    void stable_reorder_array(vector<int>& arr, Fn fn)
    {
        int len = arr.size();
        int end = len;

        for (int i = 0; i < end; ++i)
        {
            if (fn(arr[i]))
            {
                int j = i;
                for (; j < len - 1; ++j)
                    std::swap(arr[j], arr[j + 1]);
                --end, --i;
            }
        }
    }
};