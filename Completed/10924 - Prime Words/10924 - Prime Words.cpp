#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    int i = 2;
    while(i * i <= n)
    {
        if(n % i == 0)
            return false;
        i++;
    }
    return true;
}

int main()
{
    string str;
//    vector<bool> resultSet;
    while(cin >> str)
    {
        int n = 0;
//        if(str == "-1")
//            break;
        for(int i=0;i<str.length();i++)
        {
            if(isupper(str[i]))
            {
                n += (str[i] - 'A' + 27);
            }
            else
            {
                n += (str[i] - 'a' + 1);
            }
        }
        if(isPrime(n))
        {
            cout << "It is a prime word.\n";
//            resultSet.push_back(true);
        }
        else
        {
            cout << "It is not a prime word.\n";
//            resultSet.push_back(false);
        }
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i])
//        {
//            cout << "It is a prime word.\n";
//        }
//        else
//        {
//            cout << "It is not a prime word.\n";
//        }
//    }
    return 0;
}
