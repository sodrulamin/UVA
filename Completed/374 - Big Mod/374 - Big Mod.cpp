#include <iostream>

using namespace std;

int bigMod(int b,int p,int m)
{
    int mod = 1;
    if(p == 1)
        return b % m;
    else if(p == 2)
    {
        mod = b % m;
        mod = mod * mod;
        return mod % m;
    }


    if(p % 2 == 1)
        mod = b % m;
    int result = bigMod(b,p/2,m);
    mod = ((mod * result) % m) * result;

    result = mod % m;
    //cout << "B: " << b << " P: " << p << " M: " << m << " res: " << result << endl;
    return result;
}

int main()
{
    int b,p;
    int m;
    while(cin >> b >> p >> m)
    {
        cout << bigMod(b,p,m) << endl;
    }
    return 0;
}
