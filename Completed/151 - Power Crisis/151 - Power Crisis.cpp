#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
//    vector<int> resultSet;
    while(cin >> n)
    {
        if(n == 0)
            break;
        bool found = false;
        int mod = 1;
        while(!found){
            vector<int> cities;
            for(int i=1;i<=n;i++)
                cities.push_back(i);
            int currentIndex = 0;
            while(cities.size() > 1)
            {
                if(cities[currentIndex] == 13)
                    break;
                cities.erase(cities.begin() + currentIndex);
                currentIndex += (mod - 1);
                currentIndex = currentIndex % cities.size();
            }
            if(cities.size() == 1)
                found = true;
            else
                mod++;
        }

        cout << mod << endl;
//        resultSet.push_back(mod);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;
}
