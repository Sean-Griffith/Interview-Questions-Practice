/*
    Implement a function to check if a binary tree is balanced.
    For the purposes of this question, a balanced tree is defined
    to be a tree such that the heights of the two subtrees of any
    node never differ by more than one.
*/

#include <iostream>
#include "BST.h"
using namespace std;

BST<int> ArrayToBST(const int* arr, int size);
BST<int> ArrayToMinBST(const int* arr, int size);
void ArrayToMinBSTHelper(const int* p, int size, BST<int>& minTree);

int main(){
    int example1[7] = {-44, 13, 17, 32, 51, 88, 201};
    BST<int> solution1 = ArrayToMinBST(example1, 7);
    solution1.ShowStructure();
    cout << solution1.isBalanced() << endl;
    int example2[1] = {-44};
    BST<int> solution2 = ArrayToMinBST(example2, 1);
    solution2.ShowStructure();
    cout << solution2.isBalanced() << endl;
    int example3[8] = {-44, 13, 17, 32, 51, 88, 201, 202};
    BST<int> solution3 = ArrayToMinBST(example3, 8);
    solution3.ShowStructure();
    cout << solution3.isBalanced() << endl;
    int example4[15] = {0, 11, 8, -4, 1, 22, 47, 9, -41, 201, -18, -33, 1, 66, -18};
    BST<int> solution4 = ArrayToBST(example4, 15);
    solution4.ShowStructure();
    /*
        O(n) time complexity - every node is touched
        O(1) space complexity

        This solution returns the height of each branch from the 
        current node, compares them, and returns the maximum height
        so long as the difference between the branches is less than or
        equal to 1. If there is a larger discrepancy, error code -1 is 
        returned, which propogates to original call and marks the tree
        as unbalanced.
    */
    cout << solution4.isBalanced() << endl;
    return 1;
}

BST<int> ArrayToBST(const int* arr, int size){
    BST<int> myTree;
    for(int i = 0; i < size; i++){
        myTree.Insert(arr[i]);
    }
    return myTree;
}

BST<int> ArrayToMinBST(const int* arr, int size){
    BST<int> myTree;
    ArrayToMinBSTHelper(arr, size, myTree);
    return myTree;
}

void ArrayToMinBSTHelper(const int* p, int size, BST<int>& minTree){
    if(size == 0){
        return;
    }

    if(size%2 == 1){
        int middle = (size+1)/2;

        minTree.Insert(*(p+middle-1));

        const int* q = p + middle;
        ArrayToMinBSTHelper(q, size-middle, minTree);
        ArrayToMinBSTHelper(p, middle-1, minTree);
    } else {
        ArrayToMinBSTHelper(p+1, size-1, minTree);
        minTree.Insert(*p);
    }
    
}