#include <iostream>
#include <string>

using namespace std;

int mapping[] =
{
    2,2,2,
    3,3,3,
    4,4,4,
    5,5,5,
    6,6,6,
    7,7,7,7,
    8,8,8,
    9,9,9,9
};

int main()
{
    string line;
    while(cin >> line)
    {
        //cout << "We received: " << line << endl;
        for(int i=0;i<line.length();i++)
        {
            if(isalpha(line[i]))
            {
                int a = mapping[line[i] - 'A'];
                line[i] = '0' + a;
            }
        }
        cout << line << endl;
    }
    return 0;
}
