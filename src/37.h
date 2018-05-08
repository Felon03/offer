/*
 * @Author: FreedomLy 
 * @Date: 2018-04-28 15:48:00 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-28 16:31:23
 * 题目
 * 在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字
 * 组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数
 */

// 思路
// 1. 采用逐一遍历的方法，复杂度为(O(n^2))
// 2. 先把素组分隔成子数组，先统计出子数组内部的逆序对的数目，
//    然后再统计两个相邻子数组之间的逆序对数目。在统计过程中
//    还需要对数组进行排序。排序过程为归并排序
#pragma once

#include <vector>

using std::vector;

class Solution37 {
public:
    int inverse_pairs(vector<int>& data)
    {
        if (data.empty()) return 0;

        vector<int> copy(data);
        int count = helper(data, copy, 0, static_cast<int>(data.size() - 1));
        return count;
    }

private:
    int helper(vector<int>& data, vector<int>& copy, int begin, int end)
    {
        if (begin == end)
        {
            copy[begin] = data[begin];
            return 0;
        }    

        int len = (end - begin) / 2;
        // 计算后面的时候，保证计算过的部分已经排序了，因此 copy 和 data 位置互换
        int left = helper(copy, data, begin, begin + len);
        int right = helper(copy, data, begin + len + 1, end);

        // i 初始化为前半段最后一个数字的下标
        int i = begin + len;
        // j 初始化为后半段最后一个数字的下标
        int j = end;
        int index_copy = end;
        int count = 0;
        while (i >= begin && j >= begin + len + 1)
        {
            if (data[i] > data[j])
            {
                copy[index_copy--] = data[i--];
                count += j - begin - len;
            }
            else
            {
                copy[index_copy--] = data[j--];
            }
        }

        for (; i >= begin; --i)
            copy[index_copy--] = data[i];

        for (; j >= begin + len + 1; --j)
            copy[index_copy--] = data[j];

        return left + right + count;
    }

};

