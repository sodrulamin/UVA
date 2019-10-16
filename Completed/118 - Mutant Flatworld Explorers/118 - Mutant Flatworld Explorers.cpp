#include <iostream>
#include <string>
#include <vector>

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

using namespace std;

struct RobotPosOrientation
{
    int x,y;
    char orientation;

    bool moveForward();
    void chageOrientation(char ch);
    void print(bool alive);
    friend bool operator==(const RobotPosOrientation& c1, const RobotPosOrientation& c2)
    {
        //cout << "Comparing " << c1.frequency << " == " << c2.frequency << " = " << (c1.frequency == c2.frequency && c1.ascii == c2.ascii) << endl;
        return c1.x == c2.x && c1.y == c2.y;// && c1.orientation == c2.orientation;
    }
};


int maxXvalue,maxYvalue;
vector<RobotPosOrientation> scentRobots;
char directions[] = {'N','E','S','W'};

bool RobotPosOrientation::moveForward()
{

//    for(int i=0;i<scentRobots.size();i++)
//    {
//        if(scentRobots[i] == this)
//            return false;
//    }
    int newX = x,newY = y;
    switch(orientation)
    {
        case 'N':
            newY++;
            break;
        case 'S':
            newY--;
            break;
        case 'E':
            newX++;
            break;
        case 'W':
            newX--;
            break;
    }
    if(newX < 0 || newX > maxXvalue || newY < 0 || newY > maxYvalue){
        //scentRobots.push_back(this);
        return false;
    }
    x = newX;
    y = newY;
    return true;
}
void RobotPosOrientation::chageOrientation(char ch)
{
    int i=0;
    while(i < 4 && orientation != directions[i])
        i++;
    switch(ch)
    {
        case 'R':
            i++;
            break;
        case 'L':
            i--;
            break;
    }
    i = (i + 4) % 4;
    //cout << "Change orientation. Cur: " << orientation << " i: " << i << " new: " << directions[i] << endl;
    orientation = directions[i];
}
void RobotPosOrientation::print(bool alive)
{

    cout << x << " " << y << " " << orientation;
    if(!alive)
        cout << " LOST";
    cout << endl;
}

int main()
{
    cin >> maxXvalue >> maxYvalue;
    RobotPosOrientation rPos;
//    vector<RobotPosOrientation> resultSet;
//    vector<bool> lostSet;
    while(cin >> rPos.x >> rPos.y >> rPos.orientation)
    {
        if(rPos.x == -1)
            break;
        string command;
        cin >> command;
        bool alive = true;
        for(int i=0;i<command.length();i++)
        {
            if(command[i] == 'F')
            {
                bool ignore = false;
                for(int j=0;j<scentRobots.size();j++)
                {
                    if(scentRobots[j] == rPos){
                        ignore = true;
                        break;
                    }
                }

                alive = rPos.moveForward();
                if(ignore)
                {
                    alive = true;
                }
            }
            else
            {
                rPos.chageOrientation(command[i]);
            }
            //rPos.print(alive);
            if(!alive)
            {
                scentRobots.push_back(rPos);
                break;
            }
        }
        rPos.print(alive);
////        resultSet.push_back(rPos);
////        lostSet.push_back(alive);
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        resultSet[i].print(lostSet[i]);
//    }
    return 0;
}
