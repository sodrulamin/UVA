#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

bool visited[26];

// Class to represent a graph
class Graph {
	int V; // No. of vertices'

	// Pointer to an array containing adjacency listsList
	list<int>* adj;

public:
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);
	void print();
	void runBFS(int nodeIndex);
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

void Graph::runBFS(int nodeIndex)
{
    queue<int> notVisitedYet;
    notVisitedYet.push(nodeIndex);
    visited[nodeIndex] = true;

    list<int>::iterator it;
    while(!notVisitedYet.empty())
    {
        nodeIndex = notVisitedYet.front();
        notVisitedYet.pop();
        it = adj[nodeIndex].begin();
        while(it != adj[nodeIndex].end())
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                notVisitedYet.push(*it);
            }
            it++;
        }
    }
}

int main()
{
    int t;
    stringstream ss;
    string str;

    //vector<int> resultSet;

    getline(cin, str);
    ss << str;
    ss >> t;
    ss.clear();
    getline(cin, str);  ///blank line
    while(t > 0)
    {
        getline(cin, str);
        int v = str[0] - 'A' + 1, a, b;
        Graph g(v);


        getline(cin, str);
        while(str.length() > 0)
        {
            a = str[0] - 'A';
            b = str[1] - 'A';
            g.addEdge(a,b);
            g.addEdge(b,a);
            getline(cin, str);
        }

        //g.print();
        for(int i=0;i<v;i++)
            visited[i] = false;

        int count = 0;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                g.runBFS(i);
                count++;
            }
        }
        cout << count << endl;
        //resultSet.push_back(count);
        t--;
        if(t)
            cout << endl;
    }

//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl << endl;
//    }

    return 0;
}
