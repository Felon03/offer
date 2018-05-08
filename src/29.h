/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 15:15:56 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 15:35:13
 * 题目
 * 输入一个字符串，打印出该字符串中字符的所有排列
 */

// 思路
// 求整个字符串的排列，可以看作两步：
// 1. 求所有可能出现在第一个位置的字符，即把第一个字符和后面所有
//    的字符交换
// 2. 固定第一个字符，求后面所有字符的排列。
// 如此往复，递归操作

#pragma once

#include <string>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;

class Solution29 {
public:
    vector<string> permutation(string& str)
    {
        if (str.empty()) return {};

        sort(str.begin(), str.end());
        vector<string> ret;
        permute(str, ret, 0);
        return ret;
    }

private:
    void permute(string str, vector<string>& res, size_t begin)
    {
        if (begin == str.size() - 1)
        {
            res.emplace_back(str);
            return;
        }
        for (size_t i = begin; i < str.size(); ++i)
        {
            // 如果字符相同，则不交换
            if (i != begin && str[i] == str[begin])
                continue;
            // 否则就交换字符
            std::swap(str[i], str[begin]);
            // 递归调用，前begin+1不变，后面的字符全排列
            permute(str, res, begin + 1);
        }
    }
};
