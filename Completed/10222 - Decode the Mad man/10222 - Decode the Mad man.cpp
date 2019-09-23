#include <iostream>
#include <string>
#include <vector>

using namespace std;



int main()
{

    string str;
    //vector<string> resultSet;
    while(getline(cin, str))
    {
//        if(str == "-1")
//            break;
        string result = "";
        for(int i=0;i<str.length();i++)
        {
            switch(tolower(str[i]))
            {
            case 'e':
                result += "q";
                break;
            case 'r':
                result += "w";
                break;
            case 't':
                result += "e";
                break;
            case 'y':
                result += "r";
                break;
            case 'u':
                result += "t";
                break;
            case 'i':
                result += "y";
                break;
            case 'o':
                result += "u";
                break;
            case 'p':
                result += "i";
                break;
            case '[':
                result += "o";
                break;
            case ']':
                result += "p";
                break;
            case 'd':
                result += "a";
                break;
            case 'f':
                result += "s";
                break;
            case 'g':
                result += "d";
                break;
            case 'h':
                result += "f";
                break;
            case 'j':
                result += "g";
                break;
            case 'k':
                result += "h";
                break;
            case 'l':
                result += "j";
                break;
            case ';':
                result += "k";
                break;
            case '\'':
                result += "l";
                break;
            case 'c':
                result += "z";
                break;
            case 'v':
                result += "x";
                break;
            case 'b':
                result += "c";
                break;
            case 'n':
                result += "v";
                break;
            case 'm':
                result += "b";
                break;
            case ',':
                result += "n";
                break;
            case '.':
                result += "m";
                break;
            case '/':
                result += ",";
                break;
            default:
                result += str[i];
                break;

            }
        }
        cout << result << endl;
        //resultSet.push_back(result);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }

    return 0;
}
