#include <iostream>
#include <vector>

using namespace std;

int digitSum(int n)
{
    int sum = 0;
    while(n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    //vector<int> resultSet;
    while(t)
    {
        int n;
        cin >> n;
        int generator = 0;
        int nn = n,digitCount = 0,result = 0;
        while(nn)
        {
            digitCount++;
            nn /= 10;
        }
        int startIndex = n - digitCount * 9;
        if(startIndex <= 0)
            startIndex = 1;
        while(startIndex < n)
        {
            int v = digitSum(startIndex);
            //cout << "Cur: " << startIndex << " Digit: " << v << " sum: " << (startIndex + v) << endl;
            if((startIndex + v) == n)
            {
                result = startIndex;
                break;
            }
            startIndex++;
        }
        cout << result << endl;
        //resultSet.push_back(result);
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
