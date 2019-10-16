#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    //vector<int> resultSet;
    while(t > 0)
    {
        char ch;
        int m,n;
        cin >> ch >> m >> n;
        int result = 0;
        switch(ch)
        {
            case 'r':
                result = min(m,n);
                break;
            case 'k':
                result =  m * n;
                if(result % 2 == 0)
                {
                    result = result / 2;
                }
                else
                {
                    result = result / 2 + 1;
                }
                break;
            case 'Q':
                result = min(m,n);
                break;
            case 'K':
                if(m % 2 == 0)
                    m = m / 2;
                else
                    m = m / 2 + 1;
                if(n % 2 == 0)
                    n = n / 2;
                else
                    n = n / 2 + 1;
                result = m * n;
                break;
        }
        cout << result << endl;
        //resultSet.push_back(result);
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//        cout << resultSet[i] << endl;
    return 0;
}
