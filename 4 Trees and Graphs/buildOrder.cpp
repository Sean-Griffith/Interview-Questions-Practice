/*
    You are given a list of projects and a list of dependencies
    (which is a list of pairs of projects, where the second project
    is dependent on the first project). All of a projects dependencies
    must be built before the project is. Find a build order that will
    allow the projects to be built. If there is no valid build order, 
    return an error.

    EXAMPLE
    Input:
        projects: a, b, c, d, e, f
        dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
    Output: f, e, a, b, d, c
*/

#include <iostream>
#include "Graph.h"
using namespace std;

int main(){
    Graph<char> dependencies;
    Node<char> a, b, c, d, e, f;
    a.m_data = 'a';
    b.m_data = 'b';
    c.m_data = 'c';
    d.m_data = 'd';
    e.m_data = 'e';
    f.m_data = 'f';
    dependencies.InsertNode(a);
    dependencies.InsertNode(b);
    dependencies.InsertNode(c);
    dependencies.InsertNode(d);
    dependencies.InsertNode(e);
    dependencies.InsertNode(f);
    Edge ad, fb, bd, fa, dc, cd;
    ad = {0,0,3};
    fb = {5,0,1};
    bd = {1,0,3};
    fa = {5,0,0};
    dc = {3,0,2};
    cd = {2,0,3};
    dependencies.InsertEdge(ad);
    dependencies.InsertEdge(fb);
    dependencies.InsertEdge(bd);
    dependencies.InsertEdge(fa);
    dependencies.InsertEdge(dc);
    //dependencies.InsertEdge(cd);

    dependencies.ListEdges();
    /*
        O(n+d) time complexity: n = # of nodes, d = # of dependencies 
        O(n) space complexity

        The build order for a list of projects can be found by using DFS to build
        projects with no dependencies before projects with dependencies. This 
        algorithm can then be repeated for all unbuilt projects until either
        a cycle is detected (in which case no build order is possible), or all
        projects have a predetermined spot in the build order.
    */
    vector<char> depList = dependencies.OrderDependencies();
    cout << "Build order: ";
    for(int i = 0; i < depList.size(); i++){
        cout << depList[i] << " ";
    }
    cout << endl;
    return 1;
}