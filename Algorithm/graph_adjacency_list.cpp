#include <iostream>
#include <list>

using namespace std;

// Class to represent a graph
class Graph {
	int V; // No. of vertices'

	// Pointer to an array containing adjacency listsList
	list<int>* adj;

public:
	Graph(int V + 1); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);
	void print();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::print()
{
    list<int>::iterator it;
    for(int i=0;i<V;i++)
    {
        cout << i << ": ";
        it = adj[i].begin();
        while(it != adj[i].end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
}

