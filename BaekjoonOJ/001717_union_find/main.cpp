#include <iostream>

using namespace std;

int parent[1000001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x != y)
		parent[x] = y;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int op, a, b;

	cin >> n >> m;

	for(int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for(int i = 0; i < m; i++) {
		cin >> op >> a >> b;

		if(op == 0) {
			merge(a, b);
		} else {
			if (find(a) == find(b)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}

	}
	return 0;
}



