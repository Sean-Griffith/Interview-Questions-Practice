/*
    Write an algorithm to find the "next" node (i.e., in-order successor) 
    of a given node in a binary search tree. You may assume that each node
    has a link to its parent.
*/

#include <iostream>
#include "BST.h"
using namespace std;

int main(){
    BST<int> example1;
    int exampleArr1[7] = {-44, 13, 17, 32, 51, 88, 201};
    example1.ArrayToMinBST(exampleArr1, 7);
    example1.ShowStructure();
    /*
        O(nlogn) time complexity to find the node, O(n) to find the successor
        O(n) time complexity total

        O(nlogn) space complexity to find the node, O(1) to find the successor
        O(nlogn) space complexity total

        Upon finding the queried node, this algorithm checks for a right child.
        If the node has a right child, it traverses to that child and traverses
        to the left child (if any) until a leaf node is found. If the node has no
        right subtree/child, it traverses to the parent node until it approaches
        the parent from the left, at which point it returns the parent node.
    */
    cout << example1.FindSuccessor(-44) << endl;
    return 1;
}