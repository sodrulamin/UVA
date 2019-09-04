#include <iostream>
#include<bits/stdc++.h>

using  namespace std;

int main(){
    int storePosition[100],t,n;
    cin >> t;
    while(t > 0){
        cin >> n;
        int minv = -1,maxv = -1;
        for(int i=0;i<n;i++){
            cin >> storePosition[i];
            if(minv == -1){
                minv = storePosition[i];
                maxv = storePosition[i];
            }else {
                if(storePosition[i] > maxv){
                    maxv = storePosition[i];
                }else if(storePosition[i] < minv){
                    minv = storePosition[i];
                }
            }
        }
        cout << ((maxv - minv) * 2) << endl;

        t--;
    }
    return 0;
}
