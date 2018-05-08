/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 14:04:40 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 14:36:17
 * 题目
 * 请实现一个函数，输入一个整数，输出该整数二进制表示中1的个数
 */

// 思路
// 把一个整数减去1，再和原整数做与运算，会把该整数最右边的一个1变成0
// 那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的操作

#pragma once

class Solution11 {
public:
    int number_of_1(int n)
    {
        int count = 0;
        while (n)
        {
            ++count;
            n &= (n - 1);
        }

        return count;
    }

    // 常规解法
    int number_of_ones(int n)
    {
        int count = 0;
        unsigned int flag = 1;
        while (flag)
        {
            if (n & flag)
                ++count;
            flag <<= 1;
        }
        return count;
    }
};
