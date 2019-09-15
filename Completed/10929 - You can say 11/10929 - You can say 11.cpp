#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int longRemainder(string str,int n)
{
    int residue = 0,newDigit,number;
    for(int i=0;i<str.length();i++)
    {
        newDigit = str[i] - '0';
        number = residue * 10 + newDigit;
        residue = number % n;
    }
    return residue;
}

int main()
{
    string number;
    //vector<string> numberList;
    //vector<bool> resultList;
    while(cin >> number)
    {
        if(number == "0")
            break;
        //numberList.push_back(number);
        if(longRemainder(number,11) == 0)
        {
            cout << number << " is a multiple of 11." << endl;
            //resultList.push_back(true);
        }
        else
        {
            cout << number << " is not a multiple of 11." << endl;
            //resultList.push_back(false);
        }
    }
    /*for(int i=0;i<numberList.size();i++)
    {
        cout << numberList[i];
        if(resultList[i])
            cout << " is a multiple of 11." << endl;
        else
            cout << " is not a multiple of 11." << endl;
    }*/
    return 0;
}
