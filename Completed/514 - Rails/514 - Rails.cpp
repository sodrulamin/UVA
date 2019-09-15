#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        int a;
        while(cin >> a){
            if(a == 0){
                cout << endl;
                break;
            }
            queue<int> aQueue;
            aQueue.push(a);
            for(int i=1;i<n;i++)
            {
                cin >> a;
                aQueue.push(a);
            }
            bool possible = true;
            int currentQueueANumber = 1;
            stack<int> stationStack;
            while(!aQueue.empty())
            {

                a = aQueue.front();
                aQueue.pop();
                //cout << a << " ";
                if(!stationStack.empty() && stationStack.top() == a)
                {
                    //cout << "taking from station size: " << stationStack.size() << endl;
                    stationStack.pop();
                    continue;
                }
                while(currentQueueANumber < n)
                {
                    if(currentQueueANumber == a)
                    {
                        //cout << "taking from queue A\n";
                        break;
                    }
                    stationStack.push(currentQueueANumber);
                    currentQueueANumber++;
                }
                if(currentQueueANumber != a)
                {
                    possible = false;
                    break;
                }
                currentQueueANumber++;
            }
            if(possible)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}
