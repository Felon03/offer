/*
 * @Author: FreedomLy 
 * @Date: 2018-05-03 19:04:42 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-03 19:20:16
 * 题目
 * 给定一个数组A[0,1,...,n-1]，请构建一个数组B[0,1,...,n-1]，
 * 其中 B 中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
 * 不能使用除法
 */

// 思路
// 分两次循环，第一次循环都是 B 的值乘以 A[i-1]
// 当循环遍历结束时，B中的最后一个元素已经满足题目的条件，然后我们从
// 最后的元素前一个开始向前遍历，每一次都乘以A[i+1]，便利结束后所有
// 的位置就均满足题目的要求了
#pragma once
#include <vector>

using std::vector;

class Solution51 {
public:
    vector<int> multiply(const vector<int>& A)
    {
        if (A.empty()) return {};

        vector<int> res{1};

        for (size_t i = 1; i < A.size(); ++i)
            res.emplace_back(res.back() * A[i - 1]);

        int tmp = 1;
        for (int i = A.size() - 2; i >= 0; --i)
        {
            tmp *= A[i + 1];
            res[i] *= tmp;
        }

        return res;
    }
};
