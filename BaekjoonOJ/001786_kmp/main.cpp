

#include <bits/stdc++.h>

using namespace std;

int fail[1000000] = {};

int main() {

	string t, p;
	int M, N, cnt = 0;
	vector<int> res;
	
	getline(cin, t);
	getline(cin, p);

	M = p.length();
	N = t.length();


	for(int i = 1, j = 0; i < M; i++) {
		while (j > 0 && p[i] != p[j])
			j = fail[j - 1];

		if (p[i] == p[j])
			fail[i] = ++j;
	}

	for(int i = 0, j = 0; i < N; i++) {
		while(j > 0 && t[i] != p[j])
			j = fail[j - 1];

		if (t[i] == p[j]) {
			if (j == M - 1) {
				res.push_back(i - M + 1);
				j = fail[j];
				cnt++;
			} else {
				j++;
			}
		}
	}

	cout << cnt << '\n';

	for(int idx : res) {
		cout << idx + 1 << ' ';
	}


	return 0;

}
	

