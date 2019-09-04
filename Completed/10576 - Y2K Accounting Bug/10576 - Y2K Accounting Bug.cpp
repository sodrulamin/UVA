#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long s,d;
long long bestDiff;

void constructor(){
    bestDiff = -1;
}

void findResult(int index, int fiveMonthReport,bool isSurplus[]){
    if(index > 12 || (index >= 5 && fiveMonthReport >= 0)){
        return;
    }else if(index == 12){
        int sum = 0;
        for(int i=0;i<12;i++){
            if(isSurplus[i]){
                sum += s;
            }else{
                sum -= d;
            }
        }
        /**for(int i=0;i<12;i++){
            cout << "Month: " << (i + 1);
            if(isSurplus[i]){
                cout << " sur: " << s << " def: 0";
            }else {
                cout << " sur: 0 def: " << d;
            }
            cout << " report: " << fiveMonthReport << endl;
        }*/
        if(sum > bestDiff){
            bestDiff = sum;
            /**int report = 0;
            for(int i=0;i<12;i++){
                cout << "Month: " << (i + 1);
                if(isSurplus[i]){
                    cout << " sur: " << s << " def: 0";
                    report += s;
                }else {
                    cout << " sur: 0 def: " << d;
                    report -= d;
                }
                cout << " report: " << report << endl;
            }*/
        }
        return;
    }
    ///remove oldest value from five months sum
    if(index >= 5){
        if(isSurplus[index - 5]){
            ///it was surplus 5 months earlier
            fiveMonthReport -= s;
        }else{
            ///it was deficit 5 months earlier
            fiveMonthReport += d;
        }
    }

    ///surplus
    fiveMonthReport += s;
    isSurplus[index] = true;

    findResult(index + 1, fiveMonthReport, isSurplus);

    ///deficit
    fiveMonthReport = fiveMonthReport - s - d;
    isSurplus[index] = false;

    findResult(index + 1, fiveMonthReport, isSurplus);


}
int main(){
    //vector<long long> result;
    while(cin >> s >> d){
        /**if(s == 0 && d == 0){
            for(int i=0;i<result.size();i++){
                cout << result[i] << endl;
            }
            continue;
        }*/
        constructor();
        bool isSurplus[12];
        findResult(0,0,isSurplus);

        if(bestDiff < 0){
            cout << "Deficit" << endl;
            //result.push_back(-1);
        }else{
            cout << bestDiff << endl;
            //result.push_back(bestDiff);
        }
    }
}

