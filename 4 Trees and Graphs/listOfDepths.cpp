/*
    Given a binary tree, design an algorithm which creates a linked
    list of all the nodes at each depth (e.g., if you have a tree with
    depth D, you'll have D linked lists).
*/

#include <iostream>
#include "BST.h"
using namespace std;

BST<int> ArrayToBST(const int* arr, int size);

int main(){
    int example[15] = {0, 11, 8, -4, 1, 22, 47, 9, -41, 201, -18, -33, 1, 66, -18};
    BST<int> solution = ArrayToBST(example, 15);
    solution.ShowStructure();
    cout << "Tree has a depth of: " << solution.GetDepth() << endl;
    return 1;
}

BST<int> ArrayToBST(const int* arr, int size){
    BST<int> myTree;
    for(int i = 0; i < size; i++){
        myTree.Insert(arr[i]);
    }
    return myTree;
}