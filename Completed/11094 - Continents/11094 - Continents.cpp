#include <iostream>
#include <vector>

using namespace std;

int maxRow,maxCol;
char statesMap[20][20];
bool visited[20][20];

int visitRecursive(int i, int j, char cellValue)
{
    //cout << "Now visiting: " << i << " " << j << " cellValue: " << cellValue << " " << statesMap[i][j] << endl;
    int result = 1,nextCol,nextRow;

    if(i > 0)
    {
        nextRow = i - 1;
//        nextCol = (j - 1 + maxCol) % maxCol;
//        if(!visited[nextRow][nextCol] && statesMap[nextRow][nextCol] == cellValue)
//        {
//            visited[nextRow][nextCol] = true;
//            result += visitRecursive(nextRow, nextCol, cellValue);
//        }
        nextCol = j;
        if(!visited[nextRow][nextCol] && statesMap[nextRow][nextCol] == cellValue)
        {
            visited[nextRow][nextCol] = true;
            result += visitRecursive(nextRow, nextCol, cellValue);
        }
//        nextCol = (j + 1) % maxCol;
//        if(!visited[nextRow][nextCol] && statesMap[nextRow][nextCol] == cellValue)
//        {
//            visited[nextRow][nextCol] = true;
//            result += visitRecursive(nextRow, nextCol, cellValue);
//        }
    }


    nextRow = i;
    nextCol = (j - 1 + maxCol) % maxCol;
    if(!visited[nextRow][nextCol] && statesMap[nextRow][nextCol] == cellValue)
    {
        visited[nextRow][nextCol] = true;
        result += visitRecursive(nextRow, nextCol, cellValue);
    }
    nextCol = (j + 1) % maxCol;
    if(!visited[nextRow][nextCol] && statesMap[nextRow][nextCol] == cellValue)
    {
        visited[nextRow][nextCol] = true;
        result += visitRecursive(nextRow, nextCol, cellValue);
    }


    if(i < maxRow - 1)
    {
        nextRow = i + 1;
//        nextCol = (j - 1 + maxCol) % maxCol;
//        if(!visited[nextRow][nextCol] && statesMap[nextRow][nextCol] == cellValue)
//        {
//            visited[nextRow][nextCol] = true;
//            result += visitRecursive(nextRow, nextCol, cellValue);
//        }
        nextCol = j;
        if(!visited[nextRow][nextCol] && statesMap[nextRow][nextCol] == cellValue)
        {
            visited[nextRow][nextCol] = true;
            result += visitRecursive(nextRow, nextCol, cellValue);
        }
//        nextCol = (j + 1) % maxCol;
//        if(!visited[nextRow][nextCol] && statesMap[nextRow][nextCol] == cellValue)
//        {
//            visited[nextRow][nextCol] = true;
//            result += visitRecursive(nextRow, nextCol, cellValue);
//        }
    }

    return result;
}

int main()
{
    //vector<int> resultSet;
    while(cin >> maxRow >> maxCol)
    {
        //if(maxRow == 0 && maxCol == 0)break;
        for(int i=0;i<maxRow;i++)
        {
            for(int j=0;j<maxCol;j++)
            {
                cin >> statesMap[i][j];
                visited[i][j] = false;
            }
        }
        int i,j,maxContinent = 0, sizeOfContinent;
        cin >> i >> j;
        visited[i][j] = true;
        char cellValue = statesMap[i][j];
        visitRecursive(i, j, cellValue);
        for(i=0;i<maxRow;i++)
        {
            for(j=0;j<maxCol;j++)
            {
                if(statesMap[i][j] == cellValue && !visited[i][j])
                {
                    visited[i][j] = true;
                    sizeOfContinent = visitRecursive(i, j, cellValue);
                    if(sizeOfContinent > maxContinent)
                        maxContinent = sizeOfContinent;
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
