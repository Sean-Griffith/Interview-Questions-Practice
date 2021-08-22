/*
    Imagine a stack of plates. If the stack gets too high, it might
    topple. Therefore, in real life, we would likely start a new stack
    when the previous stack exceeds some threshold. Implement a data 
    structure SetOfStacks that mimics this. SetOfStacks should be 
    composed of several stacks and should create a new stack once
    the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop()
    should behave identically to a single stack (that is, pop() should return
    the same values as it would if there was just a single stack).

    FOLLOW UP

    Implement a function popAt(int index) which performs a pop operation on a 
    specific sub-stack.
*/
#include <iostream>
#include "SetOfStacks.h"
#include <stack>
using namespace std;

int main(){
    /* 
        Pop
        O(1) time complexity
        O(n) space complexity
        Whenver the latest stack is empty, remove it and return to
        the previous stack. Once a stack with an element is found, 
        return the element.

        Push
        O(1) time complexity
        O(1) space complexity
        Whenever the latest stack exceeds the threshold, make a new 
        stack and insert the element there. 

        PopAt
        O(1) time complexity
        O(1) space complexity
        Use an arraylist to hold a set of stacks, remove 
        the element from the index desired (if not empty). Cleanup
        of stacks emptied via this method is done by Pop.
    */
    SetOfStacks<int> example1(2);
    SetOfStacks<int> example2(5);

    example1.ShowStructure();
    example2.ShowStructure();

    for(int i = 0; i < 5; i++){
        example1.Push(i);
    }

    for(int i = 0; i < 17; i++){
        example2.Push(i);
    }

    example1.ShowStructure();
    example2.ShowStructure();

    cout << "Modifying example 1" << endl;
    cout << "Popping: " << example1.Pop() << endl;
    cout << "Popping: " << example1.Pop() << endl;
    cout << "Popping: " << example1.Pop() << endl;
    cout << "Popping: " << example1.Pop() << endl;
    //cout << "Popping:" << example1.Pop() << endl;

    cout << "Modifying example 2" << endl;
    cout << "Popping: " << example2.Pop() << endl;
    cout << "Popping from 1st stack: " << example2.PopAt(1) << endl;

    example1.ShowStructure();
    example2.ShowStructure();

    SetOfStacks<int> example3(3);
    for(int i = 0; i < 7; i++){
        example3.Push(i);
    }
    example3.ShowStructure();

    cout << "Modifying example 2" << endl;
    cout << "Popping from 1st stack: " << example3.PopAt(1) << endl;
    cout << "Popping from 1st stack: " << example3.PopAt(1) << endl;
    cout << "Popping from 1st stack: " << example3.PopAt(1) << endl;
    cout << "Popping: " << example3.Pop() << endl;
    cout << "Popping: " << example3.Pop() << endl;

    example3.ShowStructure();

    return 1;
}