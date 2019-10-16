#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getSum(int num,int *sumSingle, int *sumDouble)
{
    for(int i=0;i<2;i++){
        int single = num % 10;
        *sumSingle += single;
        num /= 10;
        int doub = (num % 10) * 2;
        while(doub)
        {
            *sumDouble += (doub % 10);
            doub /= 10;
        }
        num /= 10;
    }
}

int main()
{
    int t;
    cin >> t;
    //vector<bool> resultSet;
    while(t > 0)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;

        int sumSingle = 0,sumDouble = 0;
        getSum(a,&sumSingle,&sumDouble);
        getSum(b,&sumSingle,&sumDouble);
        getSum(c,&sumSingle,&sumDouble);
        getSum(d,&sumSingle,&sumDouble);

        if((sumSingle + sumDouble) % 10 == 0){
            cout << "Valid" << endl;
            //resultSet.push_back(true);
        }
        else{
            //resultSet.push_back(false);
            cout << "Invalid" << endl;
        }

        t--;
    }
//    for(int i=0;i<resultSet.size();i++)
//    {
//        if(resultSet[i]){
//            cout << "Valid" << endl;
//        }
//        else{
//            cout << "Invalid" << endl;
//        }
//    }
    return 0;
}
