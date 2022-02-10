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

void testCheckSubtree(BinaryTree<int> T1, BinaryTree<int> T2, string name);

int main(){
    int t1arr[10] = {10,4,11,17,2,55,37,19,5,9};
    int t2arr[4] = {10,1,2,3};
    int t3arr[3] = {17,19,5};
    int t4arr[3] = {11,55,37};
    BinaryTree<int> T1;
    BinaryTree<int> T2;
    BinaryTree<int> T3;
    BinaryTree<int> T4;

    T1.ArrayToBT(t1arr, 10);
    T2.ArrayToBT(t2arr, 4);
    T3.ArrayToBT(t3arr, 3);
    T4.ArrayToBT(t4arr, 3);

    /*
        O(k + jn) time complexity, where k is the number of nodes in the subtree (T2), j is the number of occurences
        of the root of the subtree (T2) within the main tree (T1), and n is the number of nodes in T1.

        This solution converts the query subtree to a string, and then walks through the main binary tree searching for
        occurences of the root node in the query subtree to compare with. If such a node is found, that node and its left
        and right branches are converted to a string for comparison. 
    */
    testCheckSubtree(T1, T2, "T2");
    testCheckSubtree(T1, T3, "T3");
    testCheckSubtree(T1, T4, "T4");

    return 1;
}

void testCheckSubtree(BinaryTree<int> T1, BinaryTree<int> T2, string name){
    if(T1.checkSubtree(T2)){
        cout << name << " is a subtree of T1." << endl;
    } else {
        cout << name << " is NOT a subtree of T1." << endl;
    }
}