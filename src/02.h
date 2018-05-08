/*
 * @Author: FreedomLy 
 * @Date: 2018-04-23 20:29:13 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-23 20:42:28
 * 题目
 * 请实现一个函数，把字符串中的每个空格替换成 "%20"
 * 例如输入 "We are happy." 则输出 "We%20are%20happy."
 */

// 思路
// 我们可以先遍历一遍字符串，这样就能统计出字符串中空格的总数，
// 并可以由此计算出替换之后字符串的总长度
// 每替换一个空格，长度增加2，因此替换以后的字符串长度为原来
// 字符串的长度加上2倍的空格数
// 可以采用从后往前替换的方式，避免反复移动数组元素

#pragma once

class Solution02 {
public:
    void replace_ws(char* str, int length)
    {
        if (str == nullptr || length < 0)
            return;
        
        int origin_length = 0, num_of_ws = 0;
        int i = 0;

        while (str[i] != '\0')
        {
            if (str[i] == 0x20) // 0x20 == ' '
                ++num_of_ws;
            ++origin_length, ++i;
        }

        // new_length 为把空格替换为 '%20' 后的长度
        int new_length = origin_length + num_of_ws * 2;
        int p1 = origin_length, p2 = new_length;

        while (p1 >= 0 && p2 > p1)
        {
            if (str[p1] == 0x20)
            {
                str[p2--] = '0';
                str[p2--] = '2';
                str[p2--] = '%';
            }
            else
                str[p2--] = str[p1];
            --p1;
        }
    }
    
};
