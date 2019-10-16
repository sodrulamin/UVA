#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

bool isPalindrom(string str)
{
    int startIndex = 0, endIndex = str.length() - 1;
    while(startIndex < endIndex)
    {
        if(str[startIndex] != str[endIndex])
            return false;
        startIndex++;
        endIndex--;
    }
    return true;
}
int countPalindromes(string str)
{
    unordered_set<string> subSet;
    for(int i=1;i<=str.length();i++)
    {
        for(int j=0;j<=str.length() - i;j++)
        {
            string s = str.substr(j,i);
            subSet.insert(s);
            //cout << "Index: " << j << " len: " << i << " str: " << s << endl;
        }
    }
    //cout << "subSet contains:\n";
    int palindromCount = 0;
    for (const string& x: subSet){
        //cout << x;
        if(x.length() == 1 || isPalindrom(x))
        {
            palindromCount++;
            //cout << " yes.";
        }
//        else
//        {
//            //cout << " no.";
//        }
        //cout << endl;
    }
    return palindromCount;
}

int main()
{
//    vector<string> stringSet;
//    vector<int> resultSet;
    string str;
    while(cin >> str)
    {
        if(str == "-1")
            break;
        int n = countPalindromes(str);
        cout << "The string '" << str << "' contains " << n << " palindromes." << endl;
//        stringSet.push_back(str);
//        resultSet.push_back(n);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "The string '" << stringSet[i] << "' contains " << resultSet[i] << " palindromes." << endl;
//    }

    return 0;
}
