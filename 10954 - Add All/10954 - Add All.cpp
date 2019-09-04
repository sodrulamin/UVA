#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main()
{
    int n;
    while(cin >> n){
        if(n == 0)
            break;
        priority_queue<int, vector<int>, greater<int> > numberQ;
        int a;
        for(int i=0;i<n;i++){
            cin >> a;
            numberQ.push(a);
        }
        int cost = 0;
        while(numberQ.size() > 1)
        {
            int a = numberQ.top();
            numberQ.pop();
            int b = numberQ.top();
            numberQ.pop();
            int sum = a + b;
            numberQ.push(sum);
            cost = cost + sum;
            //cout << "a: " << a << " b: " << b << " sum: " << sum << " cost: " << cost << endl;
        }
        cout << cost << endl;
    }
    return 0;
}
