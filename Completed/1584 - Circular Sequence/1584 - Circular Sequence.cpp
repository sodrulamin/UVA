#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    //vector<string> resultSet;
    while(t)
    {
        string sequence;
        cin >> sequence;
        string smallestSequence = sequence;


        for(int i=0;i<sequence.length() - 1;i++)
        {
            char ch = sequence[0];
            sequence.insert(sequence.end(),1,ch);
            sequence.erase(sequence.begin());
            if(sequence < smallestSequence)
                smallestSequence = sequence;
        }
        cout << smallestSequence << endl;
        //resultSet.push_back(smallestSequence);
        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
