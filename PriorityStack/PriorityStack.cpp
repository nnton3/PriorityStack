// PriorityStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stack.h"

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::stack;

//namespace using std;

template <typename T>
class PriorityStackClass
{
public:
    void Push(T value, int priority)
    {
        if (stacks_.find(priority) != stacks_.end())
        {
            stack<T> *targetStack = &stacks_[priority];
            (*targetStack).push(value);
        }
        else
        {
            stack<T> stack;
            stack.push(value);
            stacks_[priority] = stack;
        }
    }
    //void Push(T value);
    T Pop()
    {
        if (stacks_.empty()) return NULL;
        stack<T> stack = stacks_.begin()->second;
        if (stack.empty()) return NULL;
        return stack.top();
    }
    int Count()
    {
        int count = 0;
        for (auto it = stacks_.begin(); it != stacks_.end(); ++it)
            count++;
        return count;
    }
private:
    map<int, stack<T>> stacks_;
};

int main()
{
    cout << "Hello World!\n";
    PriorityStackClass<string> stack;
    string tom = "Tom";
    string steve = "Steve";
    string ana = "Ana";
    string alex = "Alex";
    stack.Push(tom, 1);
    stack.Push(steve, 5);
    stack.Push(ana, 1);
    stack.Push(alex, 5);
    cout << stack.Pop() << endl;
    stack.Count();
    /*auto count = stack.Count();
    for (size_t i = 0; i < count; i++)
    {
        std::cout << stack.Pop() << "\n";
    }*/
}
