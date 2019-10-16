#include <iostream>
#include <vector>


#define N 2000

using namespace std;

int max_row,max_col;
int world[N][N];

void visitCell(int i, int j, int cellValue)
{
    if(i > 0 && world[i - 1][j] == cellValue)
    {
        world[i - 1][j] = -1;
        visitCell(i - 1, j, cellValue);
    }
    if(j > 0 && world[i][j - 1] == cellValue)
    {
        world[i][j - 1] = -1;
        visitCell(i, j - 1, cellValue);
    }
    if(j < max_col - 1 && world[i][j + 1] == cellValue)
    {
        world[i][j + 1] = -1;
        visitCell(i, j + 1, cellValue);
    }
    if(i < max_row && world[i + 1][j] == cellValue)
    {
        world[i + 1][j] = -1;
        visitCell(i + 1, j, cellValue);
    }
}

int main()
{
    int t,worldCount = 1;
    cin >> t;

    while(t > 0)
    {
        cin >> max_row >> max_col;
        char ch;
        for(int i=0;i<max_row;i++)
        {
            for(int j=0;j<max_col;j++)
            {
                cin >> ch;
                world[i][j] = ch - 'a';
            }
        }
        int stateCount[26] = {0};
        int cellValue;
        for(int i=0;i<max_row;i++)
        {
            for(int j=0;j<max_col;j++)
            {
                if(world[i][j] != -1)
                {
                    cellValue = world[i][j];
                    stateCount[cellValue]++;
                    world[i][j] = -1;
                    visitCell(i, j, cellValue);
                }
            }
        }
        cout << "World #" << worldCount++ << endl;
        int index = 0;
        for(int i=1;i<26;i++)
        {
            if(stateCount[i] > stateCount[index])
            {
                index = i;
            }
        }
        while(stateCount[index] > 0)
        {
            ch = 'a' + index;
            cout << ch << ": " << stateCount[index] << endl;
            stateCount[index] = 0;
            index = 0;
            for(int i=1;i<26;i++)
            {
                if(stateCount[i] > stateCount[index])
                {
                    index = i;
                }
            }
        }

        t--;
    }
    return 0;
}
