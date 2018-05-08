/*
 * @Author: FreedomLy 
 * @Date: 2018-05-02 20:05:22 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-02 20:22:28
 * 题目
 * 从扑克牌中随机抽取5张牌，判断是不是一个顺子，即这5张牌是不是连续
 * 的
 * 2-10为数字本身，A为1，J为11，Q为12，K为13，而大小王可以看作任意
 * 数字
 */

// 思路
// 可以把五张牌看成由5个数字组成的数组。大小王是特殊数字。
// 我们可以先把它们都定义为0，然后可以将5个数字进行排序
// 由于大小王可以为任意数字，因此0可以用来补充不连续的部分
// 如果0的个数和排序后空缺的数字个数相同时，我们认为其为顺子
// 还要注意的问题是：如果出现重复的数字，则不是顺子

#include <vector>
#include <algorithm>

using std::vector;

class Solution45 {
public:
    bool is_continuous(vector<int>& nums)
    {
        if (nums.empty()) return false;

        // 排序
        sort(nums.begin(), nums.end());
        // 组成顺子需要多少数字补充
        int gaps = 0;
        // 排序后数字为0的个数
        int zeros = std::count(nums.begin(), nums.end(), 0);
        int first = zeros;
        int num = first + 1;
        while (num < static_cast<int>(nums.size()))
        {
            // 两个数字相等，表示有对子，不肯能是顺子
            if (nums[first] == nums[num])
                return false;
            
            gaps += nums[num] - nums[first] - 1;
            first = num;
            ++num;
        }
        
        return gaps > zeros ? false : true;
    }
};
