#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    string str = "on";
    int lowerBound = 0, upperBound = 11;
    //vector<bool> resultSet;
    while(cin >> n)
    {
        if(n == 0)
            break;
        cin >> str;
        cin >> str;
        if(str == "high")
        {
            if(upperBound > n)
            {
                upperBound = n;
            }
        }
        else if(str == "low")
        {
            if(lowerBound < n)
            {
                lowerBound = n;
            }
        }
        else if(str == "on")
        {

            if(n > lowerBound && n < upperBound)
            {
                cout << "Stan may be honest" << endl;
                //resultSet.push_back(true);
            }
            else
            {
                cout << "Stan is dishonest" << endl;
                //resultSet.push_back(false);
            }
            lowerBound = 0;
            upperBound = 11;
        }
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i])
//        {
//            cout << "Stan may be honest" << endl;
//        }
//        else
//        {
//            cout << "Stan is dishonest" << endl;
//        }
//    }
    return 0;
}
