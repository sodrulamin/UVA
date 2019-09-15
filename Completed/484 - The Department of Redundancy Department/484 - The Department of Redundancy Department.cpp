#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    vector<int> sequence;
    map<int,int> occuranceMap;
    map<int,int>::iterator it;
    int n;
    while(cin >> n)
    {
        it = occuranceMap.find(n);
        if(it == occuranceMap.end()){
            occuranceMap.insert(make_pair(n,1));
            sequence.push_back(n);
        }else{
            it->second++;
        }
    }

    for(int i=0;i<sequence.size();i++)
    {
        it = occuranceMap.find(sequence[i]);
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}
