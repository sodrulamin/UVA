#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a,b;
    //vector<vector<int> > resultSet;
    while(cin >> a >> b)
    {
        if(a == 0)
            break;
        vector<int> result;
        while(a % b != 0)
        {
            //cout << a << " " << b << " div: " << (a / b) << endl;
            result.push_back(a / b);
            int temp = a % b;
            a = b;
            b = temp;
        }
        result.push_back(a / b);
        cout << "[" << result[0];
        if(result.size() > 1)
            cout << ";";
        for(int i=1;i<result.size();i++)
        {
            cout << result[i];
            if(i < result.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
        //resultSet.push_back(result);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        vector<int> result = resultSet[i];
//        cout << "[" << result[0];
//        if(result.size() > 1)
//            cout << ";";
//        for(int i=1;i<result.size();i++)
//        {
//            cout << result[i];
//            if(i < result.size() - 1)
//                cout << ",";
//        }
//        cout << "]" << endl;
//    }
    return 0;
}
