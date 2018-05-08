/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 13:30:16 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 13:51:02
 * 题目
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是
 * 按照递增排序的
 */

#pragma once

#include "ListNode.h"

class Solution18 {
public:
    // 遍历的方法
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = nullptr;

        if (l1->val < l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        
        ListNode* p = head;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1)
            p->next = l1;
        else
            p->next = l2;
        
        return head;
    }

    // 递归
    ListNode* merge_recursive(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* head = nullptr;
        if (l1->val < l2->val)
        {
            head = l1;
            head->next = merge_recursive(l1->next, l2);
        }
        else
        {
            head = l2;
            head->next = merge_recursive(l1, l2->next);
        }
        
        return head;
    }
};
