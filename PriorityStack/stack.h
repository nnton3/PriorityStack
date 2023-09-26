#pragma once

#include <stack>
#include <map>

template <typename T>
class PriorityStack
{
public:
    void Push(T value, int priority);
    void Push(T value);
    T Pop();
private:
    std::map<int, std::stack<T>> stacks_;
};