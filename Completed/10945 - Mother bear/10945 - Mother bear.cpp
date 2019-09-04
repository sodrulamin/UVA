#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main(){
    string done = "DONE";
    string str;
    getline(cin,str);
    while(str.compare(done) != 0){
        //if(str.length() > 0)

        if(isPalindrome(str)){
            cout << "You won't be eaten!\n";
        }else {
            cout << "Uh oh..\n";
        }

        getline(cin,str);
    }
    return 1;
}

bool isPalindrome(string str){
    int startIndex = 0, endIndex = str.length() - 1;
    for(int i=0;i<=endIndex;i++){
        if(isupper(str[i]))
            str[i] = tolower(str[i]);
    }
    //cout << str << endl;
    while(startIndex < endIndex){
        while(startIndex < str.length() - 1){
            if(str[startIndex] >= 'a' && str[startIndex] <= 'z')
                break;
            startIndex++;
        }
        while(endIndex >0){
            if(str[endIndex] >= 'a' && str[endIndex] <= 'z')
                break;
            endIndex--;
        }
        if((startIndex < str.length() -1) && (endIndex > 0) && (startIndex < endIndex) && (str[startIndex] != str[endIndex]))
            return false;
        startIndex++;
        endIndex--;
    }

    return true;
}
