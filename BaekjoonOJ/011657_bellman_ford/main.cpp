#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2000000000

int dist[500];
vector<pair<int, int>> v[500];

int main()
{
	int N, M;
	cin >> N >> M;

	for(int i = 0; i < N; i++)
		dist[i] = INF;

	for(int i = 0; i < M; i++) {
		int src, dst, w;
		cin >> src >> dst >> w;
		v[src - 1].push_back(make_pair(dst - 1, w));
	}

	dist[0] = 0;
	for(int k = 0; k < N - 1; k++) {
		for(int _src = 0; _src < N; _src++) {
			for(auto [_dst, _w] : v[_src]) {
				dist[_dst] = min(dist[_dst], dist[_src] + _w);
			}
		}
	}

	int check = 0;
	for(int _src = 0; _src < N; _src++) {
		for(auto [_dst, _w] : v[_src]) {
			if(dist[_dst] > dist[_src] + _w) {
				check = 1;
				break;
			}
		}
	}

	if(check) {
		cout << -1 << '\n';
	} else {
		for(int i = 1; i < N; i++) {
			cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
		}
	}

	return 0;
}


