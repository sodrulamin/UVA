#include <iostream>
#include <vector>

using namespace std;


bool isLeapYear(int year)
{
    if (year % 400 == 0) return true;
    else if(year % 100 == 0) return false;
    else if(year % 4 == 0) return true;
    else return false;
}


int main()
{
    //vector<int> resultSet;
    int t,caseCount = 1;
    cin >> t;
    while(t > 0)
    {
        int d,m,y,yq;
        cin >> d >> m >> y >> yq;
        int year = y + 1;
        bool leapBirthday = false;
        int birthdayCount = 0;
        if(d == 29 && m == 2)
        {
            while(!isLeapYear(year))
            {
                year++;
            }
            while(year <= yq)
            {
                if(isLeapYear(year))
                {
                    birthdayCount++;
                }
                year += 4;
            }
        }
        else
        {
            birthdayCount = yq - y;
        }
        cout << "Case " << caseCount++ << ": " << birthdayCount << endl;
        //resultSet.push_back(birthdayCount);
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "Case " << (i + 1) << ": " << resultSet[i] << endl;
//    }
    return 0;
}
