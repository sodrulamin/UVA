#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t > 0)
    {
        bool result = true;
        int arr[5];
        for(int i=0;i<5;i++)
        {
            cin >> arr[i];
            if(result && i && arr[i] != arr[i - 1] + 1)
                result = false;
        }
        if(result)
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
        t--;
    }
    return 0;
}
