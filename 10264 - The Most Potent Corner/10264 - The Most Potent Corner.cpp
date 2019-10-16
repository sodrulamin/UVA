#include <iostream>
#include <vector>

using namespace std;

int pow(int a,int n)
{
    ///return a ^ n
    int value = 1;
    for(int i=0;i<n;i++)
        value = value * a;
    return value;
}

int main()
{
    int n,a;
    while(cin >> n)
    {
        vector<int> weights,potencies;
        int entryCount = pow(2, n);
        for(int i=0;i<entryCount;i++)
        {
            cin >> a;
            weights.push_back(a);
        }
        //int maxSum = 0;
        for(int i=0;i<entryCount;i++)
        {
            int sum = 0;
            //cout << "Current Corner: " << i << " Weight of Current Corner: " << weights[i] << endl;
            for(int j=0;j<n;j++)
            {
                int neighbour = i ^ (1 << j);
                sum = sum + weights[neighbour];
                //cout << "Neighbour: " << neighbour << " weight: " << weights[neighbour] << endl;
            }

            //cout << "Current: " << i << " Weight: " << weights[i] << " Sum: " << sum << endl << endl;
//            if(sum > maxSum)
//            {
//                maxSum = sum;
//            }
            potencies.push_back(sum);
        }
        int maxPotencies = 0;
        for(int i=0;i<entryCount;i++)
        {
            int sum = 0;
            //cout << "Current Corner: " << i << " Weight of Current Corner: " << weights[i] << endl;
            for(int j=0;j<n;j++)
            {
                int neighbour = i ^ (1 << j);
                sum = potencies[i] + potencies[neighbour];
                if(sum > maxPotencies)
                {
                    maxPotencies = sum;
                }
            }

            //cout << "Current: " << i << " Weight: " << weights[i] << " Sum: " << sum << endl << endl;
//            if(sum > maxSum)
//            {
//                maxSum = sum;
//            }
            potencies.push_back(sum);
        }
        cout << maxPotencies << endl;
    }
    return 0;
}
