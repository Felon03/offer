/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 10:54:17 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 10:58:59
 * 题目
 * 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的
 * 头节点
 */

#pragma once

#include "ListNode.h"

class Solution17 {
public:
    // 循环的方式
    ListNode* reverse_list(ListNode* head)
    {
        ListNode* pre = nullptr;

        while (head)
        {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    // 递归的方式
    ListNode* reverse_list_recursive(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        
        ListNode* node = reverse_list_recursive(head->next);
        // 令当前节点的下一个节点指向它的当前节点，完成反转
        head->next->next = head;
        head->next = nullptr;
        
        return node;
    }
};
