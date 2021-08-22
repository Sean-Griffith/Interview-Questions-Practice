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

/* 
    O(n^2) time complexity
    O(n) space complexity

    Pop an element from unsorted stack and store in temporary variable,
    pop elements from sorted stack until a smaller element than the temporary variable
    is found, then push it to that stack. Repeat until unsorted stack is empty.

    Time complexity is n^2 in the case where all elements are sorted high->low, as each
    sort requires the sorted stack to be moved back to the unsorted stack and then
    replaced onto the sorted stack following insertion of the new element.

    E.G.
    U: 5 4 3 2 1 | S:       | T: NULL
    U: 4 3 2 1   | S:       | T: 5
    U: 4 3 2 1   | S: 5     | T: NULL
    U: 3 2 1     | S: 5     | T: 4
    U: 5 3 2 1   | S: 4     | T: NULL
    U: 3 2 1     | S: 4     | T: 5
    U: 3 2 1     | S: 5 4   | T: NULL
    U: 2 1       | S: 5 4   | T: 3
    U: 5 2 1     | S: 4     | T: 3
    U: 4 5 2 1   | S: 3     | T: NULL
    U: 5 2 1     | S: 3     | T: 4
    U: 5 2 1     | S: 4 3   | T: NULL
    U: 2 1       | S: 4 3   | T: 5
    U: 2 1       | S: 5 4 3 | T: NULL
    ... etc
*/
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
