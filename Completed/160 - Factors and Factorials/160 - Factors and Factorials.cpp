#include <iostream>
//#include <vector>

using namespace std;

int primeNumbers[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main()
{
    int n;
//    vector<vector<int> > resultSet;
    while(cin >> n)
    {
        if(n == 0)
            break;
        int occurance[25] = {0};
        int maxPrimeIndex = 0;
        for(int num = n;num > 1;num--)
        {
            int currentPrimeIndex = 0, currentNumber = num;
            while(currentNumber > 1)
            {
                while(currentNumber % primeNumbers[currentPrimeIndex] == 0)
                {
                    if(currentPrimeIndex > maxPrimeIndex)
                        maxPrimeIndex = currentPrimeIndex;
                    currentNumber = currentNumber / primeNumbers[currentPrimeIndex];
                    occurance[currentPrimeIndex]++;
                }
                currentPrimeIndex++;
            }
        }
        if(n == 100)
            cout << n << "! =";
        else if(n > 9)
            cout << " " << n << "! =";
        else
            cout << "  " << n << "! =";
//        vector<int> result;
//        result.push_back(n);
        for(int i=0;i<=maxPrimeIndex;i++)
        {
//            cout << "  " << occurance[i];
            if(i > 1 && i % 15 == 0)
            {
                cout << endl << "      ";
            }
            if(occurance[i] >= 100)
                cout << occurance[i];
            else if(occurance[i] >= 10)
                cout << " " << occurance[i];
            else
                cout << "  " << occurance[i];
//            result.push_back(occurance[i]);
        }
        cout << endl;
//        resultSet.push_back(result);
    }

//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i][0] == 100)
//            cout << resultSet[i][0] << "! =";
//        else if(resultSet[i][0] > 9)
//            cout << " " << resultSet[i][0] << "! =";
//        else
//            cout << "  " << resultSet[i][0] << "! =";
////        cout << resultSet[i][0] << "! =";
//        for(int j=1;j<resultSet[i].size();j++)
//        {
//            if(j > 1 && j % 15 == 1)
//            {
//                cout << endl << "      ";
//            }
//            if(resultSet[i][j] >= 100)
//                cout << resultSet[i][j];
//            else if(resultSet[i][j] >= 10)
//                cout << " " << resultSet[i][j];
//            else
//                cout << "  " << resultSet[i][j];
//        }
//        cout << endl;
//    }
    return 0;
}
