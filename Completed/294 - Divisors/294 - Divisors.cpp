#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

#define maxp 31623
#define datatype unsigned long long

int main() {
	bool prime[maxp];
	memset(prime, true, sizeof(prime));
	for (int i = 4; i < maxp; i += 2)
		prime[i] = false;
	vector<int> p;
	p.push_back(2);
	for (int i = 3; i < maxp; i++)
		if (prime[i]) {
			int j = i * i;
			while (j < maxp) {
				prime[j] = false;
				j += i << 1;
			}
			p.push_back(i);
		}

	int t;
	for (cin >> t; t; t--) {
		datatype a, b;
		cin >> a >> b;
		int mx = 0;
		datatype sol;
		for (datatype n = a; n <= b; n++) {
			datatype m = n;
			int d = 1;
			for (int i = 0; i < p.size() && p[i] <= m; i++) {
				int e = 1;
				while (m % p[i] == 0) {
					m /= p[i];
					e++;
				}
				d *= e;
			}
			if (m > 1)
				d = d << 1;
			if (d > mx) {
				mx = d;
				sol = n;
			}
		}
		printf("Between %llu and %llu, %llu has a maximum of %d divisors.\n", a, b, sol, mx);
	}

}
