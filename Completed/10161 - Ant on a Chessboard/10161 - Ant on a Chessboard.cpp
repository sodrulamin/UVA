#include <iostream>
#include <cmath>
#include <vector>

#define bigint unsigned long long

using namespace std;

int main()
{
    bigint s;
//    vector<int> rowSet;
//    vector<int> colSet;
    while(cin >> s)
    {
        if(s == 0)
            break;
        int n = ceil(sqrt(s));
        int l =(n * n) - s;
        int a = 1 + 2 * (n - 1);
        l = a - l;
        int row,col;
        if(n & 1)
        {
            if(n < l)
            {
                row = 2 * n - l;
                col = n;
            }
            else
            {
                row = n;
                col = l;
            }
        }
        else
        {
            if(n <= l)
            {
                row = n;
                col = a - l + 1;
            }
            else
            {
                col = n;
                row = l;
            }
        }
        cout << row << " " << col << endl;
//        rowSet.push_back(row);
//        colSet.push_back(col);
    }
//    for(int i=0;i<rowSet.size();i++)
//    {
//        cout << rowSet[i] << " " << colSet[i] << endl;
//    }
    return 0;
}
