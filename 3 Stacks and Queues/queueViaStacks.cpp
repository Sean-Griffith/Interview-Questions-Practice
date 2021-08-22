/*
    Implement a MyQueue class which implements a queue using two stacks.
*/
#include <iostream>
#include "StackQueue.h"
using namespace std;

int main(){

    /* 
        Add
        O(n) time complexity
        O(1) space complexity
        If the last operation was Remove(), the output stack must 
        be moved to the input stack (O(n)). Otherwise O(1).

        Remove
        O(n) time complexity
        O(1) space complexity
        If the last operation was Add(), the input stack must 
        be moved to the output stack (O(n)). Otherwise O(1).

        Peek
        O(n) time complexity
        O(1) space complexity
        If the last operation was Add(), the input stack must 
        be moved to the output stack (O(n)). Otherwise O(1).
        
    */

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