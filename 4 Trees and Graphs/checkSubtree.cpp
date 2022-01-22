/*
    T1 and T2 are two very large binary trees, with T1 much bigger than T2.
    Create an algorithm to determine if T2 is a subtree of T1.

    A tree T2 is a subtree of T1 if there exists a node n in T1 such that
    the subtree of n is identical to T2. That is, if you cut off the tree at 
    node n, the two trees would be identical.
*/

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main(){
    int t1arr[10] = {10,4,11,17,2,55,37,19,5,9};
    int t2arr[4] = {10,1,2,3};
    BinaryTree<int> T1;
    BinaryTree<int> T2;
    T1.ArrayToBT(t1arr, 10);
    T2.ArrayToBT(t2arr, 4);
    T1.ShowStructure();
    T2.ShowStructure();
    return 1;
}