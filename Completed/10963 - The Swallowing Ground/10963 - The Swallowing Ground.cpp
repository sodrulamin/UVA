#include <iostream>
#include <cstdlib>
//#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    //vector<bool> resultSet;
    bool firstTime = true;
    while(t > 0)
    {
        int n;
        cin >> n;
        int difference = 500;
        bool possible = true;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin >> a >> b;
            if(i == 0)
            {
                difference = abs(a - b);
            }
            else if(difference != abs(a - b))
                possible = false;
        }
        //resultSet.push_back(possible);
        if(firstTime)
            firstTime = false;
        else
            cout << endl;
        if(possible)
            cout << "yes\n";
        else
            cout << "no\n";
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(i > 0)
//            cout << endl;
//        if(resultSet[i])
//            cout << "yes\n";
//        else
//            cout << "no\n";
//    }

    return 0;
}
