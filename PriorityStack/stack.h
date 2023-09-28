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
        {
            stack<T>* targetStack = &stacks_[priority];
            (*targetStack).push(value);
        }
        else
        {
            stack<T> stack;             //записываю копию или тот который сдесь создал?
            stack.push(value);
            stacks_[priority] = stack;
        }
    }

    void Push(T value)
    {
        Push(value, 0);
    }

    T Pop()
    {
        if (stacks_.empty()) return NULL;
        for (auto it = stacks_.begin(); it != stacks_.end(); ++it)
        {
            stack<T>& stack = it->second;
            if (stack.empty())
                continue;
            T res = stack.top();    //Если брать по ссылке, то после pop данные удаляются из памяти?!
            stack.pop();
            return res;
        }
        return NULL;                //TODO: drop ex
    }

    int Count()
    {
        int count = 0;
        for (auto it = stacks_.begin(); it != stacks_.end(); ++it)
        {
            count += (it->second).size();
        }

        return count;
    }

private:
    map<int, stack<T>> stacks_;
};