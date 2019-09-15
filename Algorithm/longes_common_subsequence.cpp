#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int lcs[1010][1010];

int main()
{
    //int lcs[1010][1010] = {0};
    string str1 = "Hello";
    string str2 = "Heinllo";
    while(getline(cin,str1))
    {
        getline(cin,str2);
        //cout << str1 << endl << str2 << endl;
        //int lcs[1000][1000];
        for(int i=0;i<=str1.length();i++)
            lcs[0][i] = 0;
        for(int i=0;i<=str2.length();i++)
            lcs[i][0] = 0;
        int maxLen = 0;
        for(int i=0;i<str1.length();i++)
        {
            for(int j=0;j<str2.length();j++)
            {
                if(str1[i] == str2[j])
                {
                    lcs[j + 1][i + 1] = 1 + lcs[j][i];
                    if(lcs[j + 1][i + 1] > maxLen)
                    {
                        maxLen = lcs[j + 1][i + 1];
                    }
                }
                else
                {
                    lcs[j + 1][i + 1] = max(lcs[j + 1][i],lcs[j][i + 1]);
                }
            }
        }
        cout << maxLen << endl;
    }

    return 0;
}

