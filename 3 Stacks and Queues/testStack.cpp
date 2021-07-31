#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack<int> example1, example2;
    for(int i = 0; i < 10; i++){
        example1.Push(i);
    }
    example1.ShowStructure();
    
    cout << example1.Pop() << endl;
    example1.ShowStructure();

    example2 = example1;
    example2.ShowStructure();

    Stack<int> example3(example2);
    example3.ShowStructure();
    
    return 1;
}