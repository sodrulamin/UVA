#include <iostream>
//#include <vector>

using namespace std;

int main()
{
    //vector<bool> resultSet;
    int first[5];
    while(cin >> first[0] >> first[1] >> first[2] >> first[3] >> first[4])
    {
//        if(first[0] == -1)
//            break;
        int second[5];
        cin >> second[0] >> second[1] >> second[2] >> second[3] >> second[4];
        bool match = false;
        for(int i=0;i<5;i++)
        {
            if(first[i] == second[i])
            {
                match = true;
                break;
            }
        }
        if(match)
        {
            cout << "N" << endl;
        }
        else
        {
            cout << "Y" << endl;
        }
        //resultSet.push_back(match);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i])
//        {
//            cout << "N" << endl;
//        }
//        else
//        {
//            cout << "Y" << endl;
//        }
//    }
    return 0;
}
