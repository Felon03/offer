/*
 * @Author: FreedomLy 
 * @Date: 2018-05-03 21:12:17 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-03 21:45:53
 * 题目
 * 一个链表中包含环，如何找到环的入口节点
 */

// 思路 Floyd-Cycle-Detection-Algorithm(https://en.wikipedia.org/wiki/Cycle_detection)
// 可以先通过快慢指针找出相同的节点，如果存在，则该节点必为环内节点
// 然后将快节点返回起点节点，并且保持相同的前进速度，当两个指针再次
// 相遇时，该节点就是环的入口

#pragma once

#include "ListNode.h"

using list::ListNode;

class Solution55 {
public:
    ListNode* detect_cycle(ListNode* head)
    {
        if (!head || !head->next)
            return nullptr;
        ListNode* fast = head, *slow = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                fast = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr; // 没有环
    }
};

