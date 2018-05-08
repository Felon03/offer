/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 20:25:58 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 20:37:40
 * 题目
 * 输入一个正整数数组，把数组里所有的数字凭借起来排成一个数
 * 打印能拼接出的所有数字中最小的一个
 */

// 思路
// 把整数转换为字符串，然后对字符串按照由小到大排序即可
// 排序的规则为比较两个字符串合并后的大小
#pragma once

#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;


class Solution34 {
public:
    const string min_number(const vector<int>& nums)
    {
        vector<string> s_nums(nums.size());
        for (size_t i = 0; i < nums.size(); ++i)
            s_nums[i] = std::to_string(nums[i]);

        std::sort(s_nums.begin(), s_nums.end(),
                  [](string s1, string s2) { return (s1 + s2) < (s2 + s1); });

        string ret;
        for (const auto &e : s_nums)
            ret.append(e);

        return ret;
    }
};
