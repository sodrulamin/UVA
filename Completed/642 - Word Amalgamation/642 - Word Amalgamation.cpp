#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string getKey(string str)
{
    int frequencey[26] = {0};

    for(int i=0;i<str.length();i++)
        frequencey[str[i] - 'a']++;

    string result = "";
    for(int i=0;i<26;i++)
    {
        char ch = 'a' + i;
        for(int j=0;j<frequencey[i];j++)
        {

            result += ch;
        }
    }

    return result;
}

int main()
{
    //vector<string> resultSet;
    map<string, vector<string> > dictionary;
    map<string, vector<string> >::iterator it;
    string dictionaryWord;
    while(cin >> dictionaryWord)
    {
        if(dictionaryWord == "XXXXXX")
            break;
        string key = getKey(dictionaryWord);
        it = dictionary.find(key);
        if(it == dictionary.end())
        {
            vector<string> v;
            v.push_back(dictionaryWord);
            dictionary.insert(make_pair(key,v));
        }
        else
        {
            it->second.push_back(dictionaryWord);
        }
    }

    for(it = dictionary.begin();it != dictionary.end(); it++)
    {
        vector<string> v = it->second;
        sort(v.begin(),v.end());
        it->second = v;
//        cout << "Key: " << it->first << " value: ";
//        for(const string& s: v)
//            cout << s << " ";
//        cout << endl;
    }

    string inputString;
    while(cin >> inputString)
    {
        if(inputString == "XXXXXX")
            break;
        string key = getKey(inputString);
        it = dictionary.find(key);
        if(it == dictionary.end())
        {
            cout << "NOT A VALID WORD" << endl;
            //resultSet.push_back("NOT A VALID WORD");
        }
        else
        {
            vector<string> v = it->second;
            for(const string& s: v){
                cout << s << endl;
                //resultSet.push_back(s);
            }
        }
        cout << "******" << endl;
        //resultSet.push_back("******");
    }

//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }

    return 0;
}
