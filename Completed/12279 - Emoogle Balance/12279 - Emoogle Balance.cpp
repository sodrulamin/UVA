#include <iostream>

using namespace std;

int main(){
    int n = 1,caseCount = 0;
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        int balance = 0,num;
        for(int i=0;i<n;i++){
            cin >> num;
            if(num == 0)
                balance--;
            else
                balance++;
        }
        caseCount++;
        cout << "Case " << caseCount << ": " << balance << endl;
    }
    return 0;
}
