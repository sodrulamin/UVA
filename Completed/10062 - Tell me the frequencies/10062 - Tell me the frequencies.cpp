#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

class Character{

    public:
    int ascii;
    int frequency;
};
struct CustomCompare
{
    bool operator()(const Character& lhs, const Character& rhs)
    {
        if(lhs.frequency == rhs.frequency)
            return lhs.ascii < rhs.ascii;
        return lhs.frequency > rhs.frequency;
    }
};

int main()
{
    string line;
    bool first = true;
//    vector<int> asciiSet;
//    vector<int> frequencySet;
    while(getline(cin,line))
    {
//        if(line.length() == 0)
//            continue;
//        else if(line == "-1")
//            break;
        map<int,Character> charMap;
        map<int,Character>::iterator it;
        for(int i=0;i<line.length();i++)
        {
            int index = line[i];
            it = charMap.find(index);

            if(it == charMap.end())
            {
                Character c;
                c.ascii = index;
                c.frequency = 1;
                charMap.insert(make_pair(index,c));
            }
            else
            {
                it->second.frequency++;
            }
        }
        //cout << "Frequency count done" << endl;
        priority_queue<Character, vector<Character>, CustomCompare > sortedList;
        it = charMap.begin();
        for(;it != charMap.end();it++)
        {
            sortedList.push(it->second);
        }
        if(first)
            first = false;
        else
            printf("\n");
            //cout << endl;
        while(!sortedList.empty())
        {
            Character c = sortedList.top();
            sortedList.pop();
            //cout << c.ascii << " " << c.frequency << endl;
            printf("%d %d\n",c.ascii,c.frequency);
//            asciiSet.push_back(c.ascii);
//            frequencySet.push_back(c.frequency);
        }
        //cout << endl;
//        asciiSet.push_back(-1);
//        frequencySet.push_back(-1);
    }
//    for(int i=0;i<asciiSet.size();i++)
//    {
//        if(asciiSet[i] == -1)
//            cout << endl;
//        else
//        {
//            cout << asciiSet[i] << " " << frequencySet[i] << endl;
//        }
//    }

    return 0;
}
