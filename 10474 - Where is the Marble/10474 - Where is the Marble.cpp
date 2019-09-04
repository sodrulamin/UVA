#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,q;
    int numbers[10000];
    int caseCount = 1;
    while(cin >> n >> q)
    {
        if(n == 0 && q == 0)
            break;
        for(int i=0;i<n;i++)
        {
            cin >> numbers[i];
        }
        sort(numbers, numbers + n);
        cout << "CASE# " << caseCount << ":\n";
        for(int i=0;i<q;i++)
        {
            int query;
            cin >> query;
            int result = -1;
            for(int i=0;i<n;i++)
            {
                if(query == numbers[i]){
                    result = (i + 1);
                    break;
                }
                else if(query < numbers[i])
                    break;
            }
            if(result == -1)
            {
                cout << query << " not found\n";
            }
            else
            {
                cout << query << " found at " << result << endl;
            }
        }
        caseCount++;
    }
    return 0;
}
