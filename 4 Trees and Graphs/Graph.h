#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Queue.h"
using namespace std;

#define UNVISITED 0
#define VISITED -1
#define BUILT 1

template <typename DataType>
struct Node {
    DataType m_data;
    int m_id = -1;
    // States: 0 = unvisited, -1 = touched, 1 = visited
    int state = 0;
};

struct Edge {
    int start;
    int weight;
    int end;
};

template <typename DataType>
class Graph {
    public:
        Graph();
        Graph(const Graph& other);
        Graph<DataType>& operator=(const Graph& other);

        void InsertNode(Node<DataType>& newNode);
        void InsertEdge(Edge newEdge);

        bool isPath(int node1, int node2);
        void visitNode(Node<DataType> myNode);

        void NodeDetails(int nodeId) const;
        void ListEdges() const;

        vector<DataType> OrderDependencies();
    private:
        bool OrderDependenciesHelper(Node<DataType>& currNode, vector<DataType>& order);
        vector<vector<Edge>> m_adjacencyList;
        vector<Node<DataType>> m_nodeList;
};

template <typename DataType>
Graph<DataType>::Graph(){
    
}

template <typename DataType>
Graph<DataType>::Graph(const Graph& other){
    // Copy over edges
    for(int i = 0; i < other.m_adjacencyList.size(); i++){
        m_adjacencyList.push_back(other.m_adjacencyList[i]);
    }
    // Copy over nodes
    for(int i = 0; i < other.m_nodeList.size(); i++){
        m_nodeList.push_back(other.m_nodeList[i]);
    }
}

template <typename DataType>
Graph<DataType>& Graph<DataType>::operator=(const Graph& other){
    if(&other == this){
        return *this;
    }
    m_adjacencyList.clear();
    // Copy over edges
    for(int i = 0; i < other.m_adjacencyList.size(); i++){
        m_adjacencyList.push_back(other.m_adjacencyList[i]);
    }
    // Copy over nodes
    for(int i = 0; i < other.m_nodeList.size(); i++){
        m_nodeList.push_back(other.m_nodeList[i]);
    }
    return *this;
}

template <typename DataType>
void Graph<DataType>::InsertNode(Node<DataType>& newNode){
    // Set node id to latest node
    newNode.m_id = m_adjacencyList.size();
    // Add edge list for new node to adjacency list
    vector<Edge> edgeList;
    m_adjacencyList.push_back(edgeList);
    // Add node to node list
    m_nodeList.push_back(newNode);
}

template <typename DataType>
void Graph<DataType>::InsertEdge(Edge newEdge){
    if(newEdge.start >= m_adjacencyList.size() || newEdge.start < 0 ||
       newEdge.end >= m_adjacencyList.size() || newEdge.end < 0){
        throw logic_error("Cannot insert edge when either the start or end nodes do not exist.");
    }
    // Directional Graph (one-way edges)
    m_adjacencyList[newEdge.start].push_back(newEdge);
}


template <typename DataType>
void Graph<DataType>::NodeDetails(int nodeId) const {
    if(nodeId < 0 || nodeId >= m_adjacencyList.size()){
        throw logic_error("Cannot print details of nonexistant node.");
    }
    for(int i = 0; i < m_adjacencyList[nodeId].size(); i++){
        cout << m_adjacencyList[nodeId][i].start << "[s] -- " << 
        m_adjacencyList[nodeId][i].weight << "[w] --> " << 
        m_adjacencyList[nodeId][i].end << "[e]" << endl;
    }
}

template <typename DataType>
void Graph<DataType>::ListEdges() const {
    for(int i = 0; i < m_adjacencyList.size(); i++){
        NodeDetails(i);
    }
}

template <typename DataType>
bool Graph<DataType>::isPath(int node1, int node2){
    if(node1 >= m_adjacencyList.size() || node1 < 0 ||
       node2 >= m_adjacencyList.size() || node2 < 0){
        return false;
    }
    // Check if a path exists between node1 and node2
    Queue<Node<DataType>> queueBFS;

    // Mark starting node, add to queue
    m_nodeList[node1].visited = true;
    queueBFS.Enqueue(m_nodeList[node1]);

    while(!queueBFS.isEmpty()){
        // Visit current node, add edge nodes to queue if not visited
        Node<DataType> currNode = queueBFS.Dequeue();
        visitNode(currNode);
        if(currNode.m_id == node2){
            return true;
        }
        
        for(int i = 0; i < m_adjacencyList[currNode.m_id].size(); i++){
            int neighborId = m_adjacencyList[currNode.m_id][i].end;
            Node<DataType> neighborNode = m_nodeList[neighborId];
            if(!neighborNode.visited){
                cout << "Queued: Node" << neighborId << endl;
                queueBFS.Enqueue(neighborNode);
                m_nodeList[neighborNode.m_id].visited = true;
            }
        }
    }
    return false;
}

template <typename DataType>
void Graph<DataType>::visitNode(Node<DataType> myNode){
    cout << "Visited: Node " << myNode.m_data << endl;
}

template <typename DataType>
vector<DataType> Graph<DataType>::OrderDependencies(){
    // Assumes the start of an edge is dependent on the end of the edge
    // For each node, first check that the node was not already visited, 
    // then do a DFS until a node with no unvisited children
    vector<DataType> orderedDependencies;
    while(orderedDependencies.size() < m_nodeList.size()){
        for(int i = 0; i < m_nodeList.size(); i++){
            if(!OrderDependenciesHelper(m_nodeList[i], orderedDependencies)){
                throw runtime_error("Cycle detected, cannot build project.");
            }
        }
    }
    return orderedDependencies;
}

template <typename DataType>
bool Graph<DataType>::OrderDependenciesHelper(Node<DataType>& currNode, vector<DataType>& order){
    // If node is built or was touched, return false
    if(currNode.state == VISITED){
        return false;
    }
    cout << "Ordering " << currNode.m_data << endl;
    // Go to each dependency and build before this node (DFS)
    if(currNode.state == UNVISITED){
        visitNode(currNode);
        currNode.state = VISITED;
        // Check all dependencies first
        for(int i = 0; i < m_adjacencyList[currNode.m_id].size(); i++){
            int dependentID = m_adjacencyList[currNode.m_id][i].end;
            if(!OrderDependenciesHelper(m_nodeList[dependentID], order)){
                return false;
            }
        }
        cout << "Built " << currNode.m_data << endl;
        currNode.state = BUILT;
        order.push_back(currNode.m_data);
    }
    return true;
}

#endif