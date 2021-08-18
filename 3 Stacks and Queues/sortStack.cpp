/*
    Write a program to sort a stack such that the smallest items are
    on the top. You can use an additional temporary stack, but you
    may not copy the elements into any other data structure (such as an array).
    The stack supports the following operations: push, pop, peek, and isEmpty.
*/
#include <iostream>
#include "Stack.h"
using namespace std;

Stack<int> sortStack(Stack<int>& unsorted);

int main(){
    Stack<int> example;
    example.Push(3);
    example.Push(8);
    example.Push(13);
    example.Push(4);
    example.Push(1);
    example.Push(0);
    sortStack(example).ShowStructure();
    return 1;
}

Stack<int> sortStack(Stack<int>& unsorted){

    if(unsorted.isEmpty()){
        return unsorted;
    }
    
    Stack<int> sorted;
    int temp = unsorted.Pop();

    while(!unsorted.isEmpty()){
        if(sorted.isEmpty()){
            sorted.Push(temp);
            temp = unsorted.Pop();
        } else {
            if(sorted.Peek() > temp){
                // Pop the element and move to unsorted stack
                unsorted.Push(sorted.Pop());
            } else {
                sorted.Push(temp);
                temp = unsorted.Pop();
            }
        }
    }
    while(!sorted.isEmpty()){
        unsorted.Push(sorted.Pop());
    }
    return unsorted;
}
