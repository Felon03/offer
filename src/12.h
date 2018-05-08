/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 14:41:43 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 14:59:29
 * 题目
 * 实现函数double power(double base, int exponent)
 * 求 base 的 exponent 次方
 */

// 思路
// 可以递归求解
// 当我们求base^32时，我们可以将其看作是base^16 * base^16
// 而base^16又可以看作是base^8 * base^8 ..., 以此类推
// 我们可以得到
// a^n = 
// 1. a^(n/2) * a^(n/2)     n 为偶数
// 2. a^(n/2) * a^(n/2) * a n为奇数

#pragma once

class Solution12 {
public:
    double power(double base, int exponent)
    {
        if (equal(base, 0)) return 0;
        if (exponent == 0) return 1;
        if (exponent < 0)
            return (1 / base) * power(1 / base, -(exponent + 1));

        if ((exponent & 0x01) == 0) // exponent为偶数
        {
            double tmp = power(base, exponent >> 1);
            return tmp * tmp;
        }
        else    // exponent为奇数
        {
            double tmp = power(base, exponent >> 1);
            return base * tmp * tmp;
        }
    }

private:
    bool equal(double num1, double num2)
    {
        return (num1 - num2) > -0.0000001 && (num1 - num2) < 0.0000001;
    }
};

