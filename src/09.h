/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 11:04:50 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 12:20:57
 * 题目
 * 一只青蛙一次可以跳上一级台阶，也可以跳上两级...它也可以跳上n级。
 * 求该青蛙跳上一个n级台阶总共有多少种跳法
 */

// 思路
// 和前面的跳台阶类似
// 但是要注意的是每一次的结果是数列前n-1项的总和(假设当前为第n阶)在
// 加上跳上该台阶的次数1，即
// f(n) = f(1) + f(2) + ... + f(n-1) + 1
// 也可以通过数学归纳法得： f(n) = 2^(n-1)

#pragma once

#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

class Solution09 {
public:
    int jump_floor_ii(int n)
    {
        vector<int> v{0, 1};
        if (n < 2) return v[n];

        int f = 0;
        for (int i = 2; i <= n; ++i)
        {
            f = accumulate(v.begin(), v.end(), 0) + 1;
            v.emplace_back(f);
        }
        return f;
    }
};
