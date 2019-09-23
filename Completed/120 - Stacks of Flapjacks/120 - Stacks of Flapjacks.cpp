#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>


using namespace std;

vector<int> inputSequence;


void printNumbers()
{
    for(int i=0;i<inputSequence.size();i++)
    {
        cout << inputSequence[i] << " ";
    }
    cout << endl;
}
void flip(int index)
{
    stack<int> flipStack;
    //cout << "Getting Sequecne: ";
    for(int i=0;i<=index;i++)
    {

        flipStack.push(inputSequence[i]);
        //cout << flipStack.top() << " ";
    }
    int i = 0;
    //cout << endl << "Reversed: ";

    while(!flipStack.empty())
    {
        //cout << flipStack.top() << " ";
        inputSequence[i++] = flipStack.top();
        flipStack.pop();
    }
    //cout << endl << "After change: ";
    //cout << "Fliped: " << (inputSequence.size() - index) << " Now: ";
    //printNumbers();
    cout << (inputSequence.size() - index) << " ";
}


int main()
{
    string line;
    while(getline(cin,line))
    {
        if(line.length() == 0)
            continue;
        stringstream stream(line);
        inputSequence.clear();
        for(int i=0;i<4;i++)
        while(stream)
        {
            int n;
            stream >> n;
            if(stream){
                inputSequence.push_back(n);
            }
        }
        printNumbers();
        int n = inputSequence.size();
        int currentIndex = n - 1;
        while(currentIndex > 0)
        {
            int maxNum = inputSequence[currentIndex];
            int maxIndex = currentIndex;
            for(int i=0;i<currentIndex;i++)
            {
                if(inputSequence[i] > maxNum)
                {
                    maxNum = inputSequence[i];
                    maxIndex = i;
                }
            }
            if(maxIndex != currentIndex)
            {
                //cout << "curIndex: " << currentIndex << " maxIndex: " << maxIndex << endl;
                if(maxIndex > 0)
                    flip(maxIndex);
                flip(currentIndex);
            }
            currentIndex--;
        }
        cout << "0\n";
    }
    return 0;
}
