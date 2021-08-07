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
    SetOfStacks<int> example1(2);
    SetOfStacks<int> example2(5);

    example1.ShowStructure();
    example2.ShowStructure();

    example1.Push(1);
    example1.Push(2);
    example1.Push(3);
    example1.Push(4);

    example1.ShowStructure();
    example2.ShowStructure();

    cout << "Popping:" << example1.Pop() << endl;
    cout << "Popping:" << example1.Pop() << endl;
    cout << "Popping:" << example1.Pop() << endl;
    cout << "Popping:" << example1.Pop() << endl;
    //cout << "Popping:" << example1.Pop() << endl;

    example1.ShowStructure();
    example2.ShowStructure();

    return 1;
}