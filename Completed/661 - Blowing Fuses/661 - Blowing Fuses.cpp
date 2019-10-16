#include <iostream>
//#include <vector>

using namespace std;

bool state[25] = {false};
int capacity[25] = {0};



int main()
{
    int n,m,c;
    int sequence = 1;
    //vector<int> resultSet;
    while(cin >> n >> m >> c)
    {
        if(n == 0 && m == 0 && c == 0)
            break;
        for(int i=0;i<25;i++)
        {
            state[i] = false;
        }
        for(int i=1;i<=n;i++)
            cin >> capacity[i];
        int a;
        int sum = 0,maxSum = -999999;
        for(int i=0;i<m;i++)
        {
            cin >> a;
            state[a] = !state[a];
            if(state[a])
                sum = sum + capacity[a];
            else
                sum = sum - capacity[a];

            if(sum > maxSum)
                maxSum = sum;

            //cout << "Max: " << maxSum << " sum: " << sum << endl;
        }
        cout << "Sequence " << sequence << endl;
        if(maxSum > c)
        {
            cout << "Fuse was blown.\n";
            //resultSet.push_back(-1);
        }
        else
        {
            cout << "Fuse was not blown.\n";
            cout << "Maximal power consumption was " << maxSum << " amperes.\n";
            //resultSet.push_back(maxSum);
        }
        cout << endl;

        sequence++;
    }

//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "Sequence " << (i + 1) << endl;
//        if(resultSet[i] > -1)
//        {
//            cout << "Fuse was not blown.\n";
//            cout << "Maximal power consumption was " << resultSet[i] << " amperes.\n";
//        }
//        else
//        {
//            cout << "Fuse was blown.\n";
//        }
//        cout << endl;
//    }

    return 0;
}
