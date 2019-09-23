#include <iostream>
//#include <vector>

using namespace std;

int main()
{
    unsigned long long n;
//    vector<unsigned long long> resultSet;
    while(cin >> n)
    {
        if(n == 0)
            break;
        unsigned long long sum = n * (n + 1) / 2;
        sum = sum * sum;
        cout << sum << endl;
//        resultSet.push_back(sum);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }

    return 0;
}
