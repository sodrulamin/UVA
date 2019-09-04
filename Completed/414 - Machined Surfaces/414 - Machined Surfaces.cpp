#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int n;

    while(cin >> n)
    {
        if(n == 0)
            break;
        //while(n > 0)
        int spaceCount[15];
        int minSpace = 25,totalSpace = 0;
        string str;
        getline(cin, str);
        for(int j=0;j<n;j++)
        {
            //char str[30];
            getline(cin,str);
            int space = 0;
            for(int i=0;i<25;i++){
                if(str[i] == ' ')
                {
                    space++;
                }
            }
            //cout << str << endl;
            spaceCount[j] = space;
            if(space < minSpace)
            {
                minSpace = space;
            }
        }
        for(int i=0;i<n;i++)
        {
            totalSpace = totalSpace + (spaceCount[i] - minSpace);
        }
        cout << totalSpace << endl;
    }
}
