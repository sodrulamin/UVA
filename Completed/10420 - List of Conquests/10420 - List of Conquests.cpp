#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;
        string country,name;
        map<string,int> conquestCount;
        map<string,int>::iterator it;
        for(int i=0;i<n;i++)
        {
            cin >> country;
            getline(cin,name);
            //cout << "Country: " << country << " Name: " << name << endl;
            it = conquestCount.find(country);
            if(it == conquestCount.end())
            {
                conquestCount.insert(make_pair(country,1));
            }else
            {
                it->second++;
            }
        }
        for(it = conquestCount.begin();it != conquestCount.end(); it++)
        {
            cout << it->first << " " << it->second << endl;
        }

    }
    return 0;
}
