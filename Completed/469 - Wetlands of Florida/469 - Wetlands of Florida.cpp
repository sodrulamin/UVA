#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define N 100

using namespace std;

bool wetland[N][N];
bool visited[N][N];

int getWetLandArea(int i,int j, int n, int m)
{
    visited[i][j] = true;
    //cout << "Now visiting: " << i << " " << j << " wetland: " << wetland[i][j] << endl;
    int result = 1;
    if(i > 0 && j > 0 && wetland[i - 1][j - 1] && !visited[i - 1][j - 1])
    {
        result += getWetLandArea(i - 1, j - 1, n, m);
    }
    if(i > 0 && wetland[i - 1][j] && !visited[i - 1][j])
    {
        result += getWetLandArea(i - 1, j, n, m);
    }
    if(i > 0 && j < m - 1 && wetland[i - 1][j + 1] && !visited[i - 1][j + 1])
    {
        result += getWetLandArea(i - 1, j + 1, n, m);
    }
    if(j > 0 && wetland[i][j - 1] && !visited[i][j - 1])
    {
        result += getWetLandArea(i, j - 1, n, m);
    }
    if(j < m - 1 && wetland[i][j + 1] && !visited[i][j + 1])
    {
        result += getWetLandArea(i, j + 1, n, m);
    }
    if(i < n - 1 && j > 0 && wetland[i + 1][j - 1] && !visited[i + 1][j - 1])
    {
        result += getWetLandArea(i + 1, j - 1, n, m);
    }
    if(i < n - 1 && wetland[i + 1][j] && !visited[i + 1][j])
    {
        result += getWetLandArea(i + 1, j, n, m);
    }
    if(i < n - 1 && j < m - 1 && wetland[i + 1][j + 1] && !visited[i + 1][j + 1])
    {
        result += getWetLandArea(i + 1, j + 1, n, m);
    }
    return result;
}

int main()
{
    string str;
    stringstream ss;
    int t;
    getline(cin, str);
    ss << str;
    ss >> t;
    getline(cin, str);
    //vector<int> resultSet;
    while(t > 0)
    {
        int n = 0,m = 0,row,col;
        getline(cin, str);
        while(str.length() > 0)
        {
            if(isalpha(str[0]))
            {
                if(m == 0)
                    m = str.length();
                for(int i=0;i<m;i++)
                {
                    wetland[n][i] = (str[i] == 'W');
                }
                n++;
            }
            else
            {
                ss.clear();
                ss << str;
                ss >> row;
                ss >> col;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        visited[i][j] = false;
                    }
                }
                int result = getWetLandArea(row - 1, col - 1, n, m);
                cout << result << endl;
                //resultSet.push_back(result);
            }
            getline(cin, str);
        }
        //resultSet.push_back(-1);

        t--;
        if(t)
            cout << endl;
    }

//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i] == -1)
//        {
//            cout << endl;
//        }
//        else
//        {
//            cout << resultSet[i] << endl;
//        }
//    }

    return 0;
}
