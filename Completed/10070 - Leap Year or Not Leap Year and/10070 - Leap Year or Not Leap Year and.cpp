#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getMod(string number,int divider)
{
    int a,mod = 0;
    for(int i=0;i<number.length();i++)
    {
        a = number[i] - '0';
        mod = mod * 10 + a;
        mod = mod % divider;
    }
    return mod;
}

int main()
{
    string n;
    int firstTime = true;
    //vector<int> resultSet;
    while(cin >> n)
    {
//        if(n == "-1")
//            break;

        if(firstTime)
            firstTime = false;
        else
            cout << endl;
        if(getMod(n,400) == 0 || (getMod(n,4) == 0 && getMod(n,100) != 0))
        {
            ///leap year
            cout << "This is leap year.\n";
            //resultSet.push_back(1);
            if(getMod(n,15) == 0)
            {
                ///Huluculu festival
                cout << "This is huluculu festival year.\n";
                //resultSet.push_back(2);
            }
            if(getMod(n,55) == 0)
            {
                ///Bulukulu festival
                cout << "This is bulukulu festival year.\n";
                //resultSet.push_back(3);
            }
        }
//        else if(getMod(n,4) == 0 && getMod(n,100) != 0)
//        {
//            ///leap year
//            cout << "This is leap year.\n";
//            //resultSet.push_back(1);
//            if(getMod(n,15) == 0)
//            {
//                ///Huluculu festival
//                cout << "This is huluculu festival year.\n";
//                //resultSet.push_back(2);
//
//            }
//            if(getMod(n,55) == 0)
//            {
//                ///Bulukulu festival
//                cout << "This is buluculu festival year.\n";
//                //resultSet.push_back(3);
//            }
//        }
        else if(getMod(n,15) == 0)
        {
            ///Huluculu festival
            cout << "This is huluculu festival year.\n";
            //resultSet.push_back(2);
//            if(getMod(n,55) == 0)
//            {
//                ///Bulukulu festival
//                cout << "This is bulukulu festival year.\n";
//                resultSet.push_back(3);
//            }
        }
//        else if(getMod(n,55) == 0)
//        {
//            ///Bulukulu festival
//            cout << "This is bulukulu festival year.\n";
//            resultSet.push_back(3);
//        }
        else
        {
            ///not leap year
            cout << "This is an ordinary year.\n";
            //resultSet.push_back(4);
        }
        //resultSet.push_back(0);
        //cout << endl;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i] == 0)
//            cout << endl;
//        else if(resultSet[i] == 1)
//            cout << "This is leap year.\n";
//        else if(resultSet[i] == 2)
//            cout << "This is huluculu festival year.\n";
//        else if(resultSet[i] == 3)
//            cout << "This is bulukulu festival year.\n";
//        else
//            cout << "This is an ordinary year.\n";
//    }
    return 0;
}
