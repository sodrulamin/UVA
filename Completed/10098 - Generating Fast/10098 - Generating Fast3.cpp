#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        do {
            cout << str << endl;
        } while (next_permutation(str.begin(),str.end()));
        cout << endl;

    }
    return 0;
}
