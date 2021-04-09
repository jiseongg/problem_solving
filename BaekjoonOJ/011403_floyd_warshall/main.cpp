#include <iostream>
#include <algorithm>

#define INF 30000

using namespace std;

int d[100][100];

int main()
{
	int value;
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> value;
			d[i][j] = value ? 1 : INF;
		}
	}


	for(int k = 0; k < N; k++) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(d[i][j] != 0 && d[i][j] != INF) {
				value = 1;
			} else {
				value = 0;
			}
			cout << value << ' ';
		}
		cout << '\n';
	}

	return 0;
}
	
