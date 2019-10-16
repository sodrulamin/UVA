#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>

using namespace std;

vector<string> resultSet;

char charList[] = {
    'A','a',
    'B','b',
    'C','c',
    'D','d',
    'E','e',
    'F','f',
    'G','g',
    'H','h',
    'I','i',
    'J','j',
    'K','k',
    'L','l',
    'M','m',
    'N','n',
    'O','o',
    'P','p',
    'Q','q',
    'R','r',
    'S','s',
    'T','t',
    'U','u',
    'V','v',
    'W','w',
    'X','x',
    'Y','y',
    'Z','z'
};

void produceAnanagrams(string str)
{
    vector<int> characters;
    for(int i=0;i<str.length();i++)
    {
        int n;
        if(isupper(str[i]))
        {
            n = (str[i] - 'A') * 2;
        }
        else
        {
            n = (str[i] - 'a') * 2 + 1;
        }
        characters.push_back(n);
    }
    //cout << "Size: " << characters.size() << endl;
    sort(characters.begin(), characters.begin() + characters.size());
    set<string> permutedList;
    do {
        string s = "";
        for(int i=0;i<characters.size();i++)
            //cout << characters[i];
        {
            s += charList[characters[i]];
        }
        if(permutedList.find(s) == permutedList.end()){
            permutedList.insert(s);
            cout << s << endl;
        }
    } while ( std::next_permutation(characters.begin(),characters.begin() + characters.size()) );

    //stack<string> reverseSet;
//    for(const string& x: permutedList)
//    {
//        cout << x << endl;
//        //reverseSet.push(x);
//    }
//    while(!reverseSet.empty())
//    {
//        //cout << reverseSet.top() << endl;
//        resultSet.push_back(reverseSet.top());
//        reverseSet.pop();
//    }
}

int main()
{
    int t;
    cin >> t;
    while(t > 0)
    {
        string str;
        cin >> str;

        produceAnanagrams(str);
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
