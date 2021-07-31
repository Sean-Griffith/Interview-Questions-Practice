/*
    How would you design a stack which, in addition to push and pop,
    has a function min which returns the minimum element? Push, pop
    and min should all operate in O(1) time.
*/
#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack<int> example;

    /*
        In order to add a min function to return the minimum element 
        in O(1) time, we can add another variable to the StackNode 
        class, "m_minLowerVal" which keeps track of the lowest value
        of that nodes and all preceding stack nodes. This value is 
        calculated when a node is added to the stack. This operates in
        O(1) time despite requiring more space, as only the top node 
        needs to be checked as it records the minimum value of the substack.
    */

    example.Push(5);
    example.ShowStructure();
    cout << "Min Value: " << example.GetMinimum() << endl;

    example.Push(6);
    example.ShowStructure();
    cout << "Min Value: " << example.GetMinimum() << endl;

    example.Push(3);
    example.ShowStructure();
    cout << "Min Value: " << example.GetMinimum() << endl;

    example.Push(7);
    example.ShowStructure();
    cout << "Min Value: " << example.GetMinimum() << endl;

    example.Pop();
    example.ShowStructure();
    cout << "Min Value: " << example.GetMinimum() << endl;

    example.Pop();
    example.ShowStructure();
    cout << "Min Value: " << example.GetMinimum() << endl;

    example.Clear();
    example.ShowStructure();
    cout << "Min Value: " << example.GetMinimum() << endl;

    example.ShowStructure();
    return 1;
}