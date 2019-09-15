#include <iostream>
#include <list>

// Class to represent a graph
class Graph {
	int V; // No. of vertices'

	// Pointer to an array containing adjacency listsList
	list<int>* adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V + 1];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

