
#include <bits/stdc++.h>

using namespace std;

struct node {
	int valid;
	int child[10];
	node () {
		valid = -1;
		memset(child, -1, sizeof(child));
	}
};

vector<node> trie;

int init()
{
	node x;
	trie.push_back(x);
	return (int)trie.size() - 1;
}

int add(int n, string &s, int i, int res)
{
	if (i == s.length()) {
		for (int i = 0; i < 10; i++) {
			if (trie[n].child[i] != -1) {
				res = 1;
			}
		}
		trie[n].valid = 1;
		return res;
	}


	int c = s[i] - '0';
	if (trie[n].child[c] == -1) {
		int next = init();
		trie[n].child[c] = next;
	}
	
	if (trie[n].valid == 1) {
		res = 1;
	}
	return add(trie[n].child[c], s, i + 1, res);
}

int main()
{
	int t, n;
	string str;
	cin >> t;

	for(int i = 0; i < t; i++) {
		trie.clear();
		init();

		int res;

		cin >> n;

		res = 0;
		for(int j = 0; j < n; j++) {
			cin >> str;

			res = add(0, str, 0, res);
		}

		if (res == 1) {
			cout << "NO" << '\n';
		} else {
			cout << "YES" << '\n';
		}

	}

	return 0;
}





			




