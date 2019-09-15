#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;

#define oo INT_MAX

int main() {

	int l;
	cin >> l;
	while (l) {
		int n, cut[51], T[51][51];
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> cut[i];
		cut[0] = 0;
		cut[++n] = l;

		for (int j = 1; j <= n; j++)
			for (int i = j - 1; i >= 0; i--) {
				if (i + 1 == j){
					T[i][j] = 0;
					//cout << "i: " << i << " j: " << j << " T[i][j]: " << T[i][j] << endl;
				}
				else {
					T[i][j] = oo;
					for (int k = i + 1; k < j; k++) {
						if (T[i][k] + T[k][j] < T[i][j])
							T[i][j] = T[i][k] + T[k][j];
                        //cout << "i: " << i << " k: " << k << " j: " << j << " T[i][k]: " << T[i][k] << " T[k][j]: " << T[k][j] << endl;
					}
					T[i][j] += cut[j] - cut[i];
					//cout << "i: " << i << " j: " << j << " T[i][j]: " << T[i][j] << " cut[j]: " << cut[j] << " cut[i]: " << cut[i] << endl;
				}
			}
		cout << "The minimum cutting is " << T[0][n] << "." << endl;

		cin >> l;
	}

	return 0;
}
