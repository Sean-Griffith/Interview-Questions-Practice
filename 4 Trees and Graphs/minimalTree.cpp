/*
    Given a sorted (increasing order) array with unique integer 
    elements, write an algorithm to create a binary search tree
    with minimal height.
*/

#include <iostream>
#include "BST.h"
using namespace std;

BST<int> ArrayToBST(const int* arr, int size);

int main(){
    int arr[7] = {-44, 13, 17, 32, 51, 88, 201};
    BST<int> solution = ArrayToBST(arr, 7);
    solution.ShowStructure();
    return 1;
}

BST<int> ArrayToBST(const int* arr, int size){
    BST<int> myTree;
    for(int i = 0; i < size; i++){
        myTree.Insert(arr[i]);
    }
    return myTree;
}