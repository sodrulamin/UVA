#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    string str;
    //vector<int> resultSet;
    int caseCount = 1;
    while(cin >> str)
    {
        if(str == "end")
            break;
        bool present[26] = {false};
        vector<int> top;
        top.push_back(0);
        int stackCount = 1;
        for(int i=str.length() - 1;i >= 0;i--)
        {
            int index = str[i] - 'A';
            bool found = false;
            int j = 0;
            for(;j<top.size();j++)
            {
                if(top[j] <= index)
                {
                    found = true;
                    break;
                }
            }
            if(found)
                top[j] = index;
            else
            {
                top.push_back(index);
                stackCount++;
            }
        }
        cout << "Case " << caseCount << ": " << stackCount << endl;
        //resultSet.push_back(stackCount);
        caseCount++;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "Case " << (i + 1) << ": " << resultSet[i] << endl;
//    }
    return 0;
}
