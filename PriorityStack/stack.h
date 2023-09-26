#pragma once

#include <stack>
#include <map>

template <typename T>
class PriorityStackClass
{
public:
    void Push(T value, int priority);
    void Push(T value);
    T Pop();
    int Count();
private:
    std::map<int, std::stack<T>> stacks_;
};