#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m,n;
//    vector<int> rowSet;
//    vector<int> colSet;
//    vector<int> resultSet;
    while(cin >> m >> n)
    {
        if(m == 0 && n == 0)
            break;
        int result = m * n;
        if(m < 3 || n < 3)
        {
            if(m > 0 && n > 0)
            {
                int maxValue = m,minValue = n;
                if(maxValue < minValue)
                {
                    maxValue = n;
                    minValue = m;
                }
                if(minValue == 1)
                {
                    result = maxValue;
                }
                else if(maxValue % 4 == 0)
                {
                    result = maxValue;
                }
                else if(m == 2 && n == 2)
                {
                    result = 4;
                }
                else
                {
                    result = (maxValue / 2 + 1) * 2;
                }

            }
            else
                result = 0;
        }
        else if(result % 2 == 0)
        {
            result = result / 2;
        }
        else
        {
            result = result / 2 + 1;
        }
        cout << result << " knights may be placed on a " << m << " row " << n << " column board." << endl;
//        rowSet.push_back(m);
//        colSet.push_back(n);
//        resultSet.push_back(result);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << " knights may be placed on a " << rowSet[i] << " row " << colSet[i] << " column board." << endl;
//    }
    return 0;
}
