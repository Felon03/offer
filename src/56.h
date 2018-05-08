/*
 * @Author: FreedomLy 
 * @Date: 2018-05-07 15:18:58 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-05-07 16:26:18
 * 题目
 * 在一个排序的链表中，如何删除重复的节点(重复节点一个都不保留)
 */

// 思路
// 可以利用双重指针来实现删除重复节点的操作
#pragma once

#include "ListNode.h"

using list::ListNode;

class Solution56 {
public:
    ListNode* remove_duplicates(ListNode* head)
    {
        if (!head || !head->next) return head;

        for (ListNode** p = &head; *p; )
        {
            ListNode* cur = *p;
            if (cur->next && (cur->val == cur->next->val))
            {
                int val = cur->val;
                while (cur && cur->val == val)
                {
                    ListNode* tmp = cur->next;
                    delete cur;
                    cur = nullptr;
                    cur = tmp;
                }
                *p = cur;
            }
            else
                p = &(*p)->next;
        }

        return head;
    }
};


