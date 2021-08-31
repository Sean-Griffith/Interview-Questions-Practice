/*
    Given a sorted (increasing order) array with unique integer 
    elements, write an algorithm to create a binary search tree
    with minimal height.
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
    int example2[1] = {-44};
    BST<int> solution2 = ArrayToMinBST(example2, 1);
    solution2.ShowStructure();
    int example3[8] = {-44, 13, 17, 32, 51, 88, 201, 202};
    BST<int> solution3 = ArrayToMinBST(example3, 8);
    solution3.ShowStructure();
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
    /*
        O(nlogn) time complexity
        O(1) space complexity

        If the array is even, recurse on the 1-nth elements first,
        and then add the smallest element.

        Divide the array into 3 sections, p, t, q, where:
        p = left side of the array, excluding the middle
        t = middle of the array
        q = right side of the array, excluding middle

        Continuously break the array into halves, adding the central
        element to the BST. Because the array is sorted, the middle of each 
        array should be the centermost element, and therefore generate a minimal
        depth BST.

        An alternative approach could be to insert new elements from the current node 
        recursively, such that the "BST.Insert()" function need not be called, saving
        O(logn) time, making the method O(n) instead of O(n*logn)
    */
    

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
