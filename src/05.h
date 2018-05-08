/*
 * @Author: FreedomLy 
 * @Date: 2018-04-24 09:10:43 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 20:51:36
 * 题目
 * 用两个栈实现队列，完成队列的 push 和 pop 操作。
 */

// 思路
// 队列的特点是先进先出(FIFO)，栈的特点是后进先出(LIFO)
// 当我们用两个栈实现队列的时候，可以把一个栈作为入队工具
// 当要出队列是，把入队栈的数据全部压入另一个栈中，这样另
// 一个栈中的元素顺序就和队列元素的出队顺序一样了

#pragma once

#include <iostream>
#include <stack>
#include <queue>

using std::stack;
using std::queue;
using std::cout;

template <typename T>
class Queue {
public:
    Queue() = default;
    ~Queue() { }

    void push(const T& val)
    {
        stack1.push(val);
    }

    T pop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                T data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }

        if (stack2.empty())
        {
            cout << "Empty Queue\n";
            return -1;
        }
        T ret = stack2.top();
        stack2.pop();
        return ret;
    }
    
private:
    stack<T> stack1, stack2;
};


// 两个队列实现栈
template <typename T>
class Stack {
public:
    Stack() = default;
    ~Stack() { }

    void push(const T& val)
    {
        queue1.push(val);
    }

    T pop()
    {
        while (queue1.size() > 1)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        
        T ret = queue1.front();
        queue1.pop();
        std::swap(queue1, queue2);

        return ret;
    }

private:
    queue<T> queue1, queue2;
};