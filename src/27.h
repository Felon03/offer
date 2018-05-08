/*
 * @Author: FreedomLy 
 * @Date: 2018-04-26 09:32:56 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-26 10:04:10
 * 题目
 * 请实现函数ListNode27* clone(ListNode27* root)，赋值一个复杂链表
 * 在复杂链表中，每个节点除了有一个 next 指向下一个节点外，还有一个
 * sibling 指向链表中的任意节点或者 nullptr
 */

// 思路
// 可以分为三步，实现较小空间复杂度的方法
// 第一步：复制所有的节点，在原节点后面添加新复制的节点
// 第二步：复制每个原节点指向的sibling
// 第三步：拆分原节点和复制的节点

#pragma once

#include <iostream>

// 节点定义
struct ListNode27 {
    int val;
    ListNode27* next;
    ListNode27* sibling;
    ListNode27(int x) : val(x), next(nullptr), sibling(nullptr) { }
};

class Solution27 {
public:
    ListNode27* clone(ListNode27* head)
    {
        if (!head)
            return head;
        copy_node(head);
        copy_sibling(head);
        return split_list(head);
    }

    void print_list(ListNode27 *head)
    {
        if (!head)
            return;
        ListNode27 *p = head;
        while (p)
        {
            std::cout << p->val;
            if (p->sibling)
                std::cout << "(" << p->sibling->val << ")" << " ";
            else
                std::cout << "(null)" << " ";
            p = p->next;
        }
        // delete p;
        // p = nullptr;
    }

    void destroy_list(ListNode27 *head)
    {
        while (head)
        {
            ListNode27 *tmp = head->next;

            delete head;
            head = nullptr;

            head = tmp;
        }
    }

private:
    void copy_node(ListNode27* head)
    {
        if (!head) return;

        ListNode27* p = head;
        while (p)
        {
            ListNode27* copy = new ListNode27(p->val);
            copy->next = p->next;
            p->next = copy;
            p = copy->next;
        }
    }

    void copy_sibling(ListNode27* head)
    {
        if (!head) return;
        ListNode27* p = head;

        while (p)
        {
            ListNode27* copy = p->next;
            if (p->sibling)
                copy->sibling = p->sibling->next;
            p = copy->next;
        }
    }

    ListNode27* split_list(ListNode27* head)
    {
        ListNode27* new_head;
        ListNode27* copy;
        ListNode27* p = head;

        if (p)
        {
            new_head = copy = p->next;
            p->next = copy->next;
            p = p->next;
        }

        while (p)
        {
            copy->next = p->next;
            copy = copy->next;
            p->next = copy->next;
            p = p->next;
        }
        
        return new_head;
    }
};
