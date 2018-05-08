/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 14:42:46 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 14:56:49
 * 题目
 * 一个整数数组里除了两个数之外，其他的数字都出现了两次
 * 请写程序找出这两个只出现一次的数字
 */

// 思路
// 使用一个map来保存每个数组出现的次数，遍历两次即可得到答案
// 或者使用二进制位运算
// 如果两个数相同，则它们的异或为0(即a^a=0)
// 那么我们把数组中所有的数按顺序异或以后，就只有两个值出现
// 一次的数字不为0，我们取异或后的二进制从右开始第一位不为0的
// 位数，这样就可以把原数组的数分为两组，第一个数组中每个数字
// 的该位均为1，第二个数组中每个数字的该位均为0
// 分组后的每组数中只有一个数字出现了一次，其他出现了两次
#pragma once

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution41 {
public:
    vector<int> single_number_i(const vector<int>& data)
    {
        if (data.empty()) return {};
        vector<int> res;
        unordered_map<int, int> m;
        for (int e : data)
            m[e]++;
        for (auto p : m)
            if (p.second == 1)
                res.emplace_back(p.first);
        return res;
    }

    vector<int> single_number_ii(const vector<int>& nums)
    {
        if (nums.empty()) return {};
        int diff = 0;
        // find two different nums' XOR
        for (int num : nums) diff ^= num;
        // get the last bit set 1 
        // for more detail:
        // ref:https://leetcode.com/problems/single-number-iii/discuss/68900/Accepted-C++Java-O(n)-time-O(1)-space-Easy-Solution-with-Detail-Explanations
        diff &= -diff;

        int num1 = 0, num2 = 0;
        for (int num : nums)
        {
            if ((num & diff) == 0)
                num1 ^= num;
            else
                num2 ^= num;
        }
        return {num1, num2};
    }
};
