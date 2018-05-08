/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 14:02:10 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 14:23:24
 * 题目
 * 统计一个数字在排序数组中出现的次数
 */

// 思路
// 可以采用二分查找，分别找出第一个数字的位置和最后一个数字的位置
// 复杂度为O(logn)
#pragma once

#include <vector>

using std::vector;

class Solution39 {
public:
    int get_num_of_k(const vector<int>& data, int k)
    {
        if (data.empty()) return 0;
        int number = 0;
        int first = get_first(data, k, 0, data.size() - 1);
        int last = get_last(data, k, 0, data.size() - 1);
        if (first != -1 && last != -1)
            number = last - first + 1;
        return number;
    }

private:
    int get_first(const vector<int>& data, int k, int begin, int end)
    {
        if (begin > end) return -1;
        int mid = begin + (end - begin) / 2;
        int mid_data = data[mid];
        if (mid_data == k)
        {
            if ((mid > 0 && data[mid - 1] != k) || mid == 0)
                return mid;
            else
                end = mid - 1;
        }
        else if (mid_data > k)
            end = mid - 1;
        else
            begin = mid + 1;
        return get_first(data, k, begin, end);
    }

    int get_last(const vector<int>& data, int k, int begin, int end)
    {
        if (begin > end) return -1;

        int mid = begin + (end - begin) / 2;
        int mid_data = data[mid];
        int size = static_cast<int>(data.size());
        
        if (mid_data == k)
        {
            if ((mid < size - 1 && data[mid + 1] != k) || mid == size - 1)
                return mid;
            else
                begin = mid + 1;
        }
        else if (mid_data < k)
            begin = mid + 1;
        else
            end = mid + 1;
        return get_last(data, k, begin, end);
    }
};
