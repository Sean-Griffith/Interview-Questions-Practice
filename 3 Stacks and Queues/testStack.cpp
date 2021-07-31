#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack<int> example;
    for(int i = 0; i < 10; i++){
        example.Push(i);
    }
    example.ShowStructure();
    cout << example.Pop() << endl;
    example.ShowStructure();
    return 1;
}