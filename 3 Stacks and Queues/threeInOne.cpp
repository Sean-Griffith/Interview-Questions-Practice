/*
    Describe how you could use a single array to implement three stacks.
*/
#include <iostream>
#include "TripleArrayStack.h"
using namespace std;

int main(){
    TripleArrayStack<int> tripleStack1;
    TripleArrayStack<int> tripleStack2(tripleStack1);
    tripleStack1 = tripleStack1;
    return 1;
}