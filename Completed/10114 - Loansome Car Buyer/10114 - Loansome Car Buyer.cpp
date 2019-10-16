#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int loanMonth,depreMonth;
    double downPament,totalLoan;
    //vector<int> resultSet;
    while(cin >> loanMonth >> downPament >> totalLoan >> depreMonth)
    {

        int totalMonthNeeded = 0;
        if(loanMonth < 0)
            break;
        double depreciations[110];
        for(int i=0;i<110;i++)
            depreciations[i] = -1;
        for(int i=0;i<depreMonth;i++)
        {
            int a;
            double b;
            cin >> a >> b;
            depreciations[a] = b;
        }
        double monthlyPayment = totalLoan / loanMonth;
        double worth = downPament + totalLoan;
        double currentDepriciation = depreciations[0];
        worth = (1 - currentDepriciation) * worth;
        //cout << "Month: " << totalMonthNeeded << " loan: " << totalLoan << " worth: " << worth << " depreciation: " << currentDepriciation << endl;
        while(totalLoan > worth)
        {
            totalMonthNeeded++;
            if(depreciations[totalMonthNeeded] > -1)
            {
                currentDepriciation = depreciations[totalMonthNeeded];
            }
            worth = (1 - currentDepriciation) * worth;
            totalLoan -= monthlyPayment;
            //cout << "Month: " << totalMonthNeeded << " loan: " << totalLoan << " worth: " << worth << " depreciation: " << currentDepriciation << endl;
        }
        //resultSet.push_back(totalMonthNeeded);
        if(totalMonthNeeded != 1)
        {
            cout << totalMonthNeeded << " months\n";
        }
        else
        {
            cout << totalMonthNeeded << " month\n";
        }
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i] != 1)
//        {
//            cout << resultSet[i] << " months\n";
//        }
//        else
//        {
//            cout << resultSet[i] << " month\n";
//        }
//    }

    return 0;
}
