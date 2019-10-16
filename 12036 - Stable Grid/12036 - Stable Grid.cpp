#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t,n,caseCount = 1;
    cin >> t;
    //vector<bool> resultSet;
    while(t--)
    {
        int a,countArray[101] = {0};
        bool stable = true;

        cin >> n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> a;
                countArray[a]++;
                if(countArray[a] > n)
                    stable = false;
            }
        }

        cout << "Case " << caseCount++ << ": ";
        if(stable)
            cout << "yes\n";
        else
            cout << "no\n";
        //resultSet.push_back(stable);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "Case " << (i + 1) << ": ";
//        if(resultSet[i])
//            cout << "yes\n";
//        else
//            cout << "no\n";
//    }
    return 0;
}
