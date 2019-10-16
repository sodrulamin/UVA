#include <iostream>
//#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    //vector<int> resultSet;
    int caseCount = 1;
    while(t > 0)
    {
        int n;
        cin >> n;
        cout << "Case #" << caseCount++ << ": " << (2 * n - 1) << endl;
        //resultSet.push_back((2 * n - 1));
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << "Case #" << (i + 1) << ": " << resultSet[i] << endl;
//    }
    return 0;
}
