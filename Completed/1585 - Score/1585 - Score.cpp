#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    //vector<int> resultSet;
    while(t > 0)
    {
        string str;
        cin >> str;
        int score = 0,count = 0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == 'O')
            {
                count++;
            }
            else
            {
                count = 0;
            }
            score += count;
        }
        cout << score << endl;
        //resultSet.push_back(score);
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
