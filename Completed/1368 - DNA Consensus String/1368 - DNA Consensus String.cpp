#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t > 0)
    {
        int m,n;
        cin >> m >> n;
        int presenceCount[1001][4] = {0};
        string str;
        for(int i=0;i<m;i++)
        {
            cin >> str;
            for(int j=0;j<n;j++)
            {
                switch(str[j])
                {
                    case 'A':
                        presenceCount[j][0]++;
                        break;
                    case 'C':
                        presenceCount[j][1]++;
                        break;
                    case 'G':
                        presenceCount[j][2]++;
                        break;
                    case 'T':
                        presenceCount[j][3]++;
                        break;
                }
            }
        }
        int maxPresence[1001];
        int hammingDistance = 0;
        for(int i=0;i<n;i++)
        {
            int count = presenceCount[i][0];
            maxPresence[i] = 0;
            for(int j=1;j<4;j++)
            {
                if(presenceCount[i][j] > count)
                {
                    count = presenceCount[i][j];
                    maxPresence[i] = j;
                }

            }
            //cout << "index: " << i << " Ham: " << hammingDistance << " count: " << count << endl;
            hammingDistance = hammingDistance + (m - count);
        }
        for(int i=0;i<n;i++){
            char ch = 'A';
            switch(maxPresence[i])
            {
                case 0:
                    ch = 'A';
                    break;
                case 1:
                    ch = 'C';
                    break;
                case 2:
                    ch = 'G';
                    break;
                case 3:
                    ch = 'T';
                    break;
            }
            cout << ch;
        }
        cout << endl << hammingDistance << endl;
        t--;
    }
    return 0;
}
