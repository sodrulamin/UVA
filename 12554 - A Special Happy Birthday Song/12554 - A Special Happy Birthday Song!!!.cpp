#include <iostream>
#include <string>
#include <vector>

using namespace std;

string song[] = {"Happy","birthday","to"};

int main()
{
    int n;

    cin >> n;

    vector<string> names;
    string name;
    for(int i=0;i<n;i++)
    {
        cin >> name;
        names.push_back(name);
    }
    int startIndex = 0;
    while(startIndex < names.size())
    {
        for(int i=0;i<2;i++)
        {
            for(int i=0;i<3;i++)
            {
                //startIndex %= n;
                cout << names[startIndex % n] << ": " << song[i] << endl;
                startIndex++;
            }
            //startIndex %= n;
            cout << names[startIndex % n] << ": you" << endl;
            startIndex++;
        }
        for(int i=0;i<3;i++)
        {
            //startIndex %= n;
            cout << names[startIndex % n] << ": " << song[i] << endl;
            startIndex++;
        }
        //startIndex %= n;
        cout << names[startIndex % n] << ": Rujia" << endl;
        startIndex++;

        for(int i=0;i<3;i++)
        {
            //startIndex %= n;
            cout << names[startIndex % n] << ": " << song[i] << endl;
            startIndex++;
        }
        //startIndex %= n;
        cout << names[startIndex % n] << ": you" << endl;
        startIndex++;
    }
    return 0;
}
