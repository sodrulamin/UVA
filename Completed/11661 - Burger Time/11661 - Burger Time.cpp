#include <iostream>
#include <string>
/*#include <cstdlib>*/
#include <vector>

using namespace std;

int main()
{
    string line;
    int n;
    /*vector<int> resultSet;*/
    while(cin >> n)
    {
        if(n == 0)
            break;
        cin >> line;
        int minDistance = 99999999;
        int lastR = -1, lastD = -1;
        for(int i=0;i<line.length();i++)
        {
            if(line[i] == 'Z')
            {
                lastD = i;
                lastR = i;
            }
            else if(line[i] == 'R')
            {
                lastR = i;
            }
            else if(line[i] == 'D')
            {
                lastD = i;
            }

            if(lastD != -1 && lastR != -1)
            {
                int dist = lastD - lastR;
                if(dist < 0)
                    dist *= -1;
                if(dist < minDistance)
                    minDistance = dist;
            }
        }
        cout << minDistance << endl;
        /*resultSet.push_back(minDistance);*/
    }
/*    for(int i=0;i<resultSet.size();i++)
    {
        cout << resultSet[i] << endl;
    }*/
    return 0;
}
