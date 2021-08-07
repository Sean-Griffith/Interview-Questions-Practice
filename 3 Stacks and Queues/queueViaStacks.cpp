/*
    Implement a MyQueue class which implements a queue using two stacks.
*/
#include <iostream>
#include "StackQueue.h"
using namespace std;

int main(){
    StackQueue<int> example1;
    //example1.Remove();
    example1.Add(1);
    example1.Add(2);
    example1.Add(3);
    example1.Add(4);
    cout << example1.Remove() << endl;
    example1.Add(5);
    cout << example1.Remove() << endl;
    return 1;
}