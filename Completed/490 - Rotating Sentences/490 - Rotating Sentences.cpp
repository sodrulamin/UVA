#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

char output[110][110] = {' '};

bool isLegal(char ch)
{
    if(ch == '\n' || ch == ' ')
        return true;
    else if(isalpha(ch) || isdigit(ch) || ispunct(ch))
        return true;
    return false;
}

int main()
{
    string str;
    int lineCount = 0;
    int maxLen = 0;
    while(getline(cin,str))
    {
        /*if(str.length() == 0)
            break;*/
        for(int i=0;i<str.length();i++)
        {
            output[i][lineCount] = str[i];
        }
        if(str.length() > maxLen)
            maxLen = str.length();
        lineCount++;
    }
    for(int i=0;i<maxLen;i++)
    {
        for(int j=lineCount - 1;j >= 0;j--)
        {
            cout << output[i][j];
        }
        cout << endl;
    }
    return 0;
}
