/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 15:42:45 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 15:53:00
 * 题目
 * 数组中有一个数字出现次数超过数组长度的一半，请找出这个数字
 */

// 思路
// 我们可以设置一个 index(默认为0) 和一个 count(默认为1) 
// 分别用于记录某个数出现的下标以及出现的次数。
// 遍历数组中的数，如果当前遍历的数值不等于index所对应的数
// 则count-1，否则count+1。当count为0时，将 index 设置为
// 当前遍历数字的下标，并将 count 重置，指导遍历完数组，得到
// 的 index 就指向出现次数最多的数，然后再判断其出现次数是否
// 大于数组长度的一半

#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution30 {
public:
    int more_than_half_num(const vector<int>& nums)
    {
        int index = 0;
        for (size_t count = 1, i = 1; i < nums.size(); ++i)
        {
            nums[index] == nums[i] ? ++count : --count;
            if (count == 0)
            {
                index = i;
                count = 1;
            }
        }

        size_t cnt = std::count(nums.begin(), nums.end(), nums[index]);

        return cnt > (nums.size() >> 1) ? nums[index] : -1;
    }
};
