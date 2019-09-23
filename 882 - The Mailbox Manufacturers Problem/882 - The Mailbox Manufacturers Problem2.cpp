// UVa 882 - The Mailbox Manufacturers Problem

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int t, oo[1];
	memset(oo, 127, sizeof(oo));
	for (cin >> t; t; t--) {
		int n, m;
		cin >> n >> m;
		int T[11][101][101];
		memset(T, 0, sizeof(T));
		for (int i = 1; i <= m; i++) {
			int ii = (i * (i - 1)) >> 1;
			for (int j = i; j <= m; j++)
				T[1][i][j] = ((j * (j + 1)) >> 1) - ii;
		}
		for (int k = 2; k <= n; k++)
			for (int d = 0; d < m; d++)
				for (int i = 1; i + d <= m; i++) {
					int j = i + d;
					int partial = oo[0];
					for (int l = i; l <= j; l++) {
						int sub_sol = max(T[k][l + 1][j], T[k - 1][i][l - 1]) + l;
						if (sub_sol < partial)
							partial = sub_sol;
					}
					T[k][i][j] = partial;
					//cout << "Rem: " << k << " start: " << i << " end: " << j << " stick: " << partial << endl;
				}
		cout << T[n][1][m] << endl;
	}

	return 0;
}
