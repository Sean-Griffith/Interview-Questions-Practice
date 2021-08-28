/*
    Given a directed graph and two nodes (S and E), design 
    an algorithm to find out whether there is a route 
    from S to E
*/

#include <iostream>
#include "Graph.h"
using namespace std;

int main(){
    Graph<int> example;
    Node<int> n1,n2,n3,n4,n5;

    n1.m_data = 11;
    n2.m_data = 22;
    n3.m_data = 33;
    n4.m_data = 44;
    n5.m_data = 55;
    example.InsertNode(n1);
    example.InsertNode(n2);
    example.InsertNode(n3);
    example.InsertNode(n4);
    example.InsertNode(n5);

    Edge e1,e2,e3,e4,e5,e6,e7;

    e1 = {0,0,1};
    e2 = {0,0,4};
    e3 = {1,0,4};
    e4 = {1,0,3};
    e5 = {2,0,1};
    e6 = {3,0,2};
    e7 = {3,0,4};
    example.InsertEdge(e1);
    example.InsertEdge(e2);
    example.InsertEdge(e3);
    example.InsertEdge(e4);
    example.InsertEdge(e5);
    example.InsertEdge(e6);
    example.InsertEdge(e7);
    
    example.ListEdges();

    /* 
        O(n) time complexity
        O(n) space complexity

        A route between two nodes can be found by performing BFS or DFS node traversal. 
        For this solution, I utilized BFS traversal to avoid going down one branch in depth
        before moving onto other neighboring nodes.
    */
    if(example.isPath(0, 1)){
        cout << "Found a path between the nodes!" << endl;
    } else {
        cout << "Couldn't find a path between the nodes!" << endl;
    }

    return 1;
}