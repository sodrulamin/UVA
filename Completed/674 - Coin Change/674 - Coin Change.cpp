#include <iostream>
#include <vector>

using namespace std;

long long wayCount;
int taken[5];
int cents[5] = {50,25,10,5,1};

void recursiveFind(int index,int n)
{
    if(index == 5)
    {
        if(n == 0)
            wayCount++;
        return;
    }
    int available = n / cents[index];
    for(int i=available;i>=0;i--)
    {
        int taken = cents[index] * i;
        recursiveFind(index + 1, n - taken);
    }
}

int main()
{
    int n;
    vector<long long> resultSet;
    while(cin >> n)
    {
        if(n == -1)
            break;
        wayCount = 0;
        for(int i=0;i<5;i++)
            taken[i] = 0;
        recursiveFind(0,n);
        cout << wayCount << endl;
        resultSet.push_back(wayCount);
    }
    for(int i=0;i<resultSet.size();i++)
    {
        cout << resultSet[i] << endl;
    }
    return 0;
}

