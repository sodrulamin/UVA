#include <iostream>
#include <vector>

using namespace std;

void printChar(char ch,int s){
    for(int i=0;i<s;i++){
        cout << ch;
    }
}

int main()
{
    int s;
    string str;
    while(cin >> s >> str){
        if(s == 0 && str == "0")
            break;

        for(int i=0;i<str.length();i++){
            printChar(' ',1);
            switch(str[i]){
                case '0':
                case '2':
                case '3':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    printChar('-',s);
                    break;
                default:
                    printChar(' ',s);
                    break;
            }
            printChar(' ',2);
            //cout << "  ";
        }
        cout << "\n";
        for(int i=0;i<s;i++){
            for(int j=0;j<str.length();j++){
                switch(str[j]){
                case '0':
                case '4':
                case '8':
                case '9':
                    printChar('|',1);
                    printChar(' ',s);
                    printChar('|',1);
                    printChar(' ',1);
                    break;
                case '5':
                case '6':
                    printChar('|',1);
                    printChar(' ',s + 2);
                    break;
                case '1':
                case '2':
                case '3':
                case '7':
                    printChar(' ',s + 1);
                    printChar('|',1);
                    printChar(' ',1);
                    break;

                }
            }
            cout << "\n";
        }
        for(int i=0;i<str.length();i++){
            printChar(' ',1);
            switch(str[i]){
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '8':
            case '9':
                printChar('-',s);
                break;
            default:
                printChar(' ',s);
                break;
            }
            printChar(' ',2);
        }
        cout << "\n";
        for(int i=0;i<s;i++){
            for(int j=0;j<str.length();j++){
                switch(str[j]){
                case '0':
                case '6':
                case '8':
                    printChar('|',1);
                    printChar(' ',s);
                    printChar('|',1);
                    printChar(' ',1);
                    break;
                case '2':
                    printChar('|',1);
                    printChar(' ',s + 2);
                    break;
                case '1':
                case '3':
                case '4':
                case '5':
                case '7':
                case '9':
                    printChar(' ',s + 1);
                    printChar('|',1);
                    printChar(' ',1);
                    break;

                }
            }
            cout << "\n";
        }
        for(int i=0;i<str.length();i++){
            printChar(' ',1);
            switch(str[i]){
            case '0':
            case '2':
            case '3':
            case '5':
            case '6':
            case '8':
            case '9':
                printChar('-',s);
                break;
            default:
                printChar(' ',s);
                break;
            }
            printChar(' ',2);
        }
        cout << "\n";
    }
    return 0;
}
