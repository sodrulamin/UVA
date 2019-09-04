#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

string s1,s2;

struct pos{
    int x,y,move;
};

bool isValid(pos point){
    if(point.x <= 0 || point.y <= 0 || point.x > 8 || point.y > 8)
        return false;
    return true;
}
pos createPosition(int x,int y,int move){
    pos newpos;
    newpos.x = x;
    newpos.y = y;
    newpos.move = move;

    return newpos;
}

void BFS(pos src,pos dst){
    queue<pos> pendingQueue;
    pendingQueue.push(src);
    bool visited[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            visited[i][j] = false;
        }
    }

    while(!pendingQueue.empty()){
        pos currentPosition = pendingQueue.front();
        pendingQueue.pop();
        visited[currentPosition.x][currentPosition.y] = true;
        if(currentPosition.x == dst.x && currentPosition.y == dst.y){
            cout << "To get from " << s1 << " to " << s2 << " takes " << currentPosition.move <<" knight moves.\n";

            break;
        }
        pos new_positions[8];
        new_positions[0] = createPosition(currentPosition.x - 1, currentPosition.y - 2 ,currentPosition.move + 1);
        new_positions[1] = createPosition(currentPosition.x - 2, currentPosition.y - 1 ,currentPosition.move + 1);
        new_positions[2] = createPosition(currentPosition.x - 2, currentPosition.y + 1 ,currentPosition.move + 1);
        new_positions[3] = createPosition(currentPosition.x - 1, currentPosition.y + 2 ,currentPosition.move + 1);
        new_positions[4] = createPosition(currentPosition.x + 1, currentPosition.y + 2 ,currentPosition.move + 1);
        new_positions[5] = createPosition(currentPosition.x + 2, currentPosition.y + 1 ,currentPosition.move + 1);
        new_positions[6] = createPosition(currentPosition.x + 2, currentPosition.y - 1 ,currentPosition.move + 1);
        new_positions[7] = createPosition(currentPosition.x + 1, currentPosition.y - 2 ,currentPosition.move + 1);


        for(int i=0;i<8;i++){
            if(!visited[new_positions[i].x][new_positions[i].y] && isValid(new_positions[i])){
                pendingQueue.push(new_positions[i]);
                visited[new_positions[i].x][new_positions[i].y] = true;
            }
        }
    }
}

int main(){

    while(cin >> s1 >> s2){
        int r1,c1,r2,c2;
        r1 = s1[0] - 'a' + 1;
        c1 = s1[1] - '0';
        r2 = s2[0] - 'a' + 1;
        c2 = s2[1] - '0';
        pos src = createPosition(r1,c1,0);
        pos dst = createPosition(r2,c2,0);

        BFS(src,dst);
    }

}
