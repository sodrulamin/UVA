#include <iostream>

#define bigint unsigned long long

using namespace std;

int main()
{
    bigint n;
    while(cin >> n)
    {
        bigint sum = 0;
        //bigint l = (n + 1) / 2;
        bigint lastOdd = (n + 1) * (n + 1) / 2 - 1;
        sum = lastOdd * 3 - 6;

        cout << sum << endl;
    }
    return 0;
}
