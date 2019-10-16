#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>

using namespace std;

vector<string> resultSet;

char charList[] = {
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9'
};

void producePermutation(string str)
{
    vector<int> characters;
    for(int i=0;i<str.length();i++)
    {
        int n;
        if(isalpha(str[i]))
        {
            n = str[i] - 'a';
        }
        else
        {
            n = (str[i] - '0') + 26;
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
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        string str;
        cin >> str;
        producePermutation(str);
        cout << endl;

    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
