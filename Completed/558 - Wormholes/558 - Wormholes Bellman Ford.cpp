// UVa 558 - Wormholes
// Bellman-Ford to detect negative cycles

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct e {
	int a, b, c;
};

int main() {
	int t;
	for (cin >> t; t; t--) {
		int n, m;
		cin >> n >> m;
		e edge[2000];
		for (int i = 0; i < m; i++)
			cin >> edge[i].a >> edge[i].b >> edge[i].c;
		int dist[1000];
		memset(dist, 127, sizeof(dist));
		int oo = dist[0];
		dist[0] = 0;
		// relax edges
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int a = edge[j].a;
				int b = edge[j].b;
				int c = edge[j].c;
				if (dist[a] != oo && dist[a] + c < dist[b])
					dist[b] = dist[a] + c;
			}
		}
		bool sol = false;
		// detect negative cycles
		for (int j = 0; j < m; j++) {
			int a = edge[j].a;
			int b = edge[j].b;
			int c = edge[j].c;
			if (dist[a] != oo && dist[a] + c < dist[b]) {
				sol = true;
				break;
			}
		}
		if (sol)
			cout << "possible\n";
		else
			cout << "not possible\n";
	}
	return 0;
}
