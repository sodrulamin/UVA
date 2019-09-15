#include <iostream>
#include <set>
#include <string>

using namespace std;


int main()
{
    set<string> wordList;
    string str;
    set<string>::iterator it;
    while(cin >> str){
        string lowerString = "";
        for(int i=0;i<str.length();i++)
        {
            if(!isalpha(str[i]))
            {
                if(lowerString.length() > 0)
                {
                    it = wordList.find(lowerString);
                    if(it == wordList.end())
                    {
                        wordList.insert(lowerString);
                    }
                }
                lowerString = "";
                continue;
            }
            lowerString += tolower(str[i]);
        }
        if(lowerString.length() > 0)
        {
            it = wordList.find(lowerString);
            if(it == wordList.end())
            {
                wordList.insert(lowerString);
            }
        }
    }
    it = wordList.begin();
    while(it != wordList.end())
    {
        cout << *it << endl;
        ++it;
    }
    return 0;
}
