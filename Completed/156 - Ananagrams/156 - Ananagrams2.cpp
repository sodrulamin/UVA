// UVa 156 - Ananagrams

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	string word[1000], id[1000], st;
	map<string, int> count;
	int n = 0;
	cin >> st;
	while (st[0] != '#') {
		word[n] = st;
		for (int i = 0; i < st.length(); i++)
			if (st[i] >= 'a')
				st[i] = st[i] - 'a' + 'A';
		sort(st.begin(), st.end());
		id[n] = st;
		count[id[n]]++;
		n++;
		cin >> st;
	}

	string sol[1000];
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (count[id[i]] == 1)
			sol[s++] = word[i];
	}
	sort(sol, sol + s);
	for (int i = 0; i < s; i++)
		cout << sol[i] << endl;

	return 0;
}
