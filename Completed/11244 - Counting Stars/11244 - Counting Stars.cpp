#include <iostream>
#include <vector>

using namespace std;

int maxRow,maxCol;
char starMap[110][110];
bool visited[110][110];

int visitRecursive(int i, int j, char cellValue)
{
    //cout << "Now visiting: " << i << " " << j << " cellValue: " << cellValue << " " << starMap[i][j] << endl;
    int result = 1,nextCol,nextRow;

    if(i > 0)
    {
        nextRow = i - 1;
        if(j > 0)
        {
            nextCol = j - 1;
            if(!visited[nextRow][nextCol] && starMap[nextRow][nextCol] == cellValue)
            {
                visited[nextRow][nextCol] = true;
                result += visitRecursive(nextRow, nextCol, cellValue);
            }
        }

        nextCol = j;
        if(!visited[nextRow][nextCol] && starMap[nextRow][nextCol] == cellValue)
        {
            visited[nextRow][nextCol] = true;
            result += visitRecursive(nextRow, nextCol, cellValue);
        }

        if(j < maxCol - 1)
        {
            nextCol = j + 1;
            if(!visited[nextRow][nextCol] && starMap[nextRow][nextCol] == cellValue)
            {
                visited[nextRow][nextCol] = true;
                result += visitRecursive(nextRow, nextCol, cellValue);
            }
        }

    }


    nextRow = i;
    if(j > 0)
    {
        nextCol = j - 1;
        if(!visited[nextRow][nextCol] && starMap[nextRow][nextCol] == cellValue)
        {
            visited[nextRow][nextCol] = true;
            result += visitRecursive(nextRow, nextCol, cellValue);
        }
    }

    if(j < maxCol - 1)
    {
        nextCol = j + 1;
        if(!visited[nextRow][nextCol] && starMap[nextRow][nextCol] == cellValue)
        {
            visited[nextRow][nextCol] = true;
            result += visitRecursive(nextRow, nextCol, cellValue);
        }
    }


    if(i < maxRow - 1)
    {
        nextRow = i + 1;
        if(j > 0)
        {
            nextCol = j - 1;
            if(!visited[nextRow][nextCol] && starMap[nextRow][nextCol] == cellValue)
            {
                visited[nextRow][nextCol] = true;
                result += visitRecursive(nextRow, nextCol, cellValue);
            }
        }

        nextCol = j;
        if(!visited[nextRow][nextCol] && starMap[nextRow][nextCol] == cellValue)
        {
            visited[nextRow][nextCol] = true;
            result += visitRecursive(nextRow, nextCol, cellValue);
        }

        if(j < maxCol - 1)
        {
            nextCol = j + 1;
            if(!visited[nextRow][nextCol] && starMap[nextRow][nextCol] == cellValue)
            {
                visited[nextRow][nextCol] = true;
                result += visitRecursive(nextRow, nextCol, cellValue);
            }
        }
    }

    return result;
}

int main()
{
    //vector<int> resultSet;
    while(cin >> maxRow >> maxCol)
    {
        if(maxRow == 0 && maxCol == 0)break;
        for(int i=0;i<maxRow;i++)
        {
            for(int j=0;j<maxCol;j++)
            {
                cin >> starMap[i][j];
                visited[i][j] = false;
            }
        }
        int i,j,maxContinent = 0, countOfStars;
        char cellValue = '*';
        for(i=0;i<maxRow;i++)
        {
            for(j=0;j<maxCol;j++)
            {
                if(starMap[i][j] == cellValue && !visited[i][j])
                {
                    visited[i][j] = true;
                    countOfStars = visitRecursive(i, j, cellValue);
                    if(countOfStars == 1)
                        maxContinent++;
                }
            }
        }
        cout << maxContinent << endl;
        //resultSet.push_back(maxContinent);
    }

//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }

    return 0;
}
