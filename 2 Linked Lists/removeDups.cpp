/*
    Write code to remove duplicates from an unsorted linked list.

    FOLLOW UP

    How would you solve this problem if a temporary buffer is not allowed?
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

int main(){
    cout << "Testing linked lists" << endl;
    List<int> example;
    for(int i = 0; i < 7; i++){
        example.insert(i);
    }
    example.showStructure();
    return 1;
}

/*
    
*/
