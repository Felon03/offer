/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 10:33:44 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 10:38:15
 * 题目
 * 写一个函数，输入 n，求斐波那契(Fibonacci)数列的第n项
 */

#pragma once

#include <vector>

using std::vector;

class Solution07 {
public:
    long long fibonacci(unsigned n)
    {
        vector<int> res{0, 1};

        if (n < 2)
            return res[n];
        
        long long f1 = res[0], f2 = res[1];
        long long fib = 0;
        for (unsigned i = 2; i <= n; ++i)
        {
            fib = f1 + f2;
            f1 = f2;
            f2 = fib;
        }
        return fib;
    }
};
