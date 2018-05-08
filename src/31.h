/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 19:03:42 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 19:20:02
 * 题目
 * 输入n个整数，找出其中最小的k个数
 */

// 思路
// 可以采用二叉树结构或者大顶堆，将其节点个数设为k
// 依次遍历数组，如果所遍历整数小于堆/树的最大值，则插入，
// 同时删除堆/树中的最大元素，保持节点个数不变。当遍历完
// 全后，在堆/树中的元素就是最小的k个数
// 时间复杂度为O(nlogk) 且不需要改变原数组元素的位置

#pragma once

#include <set>
#include <functional>
#include <vector>

using std::vector;
using std::multiset;    // multiset采用红黑树结构，因此采用它

class Solution31 {
public:
    vector<int> get_least_k_nums(const vector<int>& nums, int k)
    {
        multiset<int, std::greater<int>> ms;
        if (nums.empty() || k == 0) return { };

        for (int e : nums)
        {   
            // 当树中的元素没到k个时
            if (ms.size() < static_cast<size_t>(k))
                ms.insert(e);
            else
            {
                auto it = ms.begin();
                // 如果新插入的元素比根节点小
                if (e < *it)
                {
                    ms.erase(it);
                    ms.insert(e);
                }
            }
        }
        vector<int> ret(ms.begin(), ms.end());
        sort(ret.begin(), ret.end());
        return ret;
    }
};
