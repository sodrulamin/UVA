#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1,str2;
    while(getline(cin,str1))
    {
        getline(cin,str2);
        if(str1.length() > 0 && str2.length() > 0)
        {
            int presence1[26] = {0};
            int presence2[26] = {0};
            for(int i=0;i<str1.length();i++)
            {
                presence1[str1[i] - 'a']++;
            }
            for(int i=0;i<str2.length();i++)
            {
                presence2[str2[i] - 'a']++;
            }
            for(int i=0;i<26;i++)
            {
                int a = min(presence1[i],presence2[i]);
                for(int j=0;j<a;j++)
                {
                    char ch = 'a' + i;
                    cout << ch;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
