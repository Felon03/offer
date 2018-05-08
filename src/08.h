/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 10:42:35 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 10:50:17
 * 题目
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级
 * 求该青蛙跳上n级的台阶总共有多少种跳法
 */

// 思路
// 与斐波那契数列类似，假设有n级台阶，如果第一次只跳一阶，则跳法数目
// 等于剩下n-1阶的跳法数目；如果第一次跳二阶，则跳法数目等于剩下的
// n-2阶的跳法数目。因此，总的跳法数目为：f(n-1) + f(n-2)，形式上
// 和斐波那契数列相同
// 需要注意的是
// 当 n = 1 时，跳法只有一种
// 当 n = 2 时，跳法有两种

#pragma once

#include <vector>

using std::vector;

class Solution08 {
public:
    int jump_floor(int n)
    {
        vector<int> v{0, 1, 2};
        if (n < 3) return v[n];
        
        int f1 = v[1], f2 = v[2], f = 0;
        for (int i = 3; i <= n; ++i)
        {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
        return f;
    }
};
