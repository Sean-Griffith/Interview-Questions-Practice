#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

template <typename DataType>
class Stack {
    public:
        Stack();
        Stack(const Stack& other);
        Stack& operator=(const Stack& other);
        ~Stack();

    private:
        
};

template <typename DataType>
Stack<DataType>::Stack(){
    
}

#endif