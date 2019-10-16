#include <iostream>
#include <vector>

using namespace std;

int maxRow;
char seaMap[110][110];
bool visited[110][110];

void visitRecursive(int i, int j)
{
    //cout << "Now visiting: " << i << " " << j << " cellValue: " << cellValue << " " << seaMap[i][j] << endl;
    int nextCol,nextRow;

    if(i > 0)
    {
        nextRow = i - 1;
        nextCol = j;
        if(!visited[nextRow][nextCol] && seaMap[nextRow][nextCol] != '.')
        {
            visited[nextRow][nextCol] = true;
            visitRecursive(nextRow, nextCol);
        }
    }


    nextRow = i;
    if(j > 0)
    {
        nextCol = j - 1;
        if(!visited[nextRow][nextCol] && seaMap[nextRow][nextCol] != '.')
        {
            visited[nextRow][nextCol] = true;
            visitRecursive(nextRow, nextCol);
        }
    }

    if(j < maxRow - 1)
    {
        nextCol = j + 1;
        if(!visited[nextRow][nextCol] && seaMap[nextRow][nextCol] != '.')
        {
            visited[nextRow][nextCol] = true;
            visitRecursive(nextRow, nextCol);
        }
    }


    if(i < maxRow - 1)
    {
        nextRow = i + 1;

        nextCol = j;
        if(!visited[nextRow][nextCol] && seaMap[nextRow][nextCol] != '.')
        {
            visited[nextRow][nextCol] = true;
            visitRecursive(nextRow, nextCol);
        }
    }
}

int main()
{
    int t, caseCount = 1;
    cin >> t;
    //vector<int> resultSet;
    while(t > 0)
    {
        cin >> maxRow;
        //if(maxRow == 0)break;
        for(int i=0;i<maxRow;i++)
        {
            for(int j=0;j<maxRow;j++)
            {
                cin >> seaMap[i][j];
                visited[i][j] = false;
            }
        }
        int i,j,aliveShip = 0;
        char cellValue = 'x';
        for(i=0;i<maxRow;i++)
        {
            for(j=0;j<maxRow;j++)
            {
                if(seaMap[i][j] == cellValue && !visited[i][j])
                {
                    visited[i][j] = true;
                    visitRecursive(i, j);
                    aliveShip++;
                }
            }
        }
        cout << "Case " << caseCount++ << ": " << aliveShip << endl;
        //resultSet.push_back(aliveShip);
        t--;
    }

//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "Case " << (i + 1) << ": " << resultSet[i] << endl;
//    }

    return 0;
}
