#include <iostream>

using namespace std;

int main()
{
    int t,caseCount = 1;
    unsigned long long n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << "Case " << caseCount++ << ": " ;

        n = n * (n - 1) / 2;

        if(n % 2 == 0)
            cout << n / 2 <<endl;
        else
            cout << n << "/2" << endl;
    }
    return 0;
}
