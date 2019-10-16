#include <iostream>

using namespace std;

int findDivisiorsSum(int n)
{
    int sum = 1;
    int divisor = 2;
    int divident = n / 2;
    while(divisor < divident)
    {
        if(n % divisor == 0)
            sum += (divisor + divident);
        divisor++;
        divident = n / divisor;
    }
    if(n % divisor == 0 && divisor == divident)
        sum += divisor;
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while(t > 0)
    {
        int n;
        cin >> n;
        int sum = findDivisiorsSum(n);
        if(sum > n)
        {
            cout << "abundant" << endl;
        }
        else if(sum == n)
        {
            cout << "perfect" << endl;
        }
        else
        {
            cout << "deficient" << endl;
        }
        t--;
    }
    return 0;
}
