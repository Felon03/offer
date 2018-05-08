/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 10:04:00 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 10:19:27
 * 题目
 * 输入一个链表，输出该链表中倒数第k个节点
 */

#pragma once

#include "ListNode.h"

using list::ListNode;

// 思路
// 可以通过快慢指针的思想来解题
// 设置两个指针，第一个指针先前进k个元素，此时两个指针之间的距离为k
// 然后再让两个指针同时前进，当第一个指针指向尾节点时，第二个指针正
// 好指向第k个节点

class Solution16 {
public:
    ListNode* find_kth_to_tail(ListNode* head, int k)
    {
        if (!head || k == 0)
            return nullptr;
        
        ListNode* p1 = head, *p2 = head;
        
        for (int i = 1; i < k; ++i)
        {
            if (p1->next)
                p1 = p1->next;
            else
                return nullptr;
        }

        while (p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }

    // 求链表的中间节点
    // 定义快慢指针，快指针每次走两步，慢指针每次走一步
    // 当快指针到达尾节点时，慢指针正好指向中间节点
    ListNode* find_mid_node(ListNode* head)
    {
        if (!head)
            return nullptr;

        ListNode* slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // 判断一个单向链表是否是环形链表
    bool has_cycle(ListNode* head)
    {
        if (!head)
            return false;
        
        ListNode* slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};
