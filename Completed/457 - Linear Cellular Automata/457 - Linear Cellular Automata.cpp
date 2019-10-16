#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int DNA[10] = {0};
    while(t > 0)
    {
        for(int i=0;i<10;i++)
        {
            cin >> DNA[i];
        }
        int currentPopulation[42];
        for(int i=0;i<42;i++)
            currentPopulation[i] = 0;
        currentPopulation[20] = 1;
        for(int i=0;i<50;i++)
        {
            int newPopulation[42];
            for(int j=1;j<=40;j++)
            {

                switch(currentPopulation[j])
                {
                    case 0:
                        cout << " ";
                        break;
                    case 1:
                        cout << ".";
                        break;
                    case 2:
                        cout << "x";
                        break;
                    case 3:
                        cout << "W";
                        break;
                }
                //cout << currentPopulation[j] << " ";
                newPopulation[j] = DNA[currentPopulation[j - 1] + currentPopulation[j] + currentPopulation[j + 1]];
            }
            cout << endl;

            for(int j=1;j<=40;j++)
                currentPopulation[j] = newPopulation[j];
        }

        t--;
        if(t)
            cout << endl;
    }
    return 0;
}

