/*
    Describe how you could use a single array to implement three stacks.
*/
#include <iostream>
#include "TripleArrayStack.h"
using namespace std;

int main(){
    /*
        A single array could be used to implement three stacks by splitting 
        the array's elements into three portions. Each portion would have its
        start index, # of filled elements, and # of available slots tracked.
        Upon filling up a stack, the number of available slots tracked for that
        stack could be expanded and any stack(s) following that stack in the array
        would have their elements shifted over the number of slots added.
    */
    TripleArrayStack<int> tripleStack1;
    TripleArrayStack<int> tripleStack2(tripleStack1);
    tripleStack1 = tripleStack1;

    return 1;
}