#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    //vector<int> resultSet;
    while(cin >> n)
    {
        if(n == 0)
            break;
        int top = 1, north = 2, west = 3, temp;
        string moveStr;
        for(int i=0;i<n;i++)
        {
            cin >> moveStr;
            if(moveStr == "north")
            {
                temp = 7 - north;
                north = top;
                top = temp;
            }
            else if(moveStr == "east")
            {
                temp = 7 - top;
                top = west;
                west = temp;
            }
            else if(moveStr == "south")
            {
                temp = 7 - top;
                top = north;
                north = temp;
            }
            else if(moveStr == "west")
            {
                temp = 7 - west;
                west = top;
                top = temp;
            }
        }
        cout << top << endl;
        //resultSet.push_back(top);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
