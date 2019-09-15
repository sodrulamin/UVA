#include <iostream>
#include <string>

using namespace std;

char charMap[] = {
    'A','B','C','D',
    'E','F','G','H',
    'I','J','K','L',
    'M','N','O','P',
    'Q','R','S','T',
    'U','V','W','X',
    'Y','Z',
    'a','b','c','d',
    'e','f','g','h',
    'i','j','k','l',
    'm','n','o','p',
    'q','r','s','t',
    'u','v','w','x',
    'y','z'
};

int main()
{
    string str = "Hello World";
    while(getline(cin,str))
    {
        int frequency[52] = {0};
        int maxFrequency = 0;
        for(int i=0;i<str.length();i++)
        {
            if(isalpha(str[i]))
            {
                int index;
                if(isupper(str[i]))
                {
                    index = str[i] - 'A';
                }
                else
                {
                    index = str[i] - 'a' + 26;
                }
                frequency[index]++;
                if(frequency[index] > maxFrequency)
                    maxFrequency = frequency[index];
            }
        }
        if(maxFrequency > 0)
        {
            for(int i=0;i<52;i++)
            {
                if(frequency[i] == maxFrequency)
                {
                    cout << charMap[i];
                }
            }
            cout << " " << maxFrequency << endl;
        }

    }
    return 0;
}
