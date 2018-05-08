/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 21:05:22 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 10:30:01
 * 单链表节点定义
 */
#pragma once
#include <iostream>

namespace list {
    
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) { }
};

void destroy_list(ListNode* head)
{
    while (head)
    {
        ListNode *tmp = head->next;

        delete head;
        head = nullptr;

        head = tmp;
    }
}

void print_list(ListNode* head)
{
    if (!head)
        return;
    ListNode *p = head;
    while (p)
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    // delete p;
    // p = nullptr;
}

}

