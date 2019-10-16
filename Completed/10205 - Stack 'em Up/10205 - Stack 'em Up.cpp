#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string suites[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
string numbers[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
int shuffleIndex[101][52];

struct Card
{
    string suit,value;
};

int main()
{
    int t;
    cin >> t;

    bool first = true;
    while(t > 0)
    {

        Card initSeq[53];
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<13;j++)
            {
                initSeq[i * 13 + j + 1].suit = suites[i];
                initSeq[i * 13 + j + 1].value = numbers[j];
            }
        }

        int n;
        cin >> n;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<52;j++)
                cin >> shuffleIndex[i][j];
        }
        string str;
        getline(cin,str);
        getline(cin,str);
        while(str.length() > 0)
        {
            int i = stoi(str);
            Card newSeq[53];
            for(int j=0;j<52;j++)
            {
                newSeq[j + 1] = initSeq[shuffleIndex[i][j]];
                //cout << shuffleIndex[i][j] << " --> " << (j + 1) << endl;
            }
            for(int j=1;j<53;j++)
                initSeq[j] = newSeq[j];
//            for(int i=1;i<53;i++)
//            {
//                cout << newSeq[i].value << " of " << newSeq[i].suit << endl;
//            }
            //initSeq = newSeq;
            getline(cin,str);
        }
        if(!first)
            cout << endl;
        else
            first = false;
        for(int i=1;i<53;i++)
        {
            cout << initSeq[i].value << " of " << initSeq[i].suit << endl;
        }
        t--;
    }
    return 0;
}
