/*
    Implement an algorithm to find the kth to last element 
    of a singly linked list
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;


int main(){

    List<int> example;
    for(int i = 0; i < 10; i++){
        example.insert(i);
    }
    example.showStructure();
    /* 
        O(n) time complexity
        O(1) space complexity

        Uses two pointers, with one pointer moved 
        k elements forward in the list. Both pointers
        are then moved until the previously moved pointer
        reaches the end. The other pointer will now be pointing
        at the kth to last element.
    */
    cout << example.kthToLast(4) << endl;
    
    return 1;
}