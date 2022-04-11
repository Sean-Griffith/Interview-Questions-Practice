/*
    You are given a binary tree in which each node contains an integer value
    (which might be positive or negative). Design an algorithm to count
    the number of paths that sum to a given value. The path does not need to start
    or end at the root of a leaf, but it must go downwards. (traveling only from
    parent nodes to child nodes).
*/

#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main(){
    BinaryTree<int> example;
    int values[9] = {10, 5, -3, 3, 2, 11, 3, -2, 1};
    example.ArrayToBT(values, 9);
    example.ShowStructure();
    cout << example.PathsWithSum(8) << endl;
    return 1;
}