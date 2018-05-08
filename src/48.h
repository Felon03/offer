/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 21:31:07 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-03 21:06:13
 * 题目
 * 实现一个函数，求两数之和，要求在函数内不得使用四则运算符(+,-,*,/)
 */

// 思路
// 可以考虑二进制的位运算
// 在二进制中，有以下几种情况：
// 0+0=0, 0+1=1, 1+0=1, 1+1=10
// 如果不考虑进位，这些加法的结果和异或是一样的
// 接下来就可以考虑进位，只有1+1会产生进位，可以想象为1和1做与运算
// 然后左移一位得到10，接着把异或个与运算的结果相加就可以求出有进位
// 情况的值。反复上述过程，指导不产生进位为止
#pragma once
class Solution48 {
public:
    int add(int a, int b)
    {
        int sum = a ^ b;
        int carry = a & b << 1;
        while (carry)
        {
            int a = sum;
            int b = carry;
            sum = a ^ b;
            carry = (a & b) << 1;
        }
        return sum;
    }

    int add_recursive(int a, int b)
    {
        return b == 0 ? a : add_recursive(a ^ b, (a & b) << 1);
    }
};
