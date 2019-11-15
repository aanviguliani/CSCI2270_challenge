#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <queue>
#include "Graph.hpp"

using namespace std;

Graph::Graph(){}
Graph::~Graph() {}
void Graph::addEdge(string v1, string v2, int w)
{
    adjVertex* newEdge = new adjVertex;
    newEdge->v = findVertex(v2);
    newEdge->weight = w;
    findVertex(v1)->adj.push_back(newEdge);
}

void Graph::addVertex(string n)
{
    bool found = false;
    cout<<n<<endl;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name  == n)
        {
            found = true;
            return;
        }
    }
    vertex* v = new vertex();
    v->name = n;
    vertices.push_back(v);
}

vertex* Graph::findVertex(std::string name)
{
    for (int i = 0; i < vertices.size(); i++)
    {
        cout<<vertices[i]->name<<" "<<name<<endl;
        if (vertices[i]->name == name)
        {
            return vertices[i];
        }
    }
    return NULL;
}


void Graph::findShortestPath(string start, string end)
{
    vertex* s = findVertex(start);
    vertex* e = findVertex(end);

    s->solved = true;
    s->distance = 0;
    vector<vertex*> solved;
    solved.push_back(s);
    vertex* solvedVertex;
    vertex* parent;
    while (!e->solved)
    {
        int minDistance = INT32_MAX;
        solvedVertex = NULL;
        for (int i = 0; i < solved.size(); ++i)
        {
            vertex* s = solved[i];
            for (int j = 0; j < s->adj.size(); ++j)
            {
                if (!s->adj[j]->v->solved)
                {
                    int dist = s->distance + s->adj[j]->weight;
                    if (dist < minDistance)
                    {
                        solvedVertex = s->adj[j]->v;
                        minDistance = dist;
                        parent = s;
                    }
                }
            }
        }
        solvedVertex->distance = minDistance;
        solvedVertex->parent = parent;
        solvedVertex->solved = true;
        solved.push_back(solvedVertex);
    }
    for(int i = 0; i < solved.size(); i++)
    {
        cout<<solved[i]->name<<endl;
    }
    cout<<"Total Distance: "<<solvedVertex->distance<<endl;
};