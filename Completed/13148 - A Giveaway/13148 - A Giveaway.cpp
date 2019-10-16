#include <iostream>
#include <unordered_set>
//#include <vector>

using namespace std;

unordered_set<int> mySet = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,
1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,
47045881, 64000000, 85766121};

int main()
{
    unsigned int n;
    //vector<bool> resultSet;
    while(cin >> n)
    {
        if(n == 0)
            break;
        if(mySet.find(n) != mySet.end())
        {
            cout << "Special" << endl;
            //resultSet.push_back(true);
        }
        else
        {
            cout << "Ordinary" << endl;
            //resultSet.push_back(false);
        }
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i])
//        {
//            cout << "Special" << endl;
//        }
//        else
//        {
//            cout << "Ordinary" << endl;
//        }
//    }
    return 0;
}
