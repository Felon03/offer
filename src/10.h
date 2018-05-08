/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 13:48:31 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 13:56:30
 * 题目
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形
 * 请问用n个2*1的小矩形无重叠的覆盖一个2*n的大矩形，总共有多少种方法
 */

// 思路
// 其实和青蛙跳台阶一样，也是斐波那契数列
// 假设有一个2*1的矩形和一个2*8的矩形
// 我们现把2*8的覆盖方法记为f(8)。用第一个1*2小矩形去覆盖大矩形的// 最左边有两个选择，竖着放或者横着放。当竖着放的时候，右边还剩下
// 2*7的区域，这种情况下的覆盖方法即为f(7)；接下来考虑横着放的情况
// 当1*2的小矩形横着放左上角的时候，左下角必须横着放一个1*2的小矩形
// 而右边还剩下2*6的区域，这种情况下的覆盖方法即为f(6)，因此
// f(8) = f(7) + f(6)，所以仍然是斐波那契数列

#pragma once

#include<vector>

using std::vector;

class Solution10 {
public:
    int rect_cover(int n)
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
