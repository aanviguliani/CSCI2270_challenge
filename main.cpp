#include "Graph.hpp"
#include <fstream>
#include <sstream>
#include <exception>
using namespace std;

void addData(Graph &g){
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addVertex("D");
    g.addVertex("E");
    g.addEdge("A", "B", 4);
    g.addEdge("B", "C", 3);
    g.addEdge("A", "C", 2);
    g.addEdge("B", "D", 2);
    g.addEdge("E", "D", 1);
    g.addEdge("B", "E", 3);
    g.addEdge("C", "B", 1);
    g.addEdge("C", "D", 4);
    g.addEdge("C", "E", 5);
}
int main(int argc, char*argv[])
{
    Graph graph;
    addData(graph);

    string n1;
    string n2;

    cout << "Enter Node:" << endl;
    cin >> n1;

    cout << "Enter Node:" << endl;
    cin >> n2;

    graph.findShortestPath(n1, n2);
}