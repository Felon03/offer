/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 21:08:14 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-24 21:49:02
 * 题目
 * 给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内
 * 删除该节点
 */

// 思路
// 大致分为三种情况
// 1. 当要删除的节点为链表的中间节点是，可以把后一节点值覆盖当前
// 节点，然后删除后一节点
// 2. 当要删除的节点为链表的尾节点时，我们要保存尾节点的前一节点
// 使其 next 指向 nullptr
// 3. 当链表只有一个节点时，删除该节点后，将链表置为nullptr

#pragma once

#include "ListNode.h"

using list::ListNode;

class Solution14 {
public:
	ListNode* delete_node(ListNode* head, ListNode* del)
	{
		if (!head || !del) return head;

		// 如果删除第一个节点
		if (del->val == head->val)
		{
			ListNode* p = head;
			head = head->next;
			delete p;
			p = nullptr;
            return head;
		}

		ListNode* p = head, *q = head;
		while (p->val != del->val && p->next)
		{
			q = p;
			p = p->next;
		}

		if (p->val == del->val)
		{
			q->next = p->next;
			delete p;
			p = nullptr;
		}

        return head;
	}
};
