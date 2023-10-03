#pragma once

#include <stack>
#include <map>

using std::map;
using std::stack;

template <typename T>
class PriorityStackClass
{
public:
    void Push(T value, int priority)
    {
        if (stacks_.find(priority) != stacks_.end())
            stacks_.at(priority).push(value);
        else
            stacks_[priority].push(value);
    }

    void Push(T value)
    {
        Push(value, 0);
    }

    T Pop()
    {
        if (stacks_.empty()) 
            return nullptr;

        auto priority = stacks_.begin()->first;
        auto stack = &stacks_[priority];
        T res = stack->top();
        stack->pop();
        if (stack->size() == 0) 
            stacks_.erase(priority);
        return res;
    }

    int Count()
    {
        int count = 0;
        for (auto pair: stacks_)
            count += pair.second.size();
        
        return count;
    }

private:
    map<int, stack<T>> stacks_;
};