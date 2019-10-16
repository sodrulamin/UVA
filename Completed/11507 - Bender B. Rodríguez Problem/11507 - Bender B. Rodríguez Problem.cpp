#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string newPos(string curPos,string newMove)
{
//    if(newMove == "no")
//        return curPos;
    if(curPos == "+x")
    {
        curPos = newMove;
    }
    else if(curPos == "-x")
    {
//        if(newMove[0] = '-')
//            newMove[0] = '+';
//        else
//            newMove[0] = '-';
//        curPos = newMove;
        if(newMove == "+y")
            curPos = "-y";
        else if(newMove == "-y")
            curPos = "+y";
        else if(newMove == "+z")
            curPos = "-z";
        else if(newMove == "-z")
            curPos = "+z";
    }
    else if(curPos == "+y")
    {
        if(newMove == "+y")
            curPos = "-x";
        else if(newMove == "-y")
            curPos = "+x";
    }
    else if(curPos == "-y")
    {
        if(newMove == "+y")
            curPos = "+x";
        else if(newMove == "-y")
            curPos = "-x";
    }
    else if(curPos == "+z")
    {
        if(newMove == "+z")
            curPos = "-x";
        else if(newMove == "-z")
            curPos = "+x";
    }
    else if(curPos == "-z")
    {
        if(newMove == "+z")
            curPos = "+x";
        else if(newMove == "-z")
            curPos = "-x";
    }
    return curPos;
}

int main()
{
    int n;
    //vector<string> resultSet;
    while(scanf("%d",&n) > 0)
    {
        if(n == 0)
            break;
        string command;
        //vector<string> commandList;
        string currPosition = "+x";
        for(int i=0;i<n - 1;i++)
        {
            //scanf("%s",command);
            cin >> command;
            //commandList.push_back(command);
            if(command != "No"){
                //cout << "CurPos: " << currPosition << " newMove: " << command;
                currPosition = newPos(currPosition,command);
                //cout << " newPos: " << currPosition << endl;
            }
        }

//        printf("Enlisted Commands: ");
//        for(int i=0;i<commandList.size();i++)
//        {
//            //printf("%s ",commandList[i]);
//            cout << commandList[i] << " ";
//        }
//        printf("\n");
        cout << currPosition << endl;
        //resultSet.push_back(currPosition);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        cout << resultSet[i] << endl;
//    }
    return 0;

}
