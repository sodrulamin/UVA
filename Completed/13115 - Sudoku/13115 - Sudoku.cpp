#include <iostream>
#include <cmath>
#include <vector>

#define array_size 25

using namespace std;

int main()
{
    int t;
    cin >> t;
    //vector<bool> resultSet;
    while(t > 0)
    {
        int n;
        cin >> n;

        int r = sqrt(n), a;
        bool inputSet[array_size][array_size] = {false};
        bool inputSet2[array_size][array_size] = {false};
        int inputValue[n][n];
        bool result = true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> inputValue[i][j];
                if(inputSet[i][inputValue[i][j] - 1])
                {
                    result = false;
                }
                else if(inputSet2[j][inputValue[i][j] - 1])
                {
                    result = false;
                }
                inputSet[i][inputValue[i][j] - 1] = true;
                inputSet2[j][inputValue[i][j] - 1] = true;
            }
        }
        //cout << "Checking" << endl;
        for(int i=0;i<r && result;i++)
        {
            for(int j=0;j<r && result;j++)
            {
                int rowStart = i * r;
                int colStart = j * r;
                bool present[array_size] = {false};
                for(int k=0;k<r && result;k++)
                {
                    for(int l=0;l<r && result;l++)
                    {
                        //cout << inputValue[rowStart + k][colStart + l] << " ";
                        if(present[inputValue[rowStart + k][colStart + l] - 1])
                            result = false;
                        present[inputValue[rowStart + k][colStart + l] - 1] = true;
                    }
                    //cout << endl;
                }
                //cout << endl;
            }
        }

        if(result)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        //resultSet.push_back(result);

        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i])
//        {
//            cout << "yes" << endl;
//        }
//        else
//        {
//            cout << "no" << endl;
//        }
//    }

    return 0;
}
