/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 15:05:15 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 15:48:43
 * 题目一
 * 输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的
 * 和正好是s。如果有多对数字的和等于s，输出两个数的乘积最小的
 * 
 * 题目二
 * 输入一个正整数s，打印出所有和为s的连续整数数列(至少含有两个数)
 */

// 思路一
// 我们可以设置两个迭代器，分别指向第一个元素和最后一个元素
// 如果迭代器所指的值相加大于s，则后面的迭代器前移一位；否则，
// 前面的迭代器后移一位。直到所指值的和为s或者后面的迭代器小于
// 前面的迭代器

// 思路二
// 我们可以设置两个指针，最开始分别指向第一位和第二位，计算所指
// 整数区间的和。如果和小于s，第二个指针后移，如果大于s，第一个
// 指针后移。当第一个指针超过第二个指针时，表示没有可行解了，则
// 退出循环
#pragma once

#include <vector>

using std::vector;

class Solution42 {
public:
    vector<int> find_number_with_sum(const vector<int>& nums, int k)
    {
        vector<int>::const_iterator first = nums.begin();
        vector<int>::const_iterator last = nums.end() - 1;
        vector<int> ret;
        int product = INT_MAX;
        while(std::distance(first, last) > 0)
        {
            if (*first + *last > k)
                --last;
            else if (*first + *last < k)
                ++first;
            else
            {
                if (*first * *last < product)
                {
                    ret.clear();
                    ret.emplace_back(*first);
                    ret.emplace_back(*last);
                    product = *first * *last;
                }
                ++first;
            }
        }
        return ret;
    }

    vector<vector<int>> find_continuous_seq(int k)
    {
        vector<vector<int>> ret;
        int p1 = 1, p2 = 2;

        while (p2 > p1)
        {
            int cur_sum = (p1 + p2) * (p2 - p1 + 1) >> 1;
            if (cur_sum < k)
                ++p2;
            if (cur_sum == k)
            {
                vector<int> tmp;
                for (int i = p1; i <= p2; ++i)
                    tmp.emplace_back(i);
                ret.emplace_back(tmp);
                ++p1;
            }
            if (cur_sum > k)
                ++p1;
        }
        return ret;
    }
};
