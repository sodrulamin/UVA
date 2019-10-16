#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>

using namespace std;

vector<string> beverageList;
map<string, int> nameToIndex;

struct Graph
{
    int v;
    list<int>* adj;
    bool *visited;

    Graph(int n)
    {
        v = n;
        adj = new list<int>[v];
    }

    void addEdge(int a, int b)
    {
        adj[a].push_back(b);
    }

    void addEdge(string s1, string s2)
    {
        int a,b;
        map<string, int>::iterator it = nameToIndex.find(s1);
        a = it->second;
        it = nameToIndex.find(s2);
        b = it->second;
        adj[a].push_back(b);
    }

    void print()
    {
        list<int>::iterator it;
        for(int i=0;i<v;i++)
        {
            cout << beverageList[i] << ": ";
            it = adj[i].begin();
            while(it != adj[i].end())
            {
                cout << beverageList[*it] << " ";
                it++;
            }
            cout << endl;
        }
    }

    bool isAvailable(int index, bool taken[])
    {
        list<int>::iterator it = adj[index].begin();
        while(it != adj[index].end())
        {
            if(!taken[*it])
                return false;
            it++;
        }
        return true;
    }

    void postOrderDFS(bool taken[], int depth, int sequence[])
    {
        if(depth == v)
        {
            for(int i=0;i<v;i++)
            {
                cout << " " << beverageList[sequence[i]];
            }
            return;
        }

        for(int i=0;i<v;i++)
        {
            if(!taken[i] && isAvailable(i, taken))
            {
                taken[i] = true;
                sequence[depth] = i;
                return postOrderDFS(taken, depth + 1, sequence);
            }
        }
    }
};

int main()
{
    int nodeCount,edgeCount, caseCount = 1;
    while(cin >> nodeCount)
    {
        if(nodeCount == 0)
            break;
        Graph g(nodeCount);

        beverageList.clear();
        nameToIndex.clear();

        string str, str2;
        for(int i=0;i<nodeCount;i++)
        {
            cin >> str;
            beverageList.push_back(str);
            nameToIndex.insert(make_pair(str, i));
        }

        cin >> edgeCount;

        for(int i=0;i<edgeCount;i++)
        {
            cin >> str >> str2;
            g.addEdge(str2, str);
        }

        //g.print();
        cout << "Case #" << caseCount++ << ": Dilbert should drink beverages in this order:";
        bool taken[nodeCount];
        for(int i=0;i<nodeCount;i++)
            taken[i] = false;
        int numbers[nodeCount];
        g.postOrderDFS(taken, 0, numbers);
        cout << ".\n\n";
    }
    return 0;
}
