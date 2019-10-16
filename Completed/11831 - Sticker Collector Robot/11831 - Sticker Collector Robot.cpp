#include <iostream>
#include <vector>

using namespace std;

char directions[] = {'N', 'L', 'S', 'O'};
char arena[100][100];

struct RobotPosOrientation
{
    int x,y,stickerCount;
    char orientation;

    void moveForward(int n, int m);
    void chageOrientation(char ch);
    void print();
    friend bool operator==(const RobotPosOrientation& c1, const RobotPosOrientation& c2)
    {
        //cout << "Comparing " << c1.frequency << " == " << c2.frequency << " = " << (c1.frequency == c2.frequency && c1.ascii == c2.ascii) << endl;
        return c1.x == c2.x && c1.y == c2.y;// && c1.orientation == c2.orientation;
    }
};

void RobotPosOrientation::moveForward(int n, int m)
{
    ///North = UP, West = LEFT
    int newX = x,newY = y;
    switch(orientation)
    {
        case 'N':
            newX--;
            break;
        case 'S':
            newX++;
            break;
        case 'L':
            newY++;
            break;
        case 'O':
            newY--;
            break;
    }
    if(newX < 0 || newX >= n || newY < 0 || newY >= m || arena[newX][newY] == '#'){
        //scentRobots.push_back(this);
        return;
    }
    x = newX;
    y = newY;

    if(arena[x][y] == '*')
        stickerCount++;
    arena[x][y] = '.';
}
void RobotPosOrientation::chageOrientation(char ch)
{
    int i=0;
    while(i < 4 && orientation != directions[i])
        i++;
    switch(ch)
    {
        case 'D':
            i++;
            break;
        case 'E':
            i--;
            break;
    }
    i = (i + 4) % 4;
    //cout << "Change orientation. Cur: " << orientation << " i: " << i << " new: " << directions[i] << endl;
    orientation = directions[i];
}
void RobotPosOrientation::print()
{
    cout << x << " " << y << " orientation: " << orientation << " sticker: " << stickerCount << endl;
}

int main()
{
    int n,m,s;
    while(cin >> n >> m >> s)
    {
        if(n == 0 && m == 0 && s == 0)
            break;
        //char arena[n][m];
        RobotPosOrientation rPos;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> arena[i][j];
                if(isalpha(arena[i][j]))
                {
                    rPos.x = i;
                    rPos.y = j;
                    rPos.orientation = arena[i][j];
                    rPos.stickerCount = 0;
                    arena[i][j] = '.';
                }
            }
        }
        char command;
        //rPos.print();
        for(int k=0;k<s;k++)
        {
            cin >> command;
            if(command == 'F')
            {
                rPos.moveForward(n, m);
            }
            else
            {
                rPos.chageOrientation(command);
            }
//            cout << command << " ";
//            rPos.print();
        }
        cout << rPos.stickerCount << endl;
    }
    return 0;
}
