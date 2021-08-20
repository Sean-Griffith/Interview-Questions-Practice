#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
    Queue<int> example1, example2;
    for(int i = 0; i < 10; i++){
        example1.Enqueue(i);
    }
    example1.ShowStructure();
    
    cout << example1.Dequeue() << endl;
    example1.ShowStructure();

    //example2.ShowStructure();
    //example2.Enqueue(33);
    //example2.ShowStructure();
    //example2.Dequeue();
    //example2.ShowStructure();
    //example2.Dequeue();

    example2 = example1;
    example2.ShowStructure();

    Queue<int> example3(example2);
    example3.ShowStructure();
    
    return 1;
}