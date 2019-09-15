#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int HIGHEST_VALUE = 30001;
int coins[] = {1, 5, 10, 25, 50};

int main()
{
    vector<long long> numWays(HIGHEST_VALUE, 0);
    numWays[0] = 1;

    // Solve for all questions
    for (int coin = 0; coin < 5; ++coin)
        for (int from = 0, i = coins[coin]; i < HIGHEST_VALUE; ++from, ++i)
            numWays[i] += numWays[from];


    int n;
//    vector<long long> resultSet;
    while(cin >> n)
    {
        if(n < 0)
        {
            break;
        }
        //resultSet.push_back(numWays[n]);
        //cout << numWays[n] << endl;
        if(numWays[n] > 1)
        {
            cout << "There are " << numWays[n] << " ways to produce " << n << " cents change.\n";
        }
        else
        {
            cout << "There is only " << numWays[n] << " way to produce " << n << " cents change.\n";
        }
    }
    /*for(int i=0;i<resultSet.size();i++)
    {
        cout << resultSet[i] << endl;
    }*/
    return 0;
}
