/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 20:41:46 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 20:55:21
 * 题目
 * 如何得到一个数据量的中位数？如果从数据流中读出及数个数值，那么
 * 中位数就是所有数值排序之后位于中间的数值；如果从数据中读出偶数
 * 个数值，那么中位数就是所有数字排序之后中间两个数的平均值
 */

// 思路
// 可以发现一个读入若干数值后的数组，将会被中位数分为左右两部分
// 且左边的数都小于中位数，右边的数都大于中位数，我们可以想到用
// 堆来管理中位数左右两边的数值，其中左边采用的是大顶堆，右边采
// 用的是小顶堆

#pragma once

#include <algorithm>
#include <vector>
#include <functional>

using std::vector;

template <typename T>
class Solution62 {
public:
    void insert(T num)
    {   
        // 读入的数字的数量为偶数
        if (((min.size() + max.size()) & 1) == 0)
        {
            // 如果本应该写入小顶堆的数比大顶堆最大的还小
            // 我们应该把新的数值插入大大顶堆，然后将大顶堆
            // 的最大值写入最小堆，反之亦然
            if (max.size() > 0 && max[0] > num)
            {
                max.emplace_back(num);
                std::push_heap(max.begin(), max.end(), std::less<T>());
                num = max[0];
                std::pop_heap(max.begin(), max.end(), std::less<T>());
                max.pop_back();
            }
            min.emplace_back(num);
            std::push_heap(min.begin(), min.end(), std::greater<T>());
        }
        else    // 奇数
        {
            if (min.size() > 0 && min[0] < num)
            {
                min.emplace_back(num);
                std::push_heap(min.begin(), min.end(), std::greater<T>());
                num = min[0];
                std::pop_heap(min.begin(), min.end(), std::greater<T>());
                min.pop_back();
            }
            max.emplace_back(num);
            std::push_heap(max.begin(), max.end(), std::less<T>());
        }
    }

    const T get_median() const
    {
        size_t size = min.size() + max.size();
        if (size == 0)
            return -1;
        T median = 0;
        if ((size & 1) == 0)
            median = (min[0] + max[0]) >> 1;
        else
            median = min[0];
        return median;
    }


private:
    vector<T> max;  // max heap
    vector<T> min;  // min heap
};
