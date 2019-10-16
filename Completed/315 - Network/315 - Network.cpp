#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <queue>

using namespace std;

int mapping[100][100] = {0};

bool isAllConnected(int n, int startingNode, int criticalNode)
{
    bool visited[n+1];
    for(int i=1;i<=n;i++)
    {
        visited[i] = false;
    }

    queue<int> notVisitedYet;
    notVisitedYet.push(startingNode);
    visited[startingNode] = true;
    int node;
    //cout << "Visiting: ";
    while(!notVisitedYet.empty())
    {

        node = notVisitedYet.front();
        notVisitedYet.pop();
        if(node == criticalNode)
            continue;
        //cout << " " << node;

        for(int i=1;i<=n;i++)
        {
            if(mapping[node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                notVisitedYet.push(i);
            }
        }
    }
    //cout << endl;

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
            return false;
    }
    return true;
}

int main()
{
    string str;
    int n;
    //vector<int> resultSet;
    while(getline(cin, str))
    {
        stringstream ss;
        ss << str;
        ss >> n;
        if(n == 0)
            break;

        ss.clear();
        bool nextLine = true;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mapping[i][j] = false;

        while(nextLine)
        {
            getline(cin, str);
            ss.clear();
            ss << str;
            int a, j = 0;
            ss >> a;
            if(a == 0)
                break;
            while(ss >> j)
            {
                mapping[a][j] = 1;
                mapping[j][a] = 1;
            }
        }
        int criticalPointCount = 0,startingNode;
        for(int criticalPoint = 1;criticalPoint <= n; criticalPoint++)
        {
            startingNode = 1;
            if(startingNode == criticalPoint)
                startingNode++;

            if(!isAllConnected(n, startingNode, criticalPoint))
            {
                criticalPointCount++;
            }
        }
        cout << criticalPointCount << endl;
        //resultSet.push_back(criticalPointCount);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }

    return 0;
}
