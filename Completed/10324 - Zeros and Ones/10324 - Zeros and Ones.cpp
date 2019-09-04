#include <iostream>
#include <string>

using namespace std;

int main(){
    int caseCount = 0;
    string str;
    bool endCase = false;
    while(getline(cin,str)){
        if(str == ""){
            if(!endCase)
                break;
            else{
                endCase = false;
                continue;
            }
        }
        caseCount++;
        cout << "Case " << caseCount << ":\n";
        //resultSet.push_back(-1);
        int n;
        cin >> n;
        while(n > 0){
            endCase = true;
            int i,j;

            cin >> i >> j;
            int min = i,max = j;
            if(min > max){
                min = j;
                max = i;
            }
            if(max >= str.length())
                continue;
            bool result = true;
            for(i=min;i<max;i++){
                if(str[i] != str[i + 1]){
                    result = false;
                    break;
                }
            }
            if(result){
                cout << "Yes\n";
                //resultSet.push_back(1);
            }else{
                cout << "No\n";
                //resultSet.push_back(0);
            }
            n--;
            //getline(cin,str);
        }
        //getline(cin,str);

    }
    /*caseCount = 1;
    for(int i=0;i<resultSet.size();i++){
        if(resultSet[i] == -1){
            cout << "Case " << caseCount << ":\n";
            caseCount++;
        }else if(resultSet[i] == 1){
            cout << "Yes\n";
        }else {
            cout << "No\n";
        }
    }*/
    return 0;
}
