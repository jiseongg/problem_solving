
#include <iostream>

using namespace std;

int array[2187][2187];
int result[3];

void solve(int x, int y, int n) {
	if (n == 1) {
		int value = array[x][y];
		result[value + 1]++;
		return;
	}

	int q = n / 3;
  
	bool ok = 1;
	for(int i = x; i < x + n; i++) {
		for(int j = y; j < y + n; j++) {
			if(array[i][j] != array[x][y]) {
				ok = 0;
			}
		}
	}

	if(ok == 1) {
		result[array[x][y] + 1]++;
		return;
	}


	for(int _x = x; _x < x + n; _x += q) {
		for(int _y = y; _y < y + n; _y += q) {
			solve(_x, _y, q);
		}
	}
}

int main() {

	int N;
	int i, j;
	cin >> N;

	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			cin >> array[i][j];
		}
	}

	solve(0, 0, N);

	for(i = 0; i < 3; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}
