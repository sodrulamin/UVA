#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define HIGHEST_VALUE 5001

using namespace std;

string add(string str1,string str2)
{
    string result = "";
    reverse(str1.begin(),str1.end());
    reverse(str2.begin(),str2.end());
    int n = str1.length();
    result = str2;
    if(str2.length() < n)
    {
        n = str2.length();
        result = str1;
    }
    //cout << "str1: " << str1 << " str2: " << str2 << " res: " << result << endl;
    int sum,carry = 0;
    int i= 0;
    for(;i<n;i++)
    {

        sum = (str1[i] - '0') + (str2[i] - '0') + carry;
        carry = sum / 10;
        sum = sum % 10;
        result[i] = '0' + sum;
        //cout << i << " " << str1[i] << " " << str2[i] << " " << sum << " " << carry << endl;
    }

    while(carry > 0)
    {
        if(result.length() == i)
        {
            result = result + "0";
        }
        sum = result[i] - '0' + carry;
        //cout << i << " " << sum << " " << carry << " " << result[i];
        carry = sum / 10;
        sum = sum % 10;
        result[i] = '0' + sum;
        i++;
        //cout << " " << result[i] << endl;
    }
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
    int n;
    vector<string> fibonacciFreeze(HIGHEST_VALUE);
    fibonacciFreeze[0] = "0";
    fibonacciFreeze[1] = "1";
    for(int i=2;i<HIGHEST_VALUE;i++)
    {
        fibonacciFreeze[i] = add(fibonacciFreeze[i - 1], fibonacciFreeze[i - 2]);
        //cout << fibonacciFreeze[i - 1] << " + " << fibonacciFreeze[i - 2] << " = " << fibonacciFreeze[i] << endl;
    }
    /*string str1 = "99";
    string str2 = "925";
    cout << str1 << " + " << str2 << " = " << add(str1,str2) << endl;*/

    while(cin >> n)
    {
        cout << "The Fibonacci number for " << n << " is " << fibonacciFreeze[n] << endl;
    }
    return 0;
}
