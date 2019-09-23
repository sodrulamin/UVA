#include <iostream>

using namespace std;

int main()
{
    int n,t;
    cin >> t;
    while(t > 0)
    {
        cin >> n;
        int occurance[10] = {0};
        for(int i=1;i<=n;i++)
        {
            int m = i;
            while(m > 0)
            {
                int mod = m % 10;
                m = m / 10;
                occurance[mod]++;
            }
        }

        for(int i=0;i<10;i++)
        {
            if(i > 0)
                cout << " ";
            cout << occurance[i];
        }
        cout << endl;
        t--;
    }
    return 0;
}
