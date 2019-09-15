#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string multiplyLong(int n)
{
    int a,b;
    if(n % 2 == 0){
        a = n / 2;
        b = n + 1;
    }
    else
    {
        a = (n + 1) / 2;
        b = n;
    }
    stringstream ss;
    ss<<a;
    string stra;
    ss>>stra;
    ss.clear();
    ss<<b;
    string strb;
    ss>>strb;
    //cout << stra <<  " " << strb << endl;
    string result = "";
    for(int i=0;i<(stra.length() + strb.length());i++)
        result += "0";
    reverse(stra.begin(),stra.end());
    reverse(strb.begin(),strb.end());
    int carry = 1;
    for(int i=0;i<strb.length();i++)
    {
        int j=0;
        for(;j<stra.size();j++)
        {
            int sum = (strb[i] - '0') * (stra[j] - '0') + (result[i + j] - '0') + carry;
            carry = sum / 10;
            result[i + j] = '0' + (sum % 10);
        }
        result[i + j] = '0' + carry;
        carry = 0;
    }
    while(result.size() > 1 && result[result.size() - 1] == '0')
    {
        result.erase(result.size() - 1);
    }
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n < 0)
            break;
        string cutCount = multiplyLong(n);
        cout << cutCount << endl;

    }
    return 0;
}
