#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n > 0){
        string str;
        cin >> str;
        int len = str.length();

        if(str == "1" || str == "4" || (str == "78"))
            cout << "+\n";
        else if(str[len - 2] == '3' && str[len - 1] == '5')
            cout << "-\n";
        else if(str[0] == '9' && str[len - 1] == '4')
            cout << "*\n";
        else
            cout << "?\n";

        n--;
    }
    return 0;
}
