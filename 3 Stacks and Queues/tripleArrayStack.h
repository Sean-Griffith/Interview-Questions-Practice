#ifndef TRIPLEARRAYSTACK_H
#define TRIPLEARRAYSTACK_H

#include <stdexcept>
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

template <typename DataType>
class TripleArrayStack {
    public:
        TripleArrayStack();
        TripleArrayStack(const TripleArrayStack& other);
        TripleArrayStack& operator=(const TripleArrayStack& other);
        ~TripleArrayStack();

    private:
        int m_size1, m_size2, m_size3;
        int* m_array;
};

template <typename DataType>
TripleArrayStack<DataType>::TripleArrayStack(){
    
}

#endif