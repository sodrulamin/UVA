#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
//    vector<stack<bool> > resultSet;
//    vector<int> paritySet;
    while(cin >> n)
    {
        if(n == 0)
            break;
        stack<bool> binary;
        int parity = 0;
        while(n > 0)
        {
            bool one = n & 1;
            if(one)
                parity++;
            binary.push(one);
            n = n >> 1;
        }
//        resultSet.push_back(binary);
//        paritySet.push_back(parity);
        cout << "The parity of ";
        while(!binary.empty())
        {
            cout << binary.top();
            binary.pop();
        }
        cout << " is " << parity << " (mod 2).\n";
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        stack<bool> binary = resultSet[i];
//        int parity = paritySet[i];
//        cout << "The parity of ";
//        while(!binary.empty())
//        {
//            cout << binary.top();
//            binary.pop();
//        }
//        cout << " is " << parity << " (mod 2).\n";
//    }
    return 0;
}
