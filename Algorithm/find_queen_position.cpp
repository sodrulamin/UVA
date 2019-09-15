#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > resultSet;

bool isAttaking(int index, int queenPositions[]){
    int r1 = queenPositions[index], c1 = index + 1;

    for(int i = 0;i<8; i++){
        if(i == index )
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

void moveRecursive(int index,int queenPositions[]){
    if(index > 8){
        return;
    }
    if(index == 8){
        for(int i=0;i<8;i++){
            if(isAttaking(i,queenPositions))
                return;
        }
        vector<int> positions;
        for(int i=0;i<8;i++){
            positions.push_back(queenPositions[i]);
        }
        resultSet.push_back(positions);
        return;
    }
    for(int i=1;i<=8;i++){
        queenPositions[index] = i;
        moveRecursive(index + 1, queenPositions);
    }
}


void findPositions(){
    int queenPositions[8];
    moveRecursive(0,queenPositions);
}

int main(){
    findPositions();
    cout << "Total solutions found: " << resultSet.size() <<endl;
    cout << "int resultSet[92][8] = {\n";
    for(int i=0;i<resultSet.size();i++){
        vector<int> result = resultSet[i];
        cout << "\t{";
        for(int i=0;i<result.size();i++){
            if(i == result.size() - 1){
                cout << result[i] << "}, \n";
            }else{

                cout << result[i] << ", ";
            }
        }

    }
    cout << "};" << endl;

}
