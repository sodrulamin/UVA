#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;


int main()
{
    int caseCount;
    cin >> caseCount;
    while(caseCount > 0)
    {
        int n;
        cin >> n;
        /*if(n == 0)
            break;*/
        int numbers[n],minNum = -1,maxNum = -1;
        for(int i=0;i<n;i++)
        {
            cin >> numbers[i];
            if(minNum == -1)
            {
                minNum = numbers[i];
                maxNum = numbers[i];
            }else
            {
                if(numbers[i] > maxNum)
                {
                    maxNum = numbers[i];
                }
                else if(numbers[i] < minNum)
                {
                    minNum = numbers[i];
                }
            }
        }
        //sort(numbers, numbers + n);
        int minSum = -1;
        for(int index = minNum; index <= maxNum;index++)
        {
            int sum = 0;
            for(int i=0;i<n;i++)
            {
                int sub = abs(numbers[i] - index);

                sum += sub;
                if(minSum > -1 && sum > minSum)
                    break;
            }
            if(sum < minSum || minSum == -1)
                minSum = sum;
        }
        cout << minSum << endl;
        caseCount--;
    }
    return 0;
}
