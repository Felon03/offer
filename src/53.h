/*
 * @Author: FreedomLy 
 * @Date: 2018-05-03 20:32:04 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-03 20:40:01
 * 题目
 * 请实现一个函数用来判断字符串是否表示数值(包括整数和小数以及
 * 科学计数)
 */

// 思路
// 采用json解析数字的方法
// https://github.com/Felon03/json-tutorial/blob/master/2-Number/leptjson.c
#pragma once

#define ISDIGIT1TO9(ch) ((ch) >= '1' && (ch) <= '9')
#define ISDIGIT(ch) ((ch) >= '0' && (ch) <= '9')

class Solution53 {
public:
    bool is_numeric(char* str)
    {
        if (*str == '+' || *str == '-')
            ++str;
        if (*str == '0')
            ++str;
        else
        {
            if (!ISDIGIT1TO9(*str))
                return false;
            while (ISDIGIT(*str))
                ++str;
        }
        if (*str == '.')
        {
            ++str;
            if (!ISDIGIT(*str))         // 小数点后面必须是数字
                return false;
            while (ISDIGIT(*str))
                ++str;
        }
        if (*str == 'e' || *str == 'E') // 科学计数
        {
            ++str;
            if (*str == '+' || *str == '-')
                ++str;
            if (!ISDIGIT(*str))
                return false;
            while (ISDIGIT(*str))
                ++str;
        }

        return *str == '\0';
    }
};
