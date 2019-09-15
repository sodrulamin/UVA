#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

map<int, vector<int> > graph;

void addEdge(int a, int b)
{
    map<int, vector<int> >::iterator it;
    it = graph.find(a);
    if(it == graph.end())
    {
        vector<int> adj;
        adj.push_back(b);
        graph.insert(make_pair(a,adj));
    }
    else
    {
        it->second.push_back(b);
    }

    it = graph.find(b);
    if(it == graph.end())
    {
        vector<int> adj;
        adj.push_back(a);
        graph.insert(make_pair(b,adj));
    }
    else
    {
        it->second.push_back(a);
    }
}
bool isBypertite(int n)
{
    map<int, vector<int> >::iterator it;
    bool visited[200] = {false};
    int colored[200] = {-1};
    for(int i=0;i<n;i++)
    {
        if(visited[i])
        {
            continue;
        }
        int color = 1;
        queue<int> pendingQueue;
        pendingQueue.push(i);
        colored[i] = color;
        visited[i] = true;
        while(!pendingQueue.empty())
        {
            int curNode = pendingQueue.front();
            pendingQueue.pop();
            it = graph.find(curNode);
            vector<int> adj = it->second;
            color = (colored[curNode] + 1) % 2;
            for(int j = 0;j<adj.size();j++)
            {
                if(!visited[adj[j]])
                {
                    visited[adj[j]] = true;
                    colored[adj[j]] = color;
                    pendingQueue.push(adj[j]);
                }
                else if(colored[adj[j]] != color)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n,e;
    while(cin >> n)
    {
        if(n == 0)
            break;
        cin >> e;

        graph.clear();
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin >> a >> b;
            addEdge(a,b);
            addEdge(b,a);
        }
        if(isBypertite(n))
        {
            cout << "BICOLORABLE.\n";
        }
        else
        {
            cout << "NOT BICOLORABLE.\n";
        }
    }
    return 0;
}
