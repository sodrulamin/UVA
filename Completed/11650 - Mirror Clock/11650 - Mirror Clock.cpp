#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    //vector<string> resultSet;
    while(t > 0)
    {
        string time;
        cin >> time;
        int hour = 0,minute = 0;
        hour = (time[0] - '0') * 10 + (time[1] - '0');
        minute = (time[3] - '0') * 10 + (time[4] - '0');
        hour = 12 - hour;
        minute = 60 - minute;
        if(minute < 60)
            hour--;
        else
            minute = 0;
        if(hour <= 0)
            hour += 12;
        time[0] = '0' + (hour / 10);
        time[1] = '0' + (hour % 10);
        time[3] = '0' + (minute / 10);
        time[4] = '0' + (minute % 10);
        cout << time << endl;
        //resultSet.push_back(time);
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }

    return 0;
}
