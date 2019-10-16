#include <string>
#include <iostream>

using namespace std;

int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int daysInMonths[] = {31,59,90,120,151,181,212,243,273,304,334,365};
string days[] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m, d, dayCount = 0;
        cin >> m >> d;
        dayCount = d - 1;
        if(m > 1)
        {
            dayCount += daysInMonths[m - 2];
        }
//        for(int i=0; i < m - 1;i++)
//        {
//            dayCount += months[i];
//        }
        dayCount %= 7;
        cout << days[dayCount] << endl;
    }

    return 0;
}
