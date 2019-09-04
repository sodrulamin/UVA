#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>

using namespace std;



struct myString{
    string inputString;
    string lowerString;
    string key;

    myString(string str)
    : inputString(str)
    {
        priority_queue<char> q;
        lowerString = "";
        for(int i=0;i<str.length();i++){
            char ch = tolower(str[i]);
            lowerString += ch;
            q.push(ch);
        }
        key = "";
        while(!q.empty()){
            key += q.top();
            q.pop();
        }
    }
};
struct CompareString {
    bool operator()(myString const& ms1, myString const& ms2)
    {
        string s1 = ms1.inputString;
        string s2 = ms2.inputString;

        bool result = true;
        int minLen = s1.length();
        if(minLen > s2.length())
            minLen = s2.length();

        for(int i=0;i<minLen;i++){
            /*if(!isalpha(s1[i]) || !isalpha(s2[i])){
                if(s1[i] != s2[i]){
                    return s1[i] > s2[i];
                }
            }
            else */if(isupper(s1[i]) && isupper(s2[i])){
                if(s1[i] < s2[i]){
                    return false;
                }else if(s1[i] > s2[i]){
                    return true;
                }
            }else if(isupper(s1[i])){
                return false;
            }else if(isupper(s2[i])){
                return true;
            }else if(s1[i] < s2[i]){
                return false;
            }else if(s1[i] > s2[i]){
                return true;
            }
        }
        return s2.length() > s1.length();
    }
};


int main(){
    string str;
    priority_queue<myString, vector<myString>, CompareString> sortedInput;
    map<string,int> presenceCount;
    while(cin >> str){
        if(str == "#"){
            break;
        }
        myString ms(str);
        sortedInput.push(ms);

        map<string, int>::iterator it = presenceCount.find(ms.key);
        if(it == presenceCount.end()){
            presenceCount.insert(make_pair(ms.key,1));
        }else {
            it->second++;
        }
    }

    while(!sortedInput.empty()){
        myString ms = sortedInput.top();
        map<string, int>::iterator it = presenceCount.find(ms.key);
        if(it->second <= 1)
            cout << ms.inputString << endl;
        sortedInput.pop();
    }

    return 0;
}
