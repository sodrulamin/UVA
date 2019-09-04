#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct HeightIndex{
    int index,height;
    bool isStart;
    HeightIndex(int i,int h, bool s)
    : index(i) , height(h), isStart(s)
    {

    }
};

struct compareIndex
{
    bool operator()(HeightIndex const& hi1, HeightIndex const& hi2)
    {
        if(hi1.index == hi2.index)
            return hi1.height < hi2.height;
        return hi1.index > hi2.index;
    }
};

int main()
{
    int Li,Ri,Hi;
    priority_queue<HeightIndex, vector<HeightIndex>, compareIndex> indexQ;
    while(cin >> Li >> Hi >> Ri)
    {
        /*if(Li == 0 && Ri == 0)
            break;*/
        indexQ.push(HeightIndex(Li,Hi,true));
        indexQ.push(HeightIndex(Ri,Hi,false));
    }
    //priority_queue<HeightIndex, vector<HeightIndex>, compareIndex>::iterator it;
    priority_queue<int> currentHeightAvailable;
    int currentHeight = 0;
    bool isFirst = true;
    while(!indexQ.empty())
    {

        HeightIndex h = indexQ.top();
        indexQ.pop();
        int index = h.index;
        //cout << h.index << " " << h.height << endl;

        while(!indexQ.empty()){
            HeightIndex nextTop = indexQ.top();
            if(nextTop.index != h.index)
                break;
            if(h.isStart)
            {
                currentHeightAvailable.push(h.height);
            }
            else
            {
                vector<int> intList;
                while(currentHeightAvailable.top() != h.height)
                {
                    intList.push_back(currentHeightAvailable.top());
                    currentHeightAvailable.pop();
                }
                currentHeightAvailable.pop();
                for(int i=0;i<intList.size();i++)
                {
                    currentHeightAvailable.push(intList[i]);
                }
            }
            //cout << h.index << " " << h.height << " " << nextTop.index << " " << nextTop.height << " " << currentHeightAvailable.top() << endl;
            h = nextTop;
            indexQ.pop();
        }
        if(h.isStart)
        {
            currentHeightAvailable.push(h.height);
        }
        else
        {
            vector<int> intList;
            while(currentHeightAvailable.top() != h.height)
            {
                intList.push_back(currentHeightAvailable.top());
                currentHeightAvailable.pop();
            }
            currentHeightAvailable.pop();
            for(int i=0;i<intList.size();i++)
            {
                currentHeightAvailable.push(intList[i]);
            }
        }
        int newHeight = 0;
        if(!currentHeightAvailable.empty())
        {
            newHeight = currentHeightAvailable.top();
        }
        if(currentHeight != newHeight)
        {
            currentHeight = newHeight;
            if(isFirst)
            {
                isFirst = false;
            }
            else
            {
                cout << " ";
            }
            cout << index << " " << currentHeight;
        }
    }
    cout << endl;
    return 0;
}
