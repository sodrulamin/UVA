#include <iostream>
#include <vector>

using namespace std;

int price[1010],weight[1010],capacity[100],result[1010][35];

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<1010;i++)
        result[i][0] = 0;
    for(int i=1;i<35;i++)
        result[0][i] = 0;
    //vector<int> resultSet;
    while(t > 0)
    {
        int n;
        cin >> n;
        for(int i=1;i <= n;i++)
        {
            cin >> price[i] >> weight[i];
        }
        int m,maxCapacity = -1;
        cin >> m;
        for(int i=0;i<m;i++)
        {
            cin >> capacity[i];
            if(capacity[i] > maxCapacity)
                maxCapacity = capacity[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=maxCapacity;j++)
            {
                int maxValue = result[i - 1][j];
                int index = j - weight[i];
                if(index >= 0)
                {
                    if(result[i - 1][index] + price[i] > maxValue)
                    {
                        maxValue = result[i - 1][index] + price[i];
                    }
                }

                result[i][j] = maxValue;
                //cout << result[i][j] <<  " ";
            }
            //cout << endl;
        }


        int sum = 0;
        for(int i=0;i<m;i++)
        {
            sum += result[n][capacity[i]];
        }
        cout << sum << endl;
        //resultSet.push_back(sum);
        t--;
    }

//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
