#include <iostream>
#include <map>
#include <vector>

using namespace std;

int n,m;
int cost[1000][1000];
map<int, vector<int> > graph;
bool isVisited[1000];
bool foundLoop;

void constructor(){
    foundLoop = false;
    graph.clear();
    for(int i=0;i < n;i++){
        for(int j=0;j<n;j++){
            cost[i][j] = 0;
        }
        isVisited[i] = false;
    }
}
void addEdge(int a, int b, int value){
    cost[a][b] = value;
    vector<int> adjList;
    map<int, vector<int> >::iterator it = graph.find(a);
    adjList = it->second;
    adjList.push_back(b);
    if(it != graph.end()){
        it->second = adjList;
    }
    else {
        graph.insert(pair<int, vector<int> >(a, adjList));
    }


}
void takeInput(){
    cin >> n >> m;
    constructor();
    int a,b,num;
    for(int i=0;i<m;i++){
        cin >> a >> b >> num;
        addEdge(a,b,num);
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

void processDFS2(int nodeNumber,int currentCost){
    if(foundLoop){
        return;
    }
    int earlyCost = cost[0][nodeNumber];
    cost[0][nodeNumber] = currentCost;
    isVisited[nodeNumber] = true;
    vector<int> adjList = graph.find(nodeNumber)->second;
    for(int i=0;i<adjList.size() && !foundLoop;i++){
        if(!isVisited[adjList[i]]){
            processDFS2(adjList[i], currentCost + cost[nodeNumber][adjList[i]]);
        }
        else{

            if(cost[0][adjList[i]] > currentCost + cost[nodeNumber][adjList[i]]){
                foundLoop = true;
                return;
            }
        }
    }
    isVisited[nodeNumber] = false;
    cost[0][nodeNumber] = earlyCost;
}

int main(){
    int c;
    cin >> c;
    while(c > 0){
        c--;
        takeInput();
        processDFS2(0,0);

        if(foundLoop){
            cout << "possible\n";
        }
        else {
            cout << "not possible\n";
        }
    }
}
