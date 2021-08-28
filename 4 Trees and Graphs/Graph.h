#ifndef ANIMALSHELTER_H
#define ANIMALSHELTER_H

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Queue.h"
using namespace std;

template <typename DataType>
struct Node {
    DataType m_data;
    int m_id = -1;
    bool visited = false;
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
    private:
        vector<vector<Edge>> m_adjacencyList;
        vector<Node<DataType>> m_nodeList;
};

template <typename DataType>
Graph<DataType>::Graph(){
    
}

template <typename DataType>
Graph<DataType>::Graph(const Graph& other){
    for(int i = 0; i < other.m_adjacencyList.size(); i++){
        m_adjacencyList.push_back(other.m_adjacencyList[i]);
    }
}

template <typename DataType>
Graph<DataType>& Graph<DataType>::operator=(const Graph& other){
    if(&other == this){
        return *this;
    }
    m_adjacencyList.clear();
    for(int i = 0; i < other.m_adjacencyList.size(); i++){
        m_adjacencyList.push_back(other.m_adjacencyList[i]);
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
    cout << "Visited: Node " << myNode.m_id << endl;
}

#endif