// PriorityStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "stack.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
    PriorityStackClass<string> stack;
    
    string tom = "Tom";
    string steve = "Steve";
    string ana = "Ana";
    string alex = "Alex";
    
    stack.Push(tom, 1);
    stack.Push(steve, 5);
    stack.Push(ana, 1);
    stack.Push(alex, 5);

    int count = stack.Count();
    for (int i = 0; i < count; i++)
    {
        cout << stack.Pop() << endl;
    }
}
