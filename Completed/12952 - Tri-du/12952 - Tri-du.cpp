#include <iostream>
//#include <vector>

using namespace std;

int main()
{
    int a,b;
    //vector<int> resultSet;
    while(cin >> a >> b)
    {

//        if(a == 0)
//            break;
        if(a > b){
            cout << a << endl;
            //resultSet.push_back(a);
        }
        else{
            cout << b << endl;
            //resultSet.push_back(b);
        }
    }
//    for(int i=0;i<resultSet.size();i++)
//        cout << resultSet[i] << endl;
    return 0;
}
