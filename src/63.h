/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 21:14:33 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 21:54:10
 * 题目
 * 给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值
 */

// 思路
// 采用一个双端队列来保存窗口中最大元素的下标，最大元素的下标在队列
// 最前面。当最大值的下标与新的值的下标超过给定窗口大小时，将队列的
// 首位元素出队，使其后面的元素称为新的最大值的下标

#pragma once

#include <vector>
#include <deque>

using std::vector;
using std::deque;

class Solution63 {
public:
    vector<int> max_in_windows(const vector<int>& nums, size_t size)
    {
        vector<int> max;
        if (nums.size() >= size && size >= 1)
        {
            deque<size_t> index;

            for (size_t i = 0; i < size; ++i)
            {
                while (!index.empty() && nums[i] >= nums[index.back()])
                    index.pop_back();
                index.push_back(i);
            }

            for (size_t i = size; i < nums.size(); ++i)
            {
                max.emplace_back(nums[index.front()]);

                while (!index.empty() && nums[i] >= nums[index.back()])
                    index.pop_back();
                if (!index.empty() && index.front() <= (i - size))
                    index.pop_front();
                
                index.push_back(i);
            }
            max.emplace_back(nums[index.front()]);
        }
        return max;
    }
};
