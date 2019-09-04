#include <iostream>
#include <cstdio>


using namespace std;


unsigned int XOR_MUSK = 0xff;


int convertEndian(int x)
{
    int res = 0, a, b;
    for(int i = 0; i < 4; i++){
        a = x >> i * 8;
        b = a & XOR_MUSK;
        res = res << 8;
        res = res | b;
    }
    return res;
}

int main(){
    int n;
    while ( cin >> n ) {
        int result = convertEndian(n);
        cout << n << " converts to " << result << endl;
    }
    return 0;
}



