#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <queue>

using namespace std;

int getInt(string str,int index,int *num)
{
    int a = 0;
    while(str[index] < '0' || str[index] > '9')
        index++;
    while(str[index] >= '0' && str[index] <= '9')
        a = a * 10 + str[index++] - '0';
    *num = a;
    return index;
}

int main()
{
    int n;
    int dayCount = 1;
//    vector<int> startTimeSet;
//    vector<int> resultSet;
    while(cin >> n)
    {
//        if(n == -1)
//            break;
        string str;
        bool taskSchedule[481] = {false};
        for(int i=0;i<n;i++)
        {
            getline(cin,str);
            if(str.length() == 0)
            {
                i--;
                continue;
            }
            int a,b,c,d,startTime,endTime;
//            sscanf("%d:%d %d:%d",&a,&b,&c,&d);
            int index = 0;
            index = getInt(str,index,&a);
            index = getInt(str,index,&b);
            index = getInt(str,index,&c);
            index = getInt(str,index,&d);

            startTime = (a - 10) * 60 + b;
            endTime = (c - 10) * 60 + d;
            for(int i=startTime;i<endTime;i++)
                taskSchedule[i] = true;

            //cout << "Parsed: " << a << ":" << b << " " << c << ":" << d << endl;
        }
        taskSchedule[480] = true;
        int maxNap = 0,napTime = 0,maxNapStart = 0,napStart = 0;
        int startCount = 0;
        bool napEnd = false;
        for(int i=0;i<=480;i++)
        {
            if(!taskSchedule[i]){
                napTime++;
                if(!napEnd){
                    napEnd = true;
                    napStart = i;
                }

            }
            else if(napEnd)
            {
                napEnd = false;
                if(napTime > maxNap){
                    maxNap = napTime;
                    maxNapStart = napStart;
                }
                napTime = 0;
            }
        }
//        startTimeSet.push_back(maxNapStart);
//        resultSet.push_back(maxNap);
        int hour = maxNap / 60;
        int minute = maxNap % 60;
        int napStartHour = maxNapStart / 60 + 10;
        int napStartMinute = maxNapStart % 60;
        cout << "Day #" << dayCount++ << ": the longest nap starts at " << napStartHour << ":";
        if(napStartMinute < 10)
            cout << "0";
        cout << napStartMinute << " and will last for ";
        if(hour > 0)
        {
            cout << hour << " hours and ";
        }
        cout << minute << " minutes." << endl;
    }
//    dayCount = 1;
//    for(int i=0;i<resultSet.size();i++)
//    {
//        int hour = resultSet[i] / 60;
//        int minute = resultSet[i] % 60;
//        int napStartHour = startTimeSet[i] / 60 + 10;
//        int napStartMinute = startTimeSet[i] % 60;
//        cout << "Day #" << dayCount++ << ": the longest nap starts at " << napStartHour << ":";
//        if(napStartMinute < 10)
//            cout << "0";
//        cout << napStartMinute << " and will last for ";
//        if(hour > 0)
//        {
//            cout << hour << " hours and ";
//        }
//        cout << minute << " minutes." << endl;
//    }

    return 0;
}
