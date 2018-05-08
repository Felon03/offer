/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 19:14:15 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 20:03:57
 * 题目
 * 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s
 * 输入n，打印s的所有可能的值出现的概率
 */

// 思路
// 本题可以采用递归的方式求解，但是递归实现中很多计算都是重复的
// 因此当n较大时，程序指向速度会比较慢，因此可以采用基于循环解
// 的方式。考虑采用两个数组来存储骰子的点数的每一个总数出现的次
// 数。在一次循环重，第一个数组中的第 n 个数字表示骰子和为 n 出
// 现的次数。在下一个循环中，我们加上一个新的骰子，此时和为n的骰
// 子出现的次数应该是上一次循环中点数和为n-1, n-2, n-3, n-4, n-5
// 与n-6的次数的总和，所以我们把另一个数组的第n个数字设为前一个
// 数字对于第n-1, n-2, n-3, n-4, n-5于n-6之和
#pragma once

#include <vector>
#include <cmath>
#include <utility>

using std::vector;
using std::pair;

class Solution44 {
public:
    Solution44(int val = 6)
        : max_value(val) { }

    vector<pair<int, double>> probability(int num_of_dice)
    {
        if (num_of_dice < 1) return {};

        vector<vector<int>> prob(2, vector<int>(max_value * num_of_dice + 1));

        int flag = 0;
        for (int i = 1; i <= max_value; ++i)
            prob[flag][i] = 1;
        
        for (int k = 2; k <= num_of_dice; ++k)
        {
            for (int i = 0; i < k; ++i)
                prob[1 - flag][i] = 0;
            
            for (int i = k; i <= max_value * k; ++i)
            {
                prob[1 - flag][i] = 0;
                for (int j = 1; j <= i && j <= max_value; ++j)
                    prob[1 - flag][i] += prob[flag][i - j];
            }

            flag = 1 - flag;
        }

        vector<pair<int, double>> ret;
        double total = pow(static_cast<double>(max_value), num_of_dice);
        for (int i = num_of_dice; i <= max_value * num_of_dice; ++i)
        {
            double ratio = static_cast<double>(prob[flag][i]) / total * 100;
            ret.push_back({i, ratio});
        }

        return ret;
    }

private:
    int max_value;  // 骰子的最大点数
};
