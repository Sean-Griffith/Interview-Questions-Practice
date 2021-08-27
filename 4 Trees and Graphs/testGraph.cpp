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

    return 1;
}