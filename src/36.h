/*
 * @Author: FreedomLy 
 * @Date: 2018-04-28 14:15:14 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-28 14:37:17
 * 题目
 * 在字符串中找出第一个只出现一次的字符，并返回它的位置
 */

// 思路
// 1. 可以采用一个map来存储每个字符出现的次数，然后再遍历字符串
//    是判断其出现的次数
// 2. 将字符串的每个字符存储到vector中，遍历数组，删除当前字符，然后
//    在剩余字符中查找是否还有该字符，如果没有，就表示是第一个只出现
//    一次的字符
#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using std::unordered_map;
using std::vector;
using std::string;
using std::pair;

class Solution36 {
public:
    int first_unique_char(const string& str)
    {
        return first_unique_map(str);
        // return first_unique_vec(str);
    }

private:
    // 采用map
    int first_unique_map(const string& str)
    {
        // 使用pair<int, int>来存储出现的次数以及下标
        // 可以减少第二次遍历的次数
        unordered_map<char, pair<int, int>> m;
        for (size_t i = 0; i < str.size(); ++i)
        {
            m[str[i]].first++;
            m[str[i]].second = i;
        }
        
        int index = str.size(); // 记录只出现一次的字符的下标
        for (auto &p : m)
        {
            if (p.second.first == 1)
                index = std::min(index, p.second.second);
        }
        return index == static_cast<int>(str.size()) ? -1 : index;
    }

    // 采用vector
    int first_unique_vec(const string& str)
    {
        vector<char> vc(str.begin(), str.end());
        for (size_t i = 0; i < vc.size(); ++i)
        {
            char tmp = vc[i];
            vc.erase(vc.begin() + i);
            if (std::find(vc.begin(), vc.end(), tmp) == vc.end())
                return i;
            vc.insert(vc.begin() + i, tmp);
        }
        return -1;
    }

};
