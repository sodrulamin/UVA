#include <iostream>
#include <vector>

using namespace std;

int getPow(int x, int p)
{
    int result = 1;
    for(int i=0;i<p;i++)
    {
        result *= x;
    }
    return result;
}

int main()
{
    unsigned int n;
    int t;
    cin >> t;
    //vector<bool> resultSet;
    while(t > 0)
    {
        cin >> n;
        int digitCount = 0;
        unsigned int temp = n;
        vector<int> digitList;
        while(temp)
        {
            digitCount++;
            digitList.push_back(temp % 10);
            temp /= 10;
        }
        temp = 0;
        for(int i=0;i<digitCount;i++)
        {
            temp += getPow(digitList[i], digitCount);
        }
        if(temp == n)
            cout << "Armstrong" << endl;
        else
            cout << "Not Armstrong" << endl;
        //resultSet.push_back(temp == n);

        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i])
//            cout << "Armstrong" << endl;
//        else
//            cout << "Not Armstrong" << endl;
//    }
    return 0;
}
