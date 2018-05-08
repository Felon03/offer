/*
 * @Author: FreedomLy 
 * @Date: 2018-05-03 19:33:25 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-03 21:06:32
 * 题目
 * 请实现一个函数用来匹配包含'.'和'*'的正则表达式
 * 模式中的字符串'.'表示任意一个字符，而'*'表示它前面的字符可以出现
 * 任意次数(含0次)
 */

// 思路
// 每次从字符串中拿出一个字符串和模式中的字符去匹配
// 如果模式中的字符ch是'.'，那么它可以匹配字符串中任意字符。
// 如果模式中的字符ch不是'.'而且字符串中的字符也是ch，那么
// 它们互相匹配。当字符串中的字符和模式中的字符相匹配时，接
// 着匹配后面的字符。
// 当模式中第二个字符不是'*'时，如果字符串的第一个字符和模式
// 中的第一个字符相匹配，那么在字符串和模式上都想后移动一个
// 字符，然后匹配剩余的字符串和模式。如果字符串的第一个字符
// 和模式中的第一个字符不匹配，则直接返回false
// 当模式中的第二个字符为'*'时，如果模式中的第一个字符和字符
// 串中的第一个字符相匹配时，则将字符串向后移动一个字符，而在
// 模式上有两个选择：我们可以在模式上向后移动两个字符，也可以
// 保持模式不变。
#pragma once
#include <string>

using std::string;

class Solution52 {
public:
    bool match(char* str, char* pattern)
    {
        if (str == nullptr || pattern == nullptr)
            return false;

        return helper(str, pattern);
    }

private:
    bool helper(char* str, char* pattern)
    {
        if (*str == '\0' && *pattern == '\0')
            return true;
        if (*str != '\0' && *pattern == '\0')
            return false;
        if (*(pattern + 1) == '*')
        {
            if (*pattern == *str || (*pattern == '.' && *str != '\0'))
                return helper(str + 1, pattern + 2) ||  // 进入下一个模式，字符串前进
                       helper(str + 1, pattern) ||      // 保持当前模式，字符串前进
                       helper(str, pattern + 2);        // 忽略当前模式
            else
                return helper(str, pattern + 2);
        }
        if (*str == *pattern || (*pattern == '.' && *str != '\0'))
            return helper(str + 1, pattern + 1);
        return false;
    }
};
