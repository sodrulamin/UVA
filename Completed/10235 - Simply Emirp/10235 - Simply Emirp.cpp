#include <iostream>

using namespace std;

bool isPrime(int n)
{
    int i = 2;
    while(i * i <= n)
    {
        if(n % i == 0)
            return false;
        i++;
    }
    return true;
}
int reverseInt(int n)
{
    int result = 0;
    while(n > 0)
    {
        int mod = n % 10;
        result = result * 10 + mod;
        n = n / 10;
    }
    return result;
}

int main()
{
    int n;
    while(cin >> n)
    {
//        if(n < 0)
//            break;
        int rev = reverseInt(n);
        if(isPrime(n))
        {
            if(rev != n && isPrime(rev))
            {
                cout << n << " is emirp.\n";
            }
            else
            {
                cout << n << " is prime.\n";
            }
        }
        else
        {
            cout << n << " is not prime.\n";
        }
    }
    return 0;
}
