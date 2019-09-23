#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    //vector<double> resultSet;
    while(cin >> n)
    {
        if(n == 0)
            break;
        vector<double> costs;
        double c;
        double sum = 0;
        for(int i=0;i<n;i++)
        {
            cin >> c;
            sum = sum + c;
            costs.push_back(c);
        }
        double avg = sum / n;
        double paona = 0, dena = 0;
        for(int i=0;i<n;i++)
        {
            if(costs[i] < avg)
            {
                dena += (long) ((avg - costs[i]) * 100.0) / 100.0;
            }
            else
            {
                paona += (long) ((costs[i] - avg) * 100.0) / 100.0;
            }

        }
        if(paona > dena)
        {
            cout << "$" << std::fixed << setprecision(2) << paona << endl;
            //resultSet.push_back(paona);
        }
        else
        {
            cout << "$" << std::fixed << setprecision(2) << dena << endl;
            //resultSet.push_back(dena);
        }


    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "$" << std::fixed << setprecision(2) << resultSet[i] << endl;
//    }
    return 0;
}
