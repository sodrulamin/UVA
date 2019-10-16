#include <iostream>
#include <string>
#include <vector>

#define C 12.01
#define H 1.008
#define O 16.00
#define N 14.01

using namespace std;

int main()
{
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(3);
    int t;
    cin >> t;
    //vector<double> resultSet;
    while(t)
    {
        string formula;
        cin >> formula;
        double mass = 0;

        int index = 0;
        while(index < formula.length())
        {
            double lastMass = 0;
            switch(formula[index++])
            {
                case 'C':
                    lastMass = C;
                    break;
                case 'H':
                    lastMass = H;
                    break;
                case 'O':
                    lastMass = O;
                    break;
                case 'N':
                    lastMass = N;
                    break;
            }
            int digit = 0;
            while(index < formula.length() && isdigit(formula[index]))
            {
                digit = digit * 10 + (formula[index] - '0');
                index++;
            }
            if(digit == 0)
                mass += lastMass;
            else
                mass = mass + lastMass * digit;
        }

        cout << mass << endl;
        //resultSet.push_back(mass);

        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
