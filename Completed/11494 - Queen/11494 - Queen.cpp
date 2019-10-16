#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int i1,j1,i2,j2;
    //vector<int> resultSet;
    while(cin >> i1 >> j1 >> i2 >> j2)
    {
        if(i1 == 0 && j1 == 0 && i2 == 0 && j2 == 0)
            break;
        int result = 2;
        if(i1 == i2 && j1 == j2)
            result = 0;
        else if(i1 == i2 || j1 == j2)
            result = 1;
        else if(abs(i1 - i2) == abs(j1 - j2))
            result = 1;

        cout << result << endl;
        //resultSet.push_back(result);

    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
