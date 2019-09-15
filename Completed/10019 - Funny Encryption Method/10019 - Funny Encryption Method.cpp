#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n > 0)
    {
        int m,num;
        cin >> num;
        m = num;
        int a = 0;
        while(m > 0)
        {
            if(m % 2 == 1)
                a++;
            m = m/2;
        }
        m = 0;
        while(num > 0)
        {
            m = m * 16 + (num % 10);
            num = num / 10;
        }
        int b = 0;
        while(m > 0)
        {
            if(m % 2 == 1)
                b++;
            m = m/2;
        }
        cout << a << " " << b << endl;

        n--;
    }
    return 0;
}
