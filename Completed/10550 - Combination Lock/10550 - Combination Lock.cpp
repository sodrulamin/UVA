#include <iostream>

using namespace std;

int main(){
    int n,a,b,c;
    while(cin >> n >> a >> b >> c){
        if(n == 0 && a == 0 && b == 0 && c == 0)
            break;
        int result = 1080;
        n = n - a;
        if(n < 0){
            //cout << "n: " << n << " after adding: " << (n + 40) << endl;
            n += 40;
        }
        a = b - a;
        if(a < 0){
            //cout << "a: " << a << " after adding: " << (a + 40) << endl;
            a += 40;

        }
        b = b - c;
        if(b < 0){
            //cout << "b: " << b << " after adding: " << (b + 40) << endl;
            b += 40;
        }
        result = result + n * 9 + a * 9 + b * 9;
        //cout << "n: " << n << " a: " << a << " b: " << b << " result: " << result << endl;
        cout << result << endl;

    }
    return 0;
}
