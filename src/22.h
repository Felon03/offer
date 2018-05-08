/*
 * @Author: FreedomLy 
 * @Date: 2018-04-25 20:30:45 
 * @Last Modified by: FreedomLy
 * @Last Modified time: 2018-04-25 20:55:47
 * 题目
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的
 * min函数
 * 在该栈中，调用min, push 及 pop 的时间复杂度都是 O(1)
 */

// 思路
// 要保证调用 min 的时间复杂度是 O(1),我们必须设置一个min_elem栈，
// 每压入一个元素时，就往min_elem栈中压入当前所有元素中的最小元素，
// 每次pop时，也要将 min_elem 栈中的元素 pop出去，保证每个栈顶元素
// 对应的最小元素都是最新的
#pragma once

#include <vector>

using std::vector;

template <typename T>
class Stack22 {
public:
    Stack22() = default;

    void push(const T);
    void pop();
    const T top() const;
    const T min() const;

private:
    vector<T> stack;
    vector<T> min_elem;
};

template <typename T>
void Stack22<T>::push(const T value)
{
    stack.emplace_back(value);
    if (min_elem.empty() || value < min_elem.back())
        min_elem.emplace_back(value);
    else
        min_elem.emplace_back(min_elem.back());
}

template <typename T>
void Stack22<T>::pop()
{
    if (stack.empty())
        return;
    stack.pop_back();
    min_elem.pop_back();
}

template <typename T>
const T Stack22<T>::top() const
{
    if (stack.empty())
        return -1;
    return stack.back();
}

template <typename T>
const T Stack22<T>::min() const
{
    if (min_elem.empty())
        return -1;
    return min_elem.back();
}
