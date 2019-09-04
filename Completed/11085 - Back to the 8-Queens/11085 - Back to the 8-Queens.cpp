#include <iostream>
#include <cstdio>
#include <vector>

#define ARRAY_SIZE 8

using namespace std;

int queenPositions[ARRAY_SIZE];
int bestMoves;

void constructor(){
    bestMoves = ARRAY_SIZE + 1;
    for(int i=0;i<ARRAY_SIZE;i++){
        queenPositions[i] = -1;
    }
}
bool isAttaking(int index, bool isMoved[]){
    int r1 = queenPositions[index], c1 = index + 1;

    for(int i = 0;i<ARRAY_SIZE; i++){
        if(i == index || isMoved[i])
            continue;
        int pos = queenPositions[i];
        if(r1 == pos)
            return true;
        else{
            int rowDiff = r1 - pos;
            int colDiff = c1 - i - 1;
            if(rowDiff == colDiff || rowDiff == (-colDiff)){
                return true;
            }
        }
    }
    return false;
}

void findResult(int index, int moveCout, bool isMoved[]){
    if(index > ARRAY_SIZE || moveCout >= bestMoves){
        return;
    }else if(index == ARRAY_SIZE){


        int sum = 0;
        for(int i=0;i<ARRAY_SIZE;i++){
            if(isMoved[i]){
                sum += 1;
            }else if(isAttaking(i,isMoved)){
                return;
            }
        }

        if(sum < bestMoves){

            ///cout << "PreBest: " << bestMoves << " newBest: " << sum << " movements: ";
            bestMoves = sum;
            /**for(int i=0;i<ARRAY_SIZE;i++){
                cout << isMoved[i];
            }
            cout << endl;*/
        }
        return;
    }

    ///move this
    isMoved[index] = true;
    moveCout++;

    findResult(index + 1, moveCout, isMoved);

    ///don't move
    isMoved[index] = false;
    moveCout--;
    findResult(index + 1, moveCout, isMoved);


}
int main(){
    vector<int> result;
    int s,caseCount = 0;
    while(cin >> s){
        if(s == -1){
            for(int i=0;i<result.size();i++){
                cout << "Case " << (i + 1) << ": " << result[i] << endl;
            }
            continue;
        }
        constructor();
        queenPositions[0] = s;
        for(int i=1;i<ARRAY_SIZE;i++){
            cin >> queenPositions[i];
        }
        bool isMoved[ARRAY_SIZE];
        findResult(0, 0, isMoved);


        caseCount++;
        cout << "Case " << caseCount << ": " << bestMoves << endl;
        result.push_back(bestMoves);
        if(caseCount > 1000){
            break;
        }
    }
}

