#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

vector<int> vertexCountList;
vector<int> resultSet;

struct Graph {
	int V; // No. of vertices'

	// Pointer to an array containing adjacency listsList
	list<int>* adj;
	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int v, int w);
	void print();
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

void Graph::print()
{
    for(int i=1;i<=V;i++)
    {
        cout << i << ": ";
        list<int>::iterator it = adj[i].begin();
        while(it != adj[i].end())
        {
            cout << *it << " ";
            it++;
        }
        cout << endl;
    }
}

void runBFS(Graph g,int startVertex)
{
    bool visited[g.V + 1];
    for(int i=1;i<=g.V;i++)
    {
        visited[i] = false;
    }

    queue<int> notVisitedYet;
    int notVisitedVerticesCount = g.V;

    list<int>::iterator it = g.adj[startVertex].begin();
    while(it != g.adj[startVertex].end())
    {
        notVisitedYet.push(*it);
        notVisitedVerticesCount--;
        visited[*it] = true;
        it++;
    }
    while(!notVisitedYet.empty())
    {
        int v = notVisitedYet.front();
        notVisitedYet.pop();
        it = g.adj[v].begin();
        while(it != g.adj[v].end())
        {
            if(!visited[*it])
            {
                notVisitedYet.push(*it);
                notVisitedVerticesCount--;
                visited[*it] = true;
            }
            it++;
        }
    }

    //vertexCountList.push_back(notVisitedVerticesCount);
    cout << notVisitedVerticesCount;
    for(int i=1;i<=g.V;i++)
    {
        if(!visited[i])
        {
            cout << " " << i;
            //resultSet.push_back(i);
        }
    }
    cout << endl;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;
        Graph g(n);
        int a;
        while(cin >> a)
        {
            if(a == 0)
                break;
            int b;
            while(cin >> b)
            {
                if(b == 0)
                    break;
                ///add edge a,b
                g.addEdge(a,b);
            }
        }
        int numberOfStartingVertices,startingVertex;
        list<int> startingVerticesList;
        cin >> a;
        for(int i=0;i<a;i++)
        {
            cin >> startingVertex;
            startingVerticesList.push_back(startingVertex);
        }
        //g.print();
        list<int>::iterator it = startingVerticesList.begin();
        while(it != startingVerticesList.end())
        {
            runBFS(g,*it);
            it++;
        }
    }

//    cout << "Starting to print all result\n";
//    int j=0;
//    for(int i=0;i<vertexCountList.size();i++)
//    {
//        cout << vertexCountList[i] << " ";
//        for(int k=0;k<vertexCountList[i];k++)
//        {
//            cout << resultSet[j++] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
