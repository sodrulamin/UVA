#include <iostream>
#include <string>

using namespace std;

/*
1 represents B, F, P, or V
2 represents C, G, J, K, Q, S, X, or Z
3 represents D or T
4 represents L
5 represents M or N
6 represents R
The letters A, E, I, O, U, H, W, and Y
*/
int value[] = {
    0,1,2,3,0,1,2,0,0,2,2,4,
    5,5,0,1,2,6,2,3,0,1,0,2,
    0,2
};
char numberToChar[] = {
    '0','1','2','3','4','5','6','7','8','9'
};

int main()
{
    string str;
    while(cin >> str){
        string result = "";
        int currentInt = -1,index;
        for(int i=0;i<str.length();i++){
            index = str[i] - 'A';
            if(currentInt == value[index])
                continue;
            else if(value[index] == 0){
                currentInt = 0;
                continue;
            }
            currentInt = value[index];
            result += numberToChar[currentInt];

        }
        cout << result << endl;
    }
    return 0;
}
