#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> inputSequence;
map<int, vector<int> > orderMap;
//vector<vector<char> > resultSet;

bool isAvailable(int index, bool taken[])
{
    int a = inputSequence[index];
    map<int, vector<int> >::iterator it;
    it = orderMap.find(a);
    if(it == orderMap.end())
        return true;
    vector<int> order = it->second;
    for(int i=0;i<order.size();i++)
    {
        if(!taken[order[i]])
            return false;
    }
    return true;
}

void visitRecursive(bool taken[], int depth, int numbers[])
{
    if(depth == inputSequence.size())
    {
        vector<char> result;
        char ch;
        for(int i=0;i<depth;i++)
        {
            ch = 'a' + numbers[i];
            result.push_back(ch);
            cout << ch;
        }
        cout << endl;
//        resultSet.push_back(result);
        return;
    }
    for(int i=0;i<inputSequence.size();i++)
    {
        if(!taken[inputSequence[i]] && isAvailable(i, taken))
        {
            numbers[depth] = inputSequence[i];
            taken[inputSequence[i]] = true;
            visitRecursive(taken, depth + 1, numbers);
            taken[inputSequence[i]] = false;
        }
    }
}

int main()
{
    string line,constraints;
    bool firstInput = true;
    while(getline(cin, line))
    {
        if(line.size() == 0)break;
        inputSequence.clear();
        orderMap.clear();

        for(int i=0;i<line.length();i++)
        {
            if(isalpha(line[i]))
            {
                inputSequence.push_back(line[i] - 'a');
            }
        }
        sort(inputSequence.begin(), inputSequence.end());

        map<int, vector<int> >::iterator it;

        getline(cin, constraints);
        for(int i=0;i<constraints.length();i++)
        {
            if(isalpha(constraints[i]))
            {
                int a,b;
                a = constraints[i] - 'a';
                i++;
                while(!isalpha(constraints[i]))i++;
                b = constraints[i] - 'a';
                it = orderMap.find(b);
                if(it == orderMap.end())
                {
                    vector<int> order;
                    order.push_back(a);
                    orderMap.insert(make_pair(b, order));
                }
                else
                {
                    it->second.push_back(a);
                }
            }
        }

        bool taken[26] = {false};
        int numbers[inputSequence.size()];

        if(!firstInput)
            cout << endl;
        else
            firstInput = false;
        visitRecursive(taken, 0, numbers);
        //resultSet[resultSet.size() - 1].push_back('\n');
    }

//    for(int i=0;i<resultSet.size();i++)
//    {
//        for(int j=0;j<resultSet[i].size();j++)
//        {
//            cout << resultSet[i][j];
//        }
//        cout << endl;
//    }

    return 0;
}
