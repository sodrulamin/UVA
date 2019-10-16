#include <iostream>
#include <cmath>

#define FRONT 0
#define BACK 1
#define LEFT 0
#define RIGHT 1

using namespace std;


int pageCount[110][2][2];

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;
        cout << "Printing order for " << n << " pages:" << endl;
        int sheetCount = ceil(n/4.0);
        //cout << "SheetCount: " << sheetCount << endl;
        int pageIndex = 1;
        for(int i=1;i<=sheetCount;i++)
        {
            if(pageIndex <= n)
            {
                pageCount[i][FRONT][RIGHT] = pageIndex++;
            }
            else
                pageCount[i][FRONT][RIGHT] = 0;
            if(pageIndex <= n)
            {
                pageCount[i][BACK][LEFT] = pageIndex++;
            }
            else
                pageCount[i][BACK][LEFT] = 0;
        }
        for(int i=sheetCount;i>0;i--)
        {
            if(pageIndex <= n)
            {
                pageCount[i][BACK][RIGHT] = pageIndex++;
            }
            else
                pageCount[i][BACK][RIGHT] = 0;
            if(pageIndex <= n)
            {
                pageCount[i][FRONT][LEFT] = pageIndex++;
            }
            else
                pageCount[i][FRONT][LEFT] = 0;
        }

        for(int i=1;i<=sheetCount;i++)
        {
            cout << "Sheet " << i << ", front: ";
            if(pageCount[i][FRONT][LEFT])
                cout << pageCount[i][FRONT][LEFT];
            else
                cout << "Blank";
            cout << ", " << pageCount[i][FRONT][RIGHT] << endl;

            if(pageCount[i][BACK][LEFT])
            {
                cout << "Sheet " << i << ", back : " << pageCount[i][BACK][LEFT] << ", ";
                if(pageCount[i][BACK][RIGHT])
                    cout << pageCount[i][BACK][RIGHT];
                else
                    cout << "Blank";
                cout << endl;
            }

        }
    }
    return 0;
}
