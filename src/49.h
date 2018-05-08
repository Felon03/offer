/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 21:44:02 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-03 19:21:37
 * 题目
 * 编写一个函数，实现把字符串转换成整数
 */

// 思路
// 字符串转数字，需要考虑以下几个问题
// 1. 字符串前面可能有空字符，应该跳过这些字符
// 2. 考虑有+、-符号的情况，以及字符串中出现非数字字符
// 3. 数字大小越界
#pragma once
#include <cctype>
#include <string>

class Solution49 {
public:
    int str_to_int(const string& str)
    {
        size_t i = str.find_first_not_of(' ');
        int mult = 1;
        long ret = 0;
        if (str[i] == '+' || str[i] == '-')
            mult = str[i++] == '-' ? -1 : 1;

        while (i < str.size())
        {
            if (std::isdigit(str[i]))
            {
                ret = ret * 10 + (str[i++] - '0');
                if (ret > INT_MAX)
                    return mult == 1 ? INT_MAX : INT_MIN;
            }
            else
                return 0;
        }
        return ret * mult;
    }
};
