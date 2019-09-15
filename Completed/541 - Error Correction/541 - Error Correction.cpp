#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;
        int rowParity[100] = {0};
        int colParity[100] = {0};
        int number;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> number;
                rowParity[i] += number;
                colParity[j] += number;
            }
        }

        /*for(int i=0;i<n;i++){
            cout << "rowPar " << (i + 1) << ": " << rowParity[i] << " colPar " << (i + 1) << ": " << colParity[i] << endl;
        }*/

        int result = 0,rowPos = -1,colPos = -1;
        for(int i=0;i<n;i++)
        {
            if(rowParity[i] % 2 != 0)
            {

                if(rowPos != -1)
                {
                    result = 1;
                    break;
                }
                else
                    rowPos = i + 1;
            }
            if(colParity[i] % 2 != 0)
            {
                if(colPos != -1)
                {
                    result = 1;
                    break;
                }
                else
                {
                    colPos = i + 1;
                }
            }
        }
        //cout << "rowPos: " << rowPos << " colPos: " << colPos << endl;

        if(result == 0 && rowPos == -1 && colPos == -1)
        {
            cout << "OK\n";
        }
        else if(result == 1 || rowPos == -1 || colPos == -1)
        {
            cout << "Corrupt\n";
        }
        else if(rowPos != -1 && colPos != -1)
        {
            cout << "Change bit (" << rowPos << "," << colPos << ")\n";
        }
    }
    return 0;
}
