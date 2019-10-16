#include <iostream>
#include <string>

using namespace std;

int main()
{
    int nRow,nCol,currentColumn;
    while(cin >> nRow >> nCol >> currentColumn)
    {
        if(nRow == 0 && nCol == 0 && currentColumn == 0)
            break;
        char instructions[nRow][nCol];
        int distance[nRow][nCol];
        for(int i=0;i<nRow;i++)
        {
            for(int j=0;j<nCol;j++)
            {
                cin >> instructions[i][j];
                distance[i][j] = -1;
            }
        }
        currentColumn--;
        int currentDistance = 0, currentRow = 0, endStatus = 0, resultDistance = 0;

        distance[currentRow][currentColumn] = 0;

        while(endStatus == 0)
        {
            currentDistance++;
            switch(instructions[currentRow][currentColumn])
            {
                case 'N':
                    currentRow--;
                    break;
                case 'S':
                    currentRow++;
                    break;
                case 'E':
                    currentColumn++;
                    break;
                case 'W':
                    currentColumn--;
                    break;
            }
            if(currentRow < 0 || currentRow >= nRow || currentColumn < 0 || currentColumn >= nCol)
            {
                endStatus = 1;
                resultDistance = currentDistance;
            }
            else if(distance[currentRow][currentColumn] != -1)
            {
                endStatus = 2;
                resultDistance = currentDistance - distance[currentRow][currentColumn];
            }
            else
            {
                distance[currentRow][currentColumn] = currentDistance;
            }
        }

        switch(endStatus)
        {
            case 1:
                cout << resultDistance << " step(s) to exit" << endl;
                break;
            case 2:
                cout << distance[currentRow][currentColumn] << " step(s) before a loop of " << resultDistance << " step(s)" << endl;
                break;
        }
    }

    return 0;
}
