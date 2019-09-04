#include <iostream>

using namespace std;


int main(){
    int roundCount;
    while(cin >> roundCount){
        if(roundCount == -1){
            break;
        }
        string word,guess;
        cin >> word >> guess;
        int charArray[26];
        for(int i=0;i<26;i++){
            charArray[i] = 0;
        }
        int totalUniqueCharCount = 0;
        for(int i=0;i<word.length();i++){
            int index = word[i] - 'a';
            if(charArray[index] == 0){
                charArray[index] = 1;
                totalUniqueCharCount++;
            }
        }
        /*cout << "total unique char: " << totalUniqueCharCount << endl;
        for(int i=0;i<26;i++){
            cout << i << "-" << charArray[i] << " ";
        }
        cout << endl;*/
        int wrongCount = 0,rightCount = 0;
        int result = -1;
        for(int i=0;i<guess.length();i++){
            int index = guess[i] - 'a';
            if(charArray[index] == 1){
                rightCount++;
                charArray[index] = 2;
            }else if(charArray[index] == 0){
                wrongCount++;
                charArray[index] = -1;
            }
            //cout << "Ch: " << guess[i] << " index: " << index << " right: " << rightCount << " wrong: " << wrongCount << endl;
            if(rightCount >= totalUniqueCharCount){
                ///you win
                result = 1;
                break;
            }else if(wrongCount >= 7){
                ///you lose
                result = 0;
                break;
            }
        }
        cout << "Round " << roundCount << endl;
        if(result == -1){
            cout << "You chickened out.\n";
        }else if(result == 0){
            cout << "You lose.\n";
        }else{
            cout << "You win.\n";
        }
    }
}
