/*
    Implement an algorithm to delete a node in the middle
    (i.e. any node but the first and last node, not necessarily
    the exact middle) of a singly linked list, given only access
    to that node.

    EXAMPLE
    Input: the node c from the linked list a -> b -> c -> d -> e -> f
    Result: nothing is returned, but the new linked list looks like:
    a -> b -> d -> e -> f->
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    cout << "hello" << endl;
    List<char> example;
    example.insert('a');
    example.insert('b');
    example.insert('c');
    example.insert('d');
    example.insert('e');
    example.insert('f');
    example.showStructure();
    /*
        O(1) time complexity
        O(1) space complexity

        Upon accessing the middle node, the next node's data and 
        link can be copied, and then the next node erased.
    */
    example.removeMiddleNode('c');
    example.showStructure();

    return 1;
}