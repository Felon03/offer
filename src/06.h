/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 10:16:46 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 10:28:08
 * 题目
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转
 * 输入一个地址排序的数组旋转，输出旋转数组的最小元素
 */

// 思路
// 可以采用二分查找来减少查找次数
// 当二分查找的 start 和 end 所指的元素大小相同时，则采用遍历的方式查找

#pragma once

#include <vector>

using std::vector;

class Solution06 {
public:
    int min_number_in_rotate_array(const vector<int>& array)
    {
        if (array.empty())
            return -1;

        int start = *(array.begin());
        int end = *(array.rbegin());
        int ret = -1;
        if (start == end)
            ret = order_search(array);
        else
            ret = binary_search(array);

        return ret;
    }

private:
    int binary_search(const vector<int>& arr)
    {
        int start = 0, end = arr.size() - 1;
        int mid = start;
        
        while (arr[start] >= arr[end])
        {
            if (end - start == 1)
            {
                mid = end;
                break;
            }
            
            mid = start + (end - start) / 2;
            if (arr[mid] >= arr[start])
                start = mid;
            else if (arr[mid] <= arr[end])
                end = mid;
        }
        return arr[mid];
    }

    int order_search(const vector<int>& arr)
    {
        int min_val = INT_MAX;
        for (const int &e : arr)
            min_val = std::min(min_val, e);

        return min_val;
    }
};
