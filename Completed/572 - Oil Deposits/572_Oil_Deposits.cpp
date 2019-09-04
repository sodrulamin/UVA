#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int m,n,componentCount;
bool isOil[110][110];
bool isVisited[10000];
vector<int> result;

map<int, vector<int> > graph;


void constructor(){
    graph.clear();
    componentCount = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            isOil[i][j] = false;
            isVisited[i * n + j] = false;
        }
    }
}
void takeInput(){
    string str;
    for(int i=0;i<m;i++){
        cin >> str;
        for(int j=0;j<n;j++){
            isOil[i][j] = (str[j] == '@');
        }
    }
}
bool isValid(int i,int j){
    if(i < 0 || j < 0 || i >= m || j >= n)
        return false;
    return true;
}
vector<int> getAdjacents(int i,int j){
    int nodeNumber = n * i + j;
    vector<int> adjList;

    if(isValid(i - 1, j - 1) && isOil[i - 1][j - 1]){
        adjList.push_back(n * (i - 1) + (j - 1));
    }
    if(isValid(i - 1, j) && isOil[i - 1][j]){
        adjList.push_back(n * (i - 1) + (j));
    }
    if(isValid(i - 1, j + 1) && isOil[i - 1][j + 1]){
        adjList.push_back(n * (i - 1) + (j + 1));
    }
    if(isValid(i, j - 1) && isOil[i][j - 1]){
        adjList.push_back(n * (i) + (j - 1));
    }
    if(isValid(i, j + 1) && isOil[i][j + 1]){
        adjList.push_back(n * (i) + (j + 1));
    }
    if(isValid(i + 1, j - 1) && isOil[i + 1][j - 1]){
        adjList.push_back(n * (i + 1) + (j - 1));
    }
    if(isValid(i + 1, j) && isOil[i + 1][j]){
        adjList.push_back(n * (i + 1) + (j));
    }
    if(isValid(i + 1, j + 1) && isOil[i + 1][j + 1]){
        adjList.push_back(n * (i + 1) + (j + 1));
    }

    return adjList;
}
void createGraph(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(isOil[i][j]){
                vector<int> adjList = getAdjacents(i,j);
                graph.insert(pair<int, vector<int> >(n * i + j, adjList));
            }
        }
    }
}
void DFS(int nodeNumber){
    isVisited[nodeNumber] = true;
    vector<int> adjList = graph.find(nodeNumber)->second;
    for(int i=0;i<adjList.size();i++){
        if(!isVisited[adjList[i]]){
            DFS(adjList[i]);
        }
    }
}
void process(){
    createGraph();

    map<int,vector<int> >::iterator it = graph.begin();
    for (it=graph.begin(); it!=graph.end(); ++it){
        if(!isVisited[it->first]){
            componentCount++;
            DFS(it->first);
        }
    }

}
void printGraph(){
    map<int,vector<int> >::iterator it = graph.begin();
    for (it=graph.begin(); it!=graph.end(); ++it){
        vector<int> adjList = it->second;
        cout << it->first << ": ";
        for(int j=0;j<adjList.size();j++){
            cout << adjList[j] << " ";
        }
        cout << endl;
    }
}

int main(){
    while ( cin >> m ) {
        if(m <= 0)
            break;
        cin >> n;
        constructor();
        takeInput();
        process();

        cout << componentCount << endl;
    }

    cin >> n;
    return 0;
}


