
#include <iostream>

using namespace std;

int d[100][100];

#define INF 100000000

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int _src, _dst, _cost;
		cin >> _src >> _dst >> _cost;
		if (_cost < d[_src - 1][_dst - 1])
			d[_src - 1][_dst - 1] = _cost;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (d[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
