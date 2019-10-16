#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > charSet;

void init(){
    vector<char> vector0 {' '};
    charSet.push_back(vector0);
    vector<char> vector1 {'.',',','?','\"'};
    charSet.push_back(vector1);
    vector<char> vector2 {'a','b','c'};
    charSet.push_back(vector2);
    vector<char> vector3 {'d','e','f'};
    charSet.push_back(vector3);
    vector<char> vector4 {'g','h','i'};
    charSet.push_back(vector4);
    vector<char> vector5 {'j','k','l'};
    charSet.push_back(vector5);
    vector<char> vector6 {'m','n','o'};
    charSet.push_back(vector6);
    vector<char> vector7 {'p','q','r','s'};
    charSet.push_back(vector7);
    vector<char> vector8 {'t','u','v'};
    charSet.push_back(vector8);
    vector<char> vector9 {'w','x','y','z'};
    charSet.push_back(vector9);
}

int main()
{
    init();
    int t;
    cin >> t;
    while(t > 0)
    {
        int n;
        cin >> n;
        vector<int> numberList,countList;
        int a;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            numberList.push_back(a);
        }
        for(int i=0;i<n;i++)
        {
            cin >> a;
            countList.push_back(a);
        }

        for(int i=0;i<n;i++)
        {
            cout << charSet[numberList[i]][countList[i] - 1];
        }
        cout << endl;
        t--;
    }
    return 0;
}
