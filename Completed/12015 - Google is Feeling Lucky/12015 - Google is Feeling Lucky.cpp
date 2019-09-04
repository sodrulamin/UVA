#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,caseCount = 1;;
    cin >> n;
    while(n > 0){
        string str;
        int value,maxValue = -1;
        vector<string> resultSet;

        for(int i=0;i<10;i++){
            cin >> str >> value;
            if(maxValue == -1){
                maxValue = value;
                resultSet.push_back(str);
            }else if(maxValue == value){
                resultSet.push_back(str);
            }else if(maxValue < value){
                resultSet.clear();
                maxValue = value;
                resultSet.push_back(str);
            }
        }
        cout << "Case #" << caseCount << ":\n";
        for(int i=0;i<resultSet.size();i++){
            cout << resultSet[i] << endl;
        }
        n--;
        caseCount++;
    }

    return 0;
}
