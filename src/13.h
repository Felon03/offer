/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 20:38:00 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 21:04:14
 * 题目
 * 输入数字n，按顺序打印出从1到最大的n位十进制数
 * 不如输入3，则打印出1、2、3一直到最大的3位数999
 */

// 思路
// 注意n过大导致直接使用整型(int)或者长整形(long long)会溢出的情况
// 改用字符串处理

#pragma once

#include <string>

using std::string;
using std::cout;

class Solution13 {
public:
    void print_1_to_max_of_n_digits(int n)
    {
        if (n <= 0) return;

        string number(n, '0');

        while (!increment(number))
        {
            print_number(number);
        }
    }

private:
    bool increment(string& number)
    {
        bool is_over_flow = false;
        int n_take_over = 0;
        int length = number.size();

        for (int i = length - 1; i >= 0; --i)
        {
            int sum = number[i] - '0' + n_take_over;
            if (i == length - 1)
                ++sum;

            if (sum >= 10)
            {
                if (i == 0)
                    is_over_flow = true;
                else
                {
                    sum -= 10;
                    n_take_over = 1;
                    number[i] = '0' + sum;
                }
            }
            else
            {
                number[i] = '0' + sum;
                break;
            }
        }

        return is_over_flow;
    }

    void print_number(const string& number)
    {
        cout << stoi(number) << " ";
    }
};