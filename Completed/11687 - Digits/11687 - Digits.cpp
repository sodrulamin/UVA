#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string number;
    //vector<int> resultSet;
    while(cin >> number)
    {
        if(number == "END")
            break;
        else if(number == "1")
        {
            cout << "1" << endl;
            //resultSet.push_back(1);
            continue;
        }
        int num = number.length();
        int i=2;
        while(true)
        {
            int a = num;
            int newNum = 0;
            while(a > 0)
            {
                a /= 10;
                newNum++;
            }
            if(newNum == num)
                break;
            num = newNum;
            i++;
        }
        cout << i << endl;
        //resultSet.push_back(i);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
