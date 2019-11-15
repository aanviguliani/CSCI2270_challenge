#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

using namespace std;

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    int ID;
    std::string name;
    std::vector<adjVertex*> adj;
    int distance;
    vertex* parent;
    bool visited;
    bool solved;
};


class Graph {
public:
    Graph();
    ~Graph();
    vertex* findVertex(std::string name);
    void addEdge(std::string v1, std::string v2, int w);
    void addVertex(std::string name);
    void findShortestPath(std::string, std::string);
private:
    //vector<edge> edges;
    std::vector<vertex*> vertices;
};

#endif // GRAPH_HPP
