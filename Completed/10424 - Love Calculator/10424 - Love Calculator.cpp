#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

int shrink(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main()
{
    string str1,str2;
    //vector<double> resultSet;
    while(getline(cin,str1))
    {
//        if(str1 == "-1")
//            break;
        getline(cin,str2);
        int num1 = 0,num2 = 0;
        for(int i=0;i<str1.length();i++)
        {
            if(isalpha(str1[i]))
            {
                num1 += (tolower(str1[i]) - 'a' + 1);
            }
        }
        for(int i=0;i<str2.length();i++)
        {
            if(isalpha(str2[i]))
            {
                num2 += (tolower(str2[i]) - 'a' + 1);
            }
        }
        while(num1 > 9)
        {
            num1 = shrink(num1);
        }
        while(num2 > 9)
        {
            num2 = shrink(num2);
        }
        double percentage;
        if(num1 > num2)
        {
            percentage = (double)num2 / num1;
        }
        else
        {
            percentage = (double)num1 / num2;
        }
        percentage *= 100;
        cout << std::fixed << setprecision(2) << percentage << " %" << endl;
        //resultSet.push_back(percentage);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << std::fixed << setprecision(2) << resultSet[i] << " %" << endl;
//    }
    return 0;
}
