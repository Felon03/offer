/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 15:40:30 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 15:48:10
 * 题目一
 * 输入一个英文句子，反转句子中单词的顺序，但单词内字符的顺序不变
 * 
 * 题目二
 * 字符串的左旋操作是吧字符串前面的若干个字符转移都字符串的尾部
 * 请定义一个函数实现字符串左旋操作的功能
 */

// 思路一
// 先反转整个字符串，然后分别对每个单词再做反转

// 思路二
// 根据要左旋的字符串的个数，将字符串分为两段，先分别反转两段字符串
// 然后整体反转就可以实现左旋
#pragma once

#include <string>
#include <sstream>
#include <algorithm>

using std::string;
using std::stringstream;

class Solution43 {
public:
    string reverse_sentence(string str)
    {
        if (str.empty()) return str;

        str += ' ';
        auto it = str.begin(), start = str.begin();

        while (++it != str.end())
        {
            if (isspace(*it))
            {
                reverse(start, it);
                start = it + 1;
            }
        }
        str = str.substr(0, str.size() - 1);
        std::reverse(str.begin(), str.end());
        return str;
    }

    string left_rotate_str(string str, int n)
    {
        if (str.empty() || n < 1) return str;

        auto it = str.begin() + n, begin = str.begin(), end = str.end();
        std::reverse(begin, it);
        std::reverse(it, end);
        std::reverse(begin, end);
        return str;
    }
};
