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

int main()
{
    int n1 = 2, n2 = 1000;
    for(int i = n1; i <= n2; i++)
    {
        if(isPrime(i))
        {
            cout << i << ",";
        }

    }
    cout << endl;
    return 0;
}
