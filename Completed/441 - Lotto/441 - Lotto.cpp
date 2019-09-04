#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int n;
vector<vector<int> > resultSet;
int numbers[13];

void constructor(){
    resultSet.clear();
}

void findResult3(int index,int takenCount,bool taken[]){
    if(index > n || takenCount > 6 || (((n - index) + takenCount) < 6))
        return;
    else if(takenCount == 6){
        vector<int> result;
        for(int i=0;i<index;i++){
            if(taken[i]){
                result.push_back(numbers[i]);
            }
        }
        resultSet.push_back(result);
        return;
    }
    taken[index] = true;
    findResult3(index + 1, takenCount + 1, taken);

    taken[index] = false;
    findResult3(index + 1, takenCount, taken);
}
void printResult(){
    for(int i=0;i<resultSet.size();i++){
        vector<int> result = resultSet[i];
        for(int j=0;j<result.size();j++){
            cout << result[j] << " ";
        }
            cout << endl;
    }
}

int main(){
    int caseCount = 0;
    while (scanf("%d", &n), n){
        for(int i=0;i<n;i++){
            cin >> numbers[i];
        }
        constructor();
        sort(numbers,numbers + n);
        bool taken[13];
        findResult3(0,0,taken);
        if(caseCount > 0)
            cout << endl;
        printResult();
        caseCount++;
    }


    return 1;
}

