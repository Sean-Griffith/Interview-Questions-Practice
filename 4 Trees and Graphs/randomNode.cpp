/*
    You are implementing a binary search tree class from scratch,
    which, in addition to insert, find, delete, has a method
    getRandomNode() which returns a random node from the tree. All 
    nodes should be equally likely to be chosen. Design and implement
    an algorithm for getRandomNode, and explain how you would implement
    the rest of the methods.
*/

#include <iostream>
#include "RandomBST.h"
using namespace std;

int main(){
    RandomBST<int> example;
    int exampleArr[7] = {-44, 13, 17, 32, 51, 88, 201};
    example.ArrayToBT(exampleArr, 7);
    example.ShowStructure();
    /*
        Time complexity: O(logn) where n is the number of nodes in the BST
        
        getRandomNode() was implemented by keeping track of the size of each subtree within the tree, 
        and using that value to traverse left, right, or pick the current node. To complement this solution, 
        it is necessary to add a "size" attribute to the BST node class, which would be updated upon
        the insertion or deletion of a node. The find method would work the same as it does in a usual BST.
    */
    int randomData = example.GetRandomNode();
    cout << "Random value: " << randomData << endl;
    return 1;
}