/*
 * @Author: FreedomLy 
 * @Date: 2018-05-03 20:46:05 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-03 21:06:49
 * 题目
 * 实现一个函数，用来找出字符流中第一个只出现一次的字符
 */

// 思路
// 可以用一个数组来表示哈希表，用字符的ASCII码作为哈希表的键值，
// 而把字符对于的位置作为哈希表的值
#pragma once
#include <vector>

using std::vector;

class Solution54 {
public:
    Solution54()
        : occurrence(vector<int>(256, -1)), index(0) { }

    void insert(char ch)
    {
        if (occurrence[ch] == -1)
            occurrence[ch] = index;
        else if (occurrence[ch] >= 0)
            occurrence[ch] = -2;
        ++index;
    }

    char first_appearing_once()
    {
        char ch = '\0';
        int min_index = INT_MAX;
        for (size_t i = 0; i < 256; ++i)
        {
            if (occurrence[i] >= 0 && occurrence[i] < min_index)
            {
                ch = static_cast<char>(i);
                min_index = occurrence[i];
            }
        }
        return ch == '\0' ? '#' : ch;
    }


private:
    vector<int> occurrence;
    int index;

};
