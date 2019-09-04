#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N,trackNo,bestDiff;
int trackLenArray[20];
vector<int> takenNumbers;

void constructor(){
    bestDiff = N;
}

void findResult3(int index,int sum,vector<int> takenNumber){
    if(index > trackNo || bestDiff == 0 || sum > N)
        return;
    else if(index == trackNo){
        //int sum = 0;
        //vector<int> takenNumber;
        //for(int i=0;i<trackNo;i++){
            //if(takenList[i]){
                //sum += trackLenArray[i];
                //takenNumber.push_back(trackLenArray[i]);
            //}
        //}
        int diff = N - sum;
        //cout << "Diff: " << diff << " bestDiff: " << bestDiff << " taken: ";
        /*for(int i=0;i<takenNumber.size();i++){
            cout << takenNumber[i] << " ";
        }
        cout << endl;*/

        if(diff >= 0 && diff < bestDiff){
            bestDiff = diff;
            takenNumbers = takenNumber;
        }
    }
    //takenList[index] = true;
    takenNumber.push_back(trackLenArray[index]);
    sum += trackLenArray[index];
    findResult3(index + 1,sum,takenNumber);
    //takenList[index] = false;
    takenNumber.pop_back();
    sum -= trackLenArray[index];
    findResult3(index + 1,sum,takenNumber);
    //takenList[index] = true;
    takenNumber.push_back(trackLenArray[index]);
    sum += trackLenArray[index];
}
int main(){

    while(cin >> N){
        cin >> trackNo;
        int sum = 0;
        for(int i=0;i<trackNo;i++){
            cin >> trackLenArray[i];
            sum += trackLenArray[i];;
        }
        constructor();
        //bool takenList[20];
        //findResult2(0,takenList);
        if(sum > N){
            vector<int> takenNumber;
            findResult3(0,0,takenNumber);
            sum = 0;
            for(int i=0;i<takenNumbers.size();i++){
                cout << takenNumbers[i] << " ";
                sum += takenNumbers[i];
            }
            cout << "sum:" << sum << endl;
        }else{
            for(int i=0;i<trackNo;i++){
                cout << trackLenArray[i] << " ";
            }
            cout << "sum:" << sum << endl;
        }
    }
}
