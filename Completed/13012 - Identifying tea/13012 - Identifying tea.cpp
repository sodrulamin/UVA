#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int a,result = 0;
        for(int i=0;i<5;i++)
        {
            cin >> a;
            if(a == n)
                result++;
        }
        cout << result << endl;
    }
    return 0;
}
