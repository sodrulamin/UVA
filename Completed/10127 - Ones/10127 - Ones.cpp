#include <iostream>
//#include <vector>

using namespace std;

int main()
{
    int n;
    //vector<int> resultSet;
    while(cin >> n)
    {
        if(n <= 0)
            break;
        int divident = 1;
        int x = 1;
        while(divident % n != 0)
        {
            x++;
            divident = (divident % n) * 10 + 1;
        }
        cout << x << endl;
        //resultSet.push_back(x);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
