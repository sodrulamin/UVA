#include <iostream>

using namespace std;

int maxStick;

void findRecursive(int remainingBox,int stickUsed,int startRange, int endRange)
{
    if(endRange < startRange){
        return;
    }
    int middle = (endRange + startRange) / 2;
    cout << "Rem: " << remainingBox  << " start: " << startRange << " end: " << endRange << " mid: " << middle ;
    if(remainingBox == 1)
    {
//        int n = endRange - startRange;
//        n = (n * (n + 1)) / 2;
//        stickUsed = stickUsed + n + startRange;
        for(int i=startRange;i<=endRange;i++)
            stickUsed += i;
        if(stickUsed > maxStick)
            maxStick = stickUsed;
        cout << " Used: " << stickUsed << endl;
        return;
    }
    if(endRange == startRange)
    {
        //stickUsed += startRange;
        if(stickUsed > maxStick)
            maxStick = stickUsed;
        cout << " Used: " << stickUsed << endl;
        return;
    }
    stickUsed += middle;
    cout << " Used: " << stickUsed << endl;
    findRecursive(remainingBox,stickUsed,middle + 1,endRange);
    findRecursive(remainingBox - 1,stickUsed,startRange,middle - 1);
}

int main()
{
    int n;
    cin >> n;
    while(n > 0)
    {
        int k,m;
        cin >> k >> m;
        maxStick = 0;
        findRecursive(k,0,1,m);
        cout << "Maximum stick required: " << maxStick << endl;
        n--;
    }
    return 0;
}
