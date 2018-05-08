/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 22:03:39 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 22:22:49
 * 题目
 * 在一个长度为n的数组里的所有数字都在0到n-1的范围内
 * 数组中某些数字是重复的，但不知道有几个数字重复了，
 * 也不知道每个数字重复了几次。请找出任意一个重复的数字
 */

// 思路
// 从头到尾遍历数组，当遍历到下表为i的数字时，首先比较这个数字(m)
// 是否和i相等。如果是，接着遍历下一个数组；否则，再拿它和第m个数字
// 作比较。如果它和第m个数字相等，就找到了一个重复的数字(该数字在
// 下标为i和m的位置都出现了)。如果它和第m个数字不相等，就交换第i
// 个数字和第m个数字，把m放到属于它的位置。接下来再重复这个比较、
// 交换的过程，直到发现一个重复的数字或者遍历完数组
#pragma once
#include <vector>

using std::vector;

class Solution50 {
public:
    bool duplicate(vector<int>& nums, int& dup)
    {
        if (nums.empty()) return false;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0 || nums[i] > static_cast<int>(nums.size()) - 1)
                return false;
        }

        for (size_t i = 0; i < nums.size(); ++i)
        {
            while (nums[i] != static_cast<int>(i))
            {
                if (nums[i] == nums[nums[i]])
                {
                    dup = nums[i];
                    return true;
                }

                std::swap(nums[i], nums[nums[i]]);
            }
        }
        
        return false;
    }
};

