#include <iostream>
#include <algorithm>
#include <string>

#define ArraySize 100

using namespace std;

int id[ArraySize];

int main(){
    string inputCode;

    while(cin >> inputCode){
        if(inputCode == "#"){
            break;
        }

        for(int i=0;i<inputCode.length();i++){
            int index = inputCode[i] - 'a';
            id[i] = index;
        }

        if(next_permutation(id,id + inputCode.length())){
            for(int i=0;i<inputCode.length();i++){
                char ch = 'a' + id[i];
                cout << ch;
            }
            cout << endl;
        }else {
            cout << "No Successor\n";
        }
    }

    return 0;
}
