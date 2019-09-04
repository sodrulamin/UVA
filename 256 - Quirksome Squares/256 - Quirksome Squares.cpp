#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool isInRange(int mulSum,int digitCount)
{
    for(int i=0;i<digitCount;i++)
    {
        mulSum = mulSum / 10;
        if(mulSum == 0)
            return true;
    }
    return false;
}

string getQuirkSome(int mulSum,int digitCount)
{
    string result = "";
    int halfDigit = digitCount / 2,mul = mulSum;
    int rightHalf = 0, leftHalf = 0,multiplier = 1,digit;
    //cout <<"Mul: " << mulSum << " halfDigit: " << halfDigit<< " Right: ";
    for(int i=0;i<halfDigit;i++)
    {
        digit = (mulSum % 10);
        rightHalf = rightHalf + (digit * multiplier);
        mulSum = mulSum / 10;
        multiplier *= 10;
        char ch = '0' + digit;
        result = ch + result;
        //cout << ch;
    }
    //cout << " Left: ";
    multiplier = 1;
    for(int i=0;i<halfDigit;i++)
    {
        digit = (mulSum % 10);
        leftHalf += (digit * multiplier);
        mulSum /= 10;
        multiplier *= 10;
        char ch = '0' + digit;
        result = ch + result;
        //cout << ch;
    }
    //cout << endl;

    //cout << "mul: " << mul << " left: " << leftHalf << " right: " << rightHalf << endl;
    leftHalf += rightHalf;
    if(mul == (leftHalf * leftHalf))
        return result;

    return "";
}

int main()
{
    int n;
    while(cin >> n)
    {
        int mulSum = 0,index = 0;
        string str;
        while(isInRange(mulSum,n))
        {

            str = getQuirkSome(mulSum,n);
            if(str != "")
                cout << str << endl;
            //cout << "mul: " << mulSum << " index: " << index << " str: " << str << endl;
            index++;
            mulSum = index * index;
        }
    }
    return 0;
}
