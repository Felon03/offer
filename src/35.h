/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 20:54:02 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 21:11:52
 * 题目
 * 我们把只包含因子2、3和5的数称作丑数(Ugly Number)
 * 求按从小到大顺序的第n个丑数
 */

// 思路
// 可以循环遍历每个数，判断其是否为丑数，如果是，则计数器加1
// 直到计数器等于n时，返回该丑数
// 上述方法运行速度较慢，我们可以根据丑数的特点，生成一个只包含
// 丑数的列表。列表中的丑数分别乘以2、3、5，找到大于当前最后一个
// 丑数的第一个丑数存到数组里，如此循环
#pragma once

#include <vector>
#include <algorithm>

using std::vector;

class Solution35 {
public:
    int get_ugly_number(int n)
    {
        if (n <= 0) return 0;

        vector<int> ugly_nums(n);
        ugly_nums[0] = 1;
        int next_index = 1;

        auto it2 = ugly_nums.begin();
        auto it3 = ugly_nums.begin();
        auto it5 = ugly_nums.begin();

        while (next_index < n)
        {
            int min_num = minmum(*it2 * 2, *it3 * 3, *it5 * 5);
            ugly_nums[next_index] = min_num;
            while (*it2 * 2 <= ugly_nums[next_index])
                ++it2;
            while (*it3 * 3 <= ugly_nums[next_index])
                ++it3;
            while (*it5 * 5 <= ugly_nums[next_index])
                ++it5;
            ++next_index;
        }
        
        return ugly_nums.back();
    }

private:
    int minmum(int n1, int n2, int n3)
    {
        return std::min(std::min(n1, n2), n3);
    }
};