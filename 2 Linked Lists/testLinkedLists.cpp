/*
    Driver for testing linked list functionality
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

    List<int> example2(example);
    example2.showStructure();

    List<int> example3 = example2;
    example3.showStructure();

    return 1;
}
