/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 19:36:51 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 20:24:49
 * 题目
 * 输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数
 */

// 思路 
// 参考博客
// https://www.cnblogs.com/lengender-12/p/6876897.html
// https://blog.csdn.net/yi_afly/article/details/52012593
// 如果第i位(自右向左，从1开始标号)上的数字是0，则第i位可能出现1的
// 次数由更高位决定(若没有更高位，则视高位为0)，等于更高位数乘以当前
// 位数的权重(10^(i-1))
// 如果第i位上的数字为1，则第i位上出现1的次数不仅受高位影响，还受
// 低位影响(若没有低位，视低位为0)，等于更高位数乘以当前位数的权重
// (10^(i-1)+(低位数+1))
// 如果第i位上的数字大于1，则第i位上可能出现1的次数仅由更高位决定
// (若没有更高位，视高位为0)，等于(更高位数+1)乘以当前位数的权重
// (10^(i-1))
#pragma once

#include <string>

using std::string;

class Solution33 {
public:
    int number_of_1_between_1_and_n(int n)
    {
        if (n < 1) return 0;
        if (n < 9) return 1;

        int high = 0, k = 0, cur = 0, count = 0;

        for (int i = 1; (k = n / i); i *= 10)
        {
            high = k / 10;
            count += high * i;

            cur = k % 10;
            if (cur > 1)
                count += i;
            else if (cur == 1)
                count += n - k * i + 1;
        }
        return count;
    }

    // 利用 STL 中的 count 计算
    int count_1(int n)
    {
        int cnt = 0;
        while (n)
        {
            string s = std::to_string(n);
            cnt += count(s.begin(), s.end(), '1');
            --n;
        }

        return cnt;
    }
};