#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string str;
    getline(cin,str);
    //vector<bool> resultSet;
    while(t > 0)
    {
        getline(cin,str);
        if(str.length() == 0)
            continue;
        int num[2];
        num[0] = 0;
        num[1] = 0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == 'M')
                num[0]++;
            else if(str[i] == 'F')
                num[1]++;
        }
        if(num[0] > 1 && num[1] > 1 && num[0] == num[1]){
            cout << "LOOP" << endl;
            //resultSet.push_back(true);
        }
        else{
            cout << "NO LOOP" << endl;
            //resultSet.push_back(false);
        }
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i]){
//            cout << "LOOP" << endl;
//        }
//        else{
//            cout << "NO LOOP" << endl;
//        }
//    }
    return 0;
}
