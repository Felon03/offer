/*
 * @Author: FreedomLy 
 * @Date: 2018-04-28 16:32:02 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-28 16:50:59
 * 题目
 * 输入两个链表，找出他们的第一个公共节点
 */

// 思路
// 先得到两个链表的长度，令两个指针分别指向两个链表的头节点
// 让长的链表先走两个链表的长度差步数(abs(l1-l2)) 然后一起
// 前进。第一个所指的值相同的节点就是公共节点
// 还可以吧两恶搞链表接起来，形成两个链表(l1+l2, l2+l1)
// 同时遍历两个链表，就能找到第一个公共节点
#pragma once

#include "ListNode.h"

using list::ListNode;


class Solution38 {
public:
    ListNode* get_intersection_node(ListNode* l1, ListNode* l2)
    {
        ListNode* la = l1, *lb = l2;
        int lenA = get_length(la);
        int lenB = get_length(lb);
        la = l1, lb = l2;

        if (lenA < lenB)
        {
            for (int i = 0; i < lenB - lenA; ++i)
                lb = lb->next;
        }
        else
        {
            for (int i = 0; i < lenA - lenB; ++i)
                la = la->next;
        }

        while (la && lb && la != lb)
        {
            la = la->next;
            lb = lb->next;
        }

        if (!la || !lb)
            return nullptr;
        return la;
    }

    ListNode* intersection(ListNode* l1, ListNode* l2)
    {
        ListNode* a = l1, *b = l2;
        while (a != b)
        {
            a = a ? a->next : l2;
            b = b ? b->next : l1;
        }

        return a;
    }


private:
    int get_length(ListNode* head)
    {
        int len = 0;
        ListNode* p = head;
        while (p)
        {
            p = p->next;
            ++len;
        }
        return len;
    }

};