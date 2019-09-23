#include <iostream>
#include <vector>
#include <cstdio>

#define MAX_NUM 46350

using namespace std;

vector<int> primeNumbers;

bool isPrime(int n)
{
    int i = 0;
    while(primeNumbers[i] * primeNumbers[i] <= n)
    {
        if(n % primeNumbers[i] == 0)
            return false;
        i++;
    }
    return true;
}


int main()
{
    primeNumbers.push_back(2);
    primeNumbers.push_back(3);
    primeNumbers.push_back(5);
    int n;

    n = 7;
    while(n < MAX_NUM)
    {
        if(isPrime(n))
        {
            primeNumbers.push_back(n);
            //cout << n << endl;
        }
        n += 2;
    }

    while(cin >> n)
    {
        //cout << n << endl;
        if(n == 0)
            break;
        vector<int> factors;
        int num = n;
        if(num < 0)
        {
            factors.push_back(-1);
            num = -1 * num;
        }
        int currentDivider = 0;

        while(currentDivider < primeNumbers.size() && num >= primeNumbers[currentDivider])
        {
            if(num % primeNumbers[currentDivider] != 0)
            {
                currentDivider++;
                continue;
            }
            num = num / primeNumbers[currentDivider];
            factors.push_back(primeNumbers[currentDivider]);
        }
        if(num > 1)
            factors.push_back(num);
        //cout << " = ";
        cout << n << " = ";
        if(factors.size() > 0)
            cout << factors[0];
        for(int i=1;i<factors.size();i++)
        {
            printf(" x %d",factors[i]);
        }
        cout << endl;
    }
    return 0;
}
