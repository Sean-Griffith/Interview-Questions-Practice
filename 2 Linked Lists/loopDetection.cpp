/*
    Given a linked list which might contain a loop, implement an
    algorithm that returns the node at the beginning of the loop
    (if one exists).
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

void checkLoop(List<int>& myList);

int main(){

    List<int> example1;
    List<int> example2;

    for(int i = 0; i < 10; i++){
        example1.insert(i);
        example2.insert(i);
    }

    checkLoop(example1);

    example2.loopList(7);
    checkLoop(example2);

    return 1;
}

/* 
    O(n) time complexity
    O(1) space complexity

    Uses two temporary pointers, one that moves
    slowly - one node at a time, and another tha moves
    quickly - two nodes at a time. If the list has a loop, 
    the address of the current node for each pointer will be the same
    before the end of the list is reached.
*/
void checkLoop(List<int>& myList){
    if(myList.isLooped()){
        cout << "List is looped!" << endl;
    } else {
        myList.showStructure();
        cout << "List has no loop." << endl;
    }
}
