#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string command;
    int t;
    cin >> t;
    //vector<int> resultSet;
    while(t > 0)
    {
        int n,a;
        cin >> n;
        int currentPosition = 0;
        vector<int> commandSequence;
        commandSequence.push_back(0);
        for(int i=0;i<n;i++)
        {
            cin >> command;
            if(command == "LEFT")
            {
                commandSequence.push_back(-1);
                currentPosition--;
            }
            else if(command == "RIGHT")
            {
                commandSequence.push_back(1);
                currentPosition++;
            }
            else
            {
                cin >> command >> a;
                a = commandSequence[a];
                currentPosition += a;
                commandSequence.push_back(a);
            }
        }
        cout << currentPosition << endl;
        //resultSet.push_back(currentPosition);
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
