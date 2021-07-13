/*
    Write code to remove duplicates from an unsorted linked list.

    FOLLOW UP

    How would you solve this problem if a temporary buffer is not allowed?
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;


int main(){

    List<int> example;
    for(int i = 0; i < 10; i++){
        example.insert(i);
    }
    example.gotoBeginning();
    for(int i = 0; i < 10; i++){
        example.insert(i);
    }
    example.showStructure();
    /* First solution - removeDups()
        O(n) time complexity
        O(n) space complexity

        Uses a hashtable to count the number of each dataitem present
        as the cursor traverses the linkedlist. If a dataitem at the cursor 
        is already present in the hashtable, the node at the cursor is 
        removed using a pointer to the previous element.
    */
    example.removeDups();
    example.showStructure();


    List<int> example2;
    for(int i = 0; i < 10; i++){
        example2.insert(i);
    }
    example2.gotoBeginning();
    for(int i = 0; i < 10; i++){
        example2.insert(i);
    }
    example2.showStructure();
    /* Second solution - removeDupsNoBuffer()
        O(n^2) time complexity
        O(1) space complexity

        "How would you solve this problem if a temporary buffer is not allowed"

        Uses a scanning pointer in addition to the cursor.
        As the list is traversed, the dataItem at the scanning pointer
        is compared to the dataItem at the cursor, which starts at the
        following element and traverses the list checking for duplicates.
        If a duplicate is found, it is removed from the list.
    */
    example2.removeDupsNoBuffer();
    example2.showStructure();
    
    return 1;
}