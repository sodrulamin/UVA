#include <iostream>
#include <cmath>

#define bigint unsigned long long

using namespace std;

int main()
{
    bigint n;
    while(cin >> n)
    {
        int l = ceil((sqrt (1 + 8 * n) - 1) / 2);
        int s = n - l * (l - 1) / 2;
        int upperValue,lowerValue;
        if(l & 1)
        {
            upperValue = l - s + 1;
            lowerValue = s;
        }
        else
        {
            upperValue = s;
            lowerValue = l - s + 1;
        }
        cout << "TERM " << n << " IS " << upperValue << "/" << lowerValue << endl;
    }
    return 0;
}
