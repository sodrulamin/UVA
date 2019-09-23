#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>

#define MAX_NUM 1001

using namespace std;

string product(string str1,string str2)
{
    //char result[str1.length() + str2.length()];
    string str;
    for(int i=0;i<str1.length() + str2.length();i++)
        str = str + "0";
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());

    for(int i=0;i<str1.length();i++)
    {
        int mult = 0,carry = 0,sum;
        int j=0;
        for(;j<str2.length();j++)
        {
            mult = (str2[j] - '0') * (str1[i] - '0');
            sum = (str[i + j] - '0') + mult + carry;
            carry = sum / 10;
            sum = sum % 10;
            str[i + j] = '0' + sum;
        }
        sum = (str[i + j] - '0') + carry;
        str[i + j] = '0' + sum;
    }
    //cout << str << "\n" << str1 << endl << str2 << endl;
    while(str.length() > 1 && str[str.length() - 1] == '0')
    {
        str.erase(str.length() - 1);
    }
    reverse(str.begin(),str.end());
    return str;
}

int main()
{
    int n;

    string factorial[MAX_NUM];

    factorial[0] = "1";
    factorial[1] = "1";
    for(int i = 2;i<MAX_NUM;i++)
    {
        stringstream ss;
        ss << i;
        string newInt;
        ss >> newInt;
        factorial[i] = product(factorial[i-1],newInt);
    }

    while(cin >> n)
    {
        if(n < 0)
            break;

        cout << n << "!\n" << factorial[n] << endl;

    }
    return 0;
}
