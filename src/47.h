/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 21:14:27 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 21:28:43
 * 题目
 * 求1+2+...+n，要求不能使用乘除法、for、while、if、else、switch、
 * case等关键字级条件判断语句(A?B:C)
 */


// 思路
// 短路求值，递归思想

#pragma once

class Solution47 {
public:
    int get_sum(int n)
    {
        int ans = n;
        ans && (ans += get_sum(n - 1));
        return ans;
    }
};
