#include <iostream>
#include <string>
#include <algorithm>

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
    string str1 = "0";
    string str2 = "8888888888888888888888";
    cout << product(str1,str2);
    return 0;
}
