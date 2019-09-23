#include <iostream>
//#include <vector>

using namespace std;

int reservs[40];

int main()
{
    int n,m;
    //vector<bool> resultSet;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)
            break;
        for(int i=1;i<=n;i++)
        {
            cin >> reservs[i];
        }
        int a,b,c;
        for(int i=0;i<m;i++)
        {
            cin >> a >> b >> c;
            reservs[a] -= c;
            reservs[b] += c;
        }
        bool possible = true;
        for(int i=1;i<=n;i++)
        {
            if(reservs[i] < 0)
            {
                possible = false;
                break;
            }
        }
        //resultSet.push_back(possible);
        if(possible)
        {
            cout << "S\n";
        }
        else
        {
            cout << "N\n";
        }
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i])
//        {
//            cout << "S\n";
//        }
//        else
//        {
//            cout << "N\n";
//        }
//    }
    return 0;
}
