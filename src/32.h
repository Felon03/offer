/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 19:21:44 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 19:28:45
 * 题目
 * 输入一个整数数组，数组里有正数也有负数。数组中一个或连续多个整数
 * 组成一个子数组。求所有子数组和的最大值。要求时间复杂度为O(n)
 */

// 思路
// 遍历整个数组，每遍历一个元素，就加上该元素对应的值，如果
// 相加得到的结果大于当前元素值，则继续累计，并保存当前最大值
// 如果小于当前元素，则前面累计的数值抛弃，从当前元素开始重新累计
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution32 {
public:
    int maximum_subarray(const vector<int>& nums)
    {
        if (nums.empty()) return 0;
        
        int sum_max = INT_MIN;
        int sum = 0;
        for (int e : nums)
        {
            if (sum <= 0)
                sum = e;
            else
                sum += e;
            sum_max = std::max(sum_max, sum);
        }

        return sum_max;
    }

    int maximum_subarray_dp(const vector<int>& nums)
    {
        int sum = INT_MIN, tmp = 0;
        for (int num : nums)
        {
            tmp = std::max(tmp + num, num);
            sum = std::max(tmp, sum);
        }
        return sum;
    }
};