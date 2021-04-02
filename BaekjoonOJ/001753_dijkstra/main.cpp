#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

vector<pair<int, int>> v[20000];
int dist[20000];
int chk[20000];

int main() {
	int V, E;
	int src;

	cin >> V >> E;
	cin >> src;

	for(int i = 0; i < V; i++) {
		dist[i] = INF;
	}

	for(int i = 0; i < E; i++) {
		int _src, _dst, _w;
		cin >> _src >> _dst >> _w;
		v[_src - 1].push_back(make_pair(_dst - 1, _w));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dist_src;
	dist[src - 1] = 0;
	dist_src.push({0, src - 1});

	while(!dist_src.empty()) {
		int _src_idx = dist_src.top().second;
		dist_src.pop();

		if(!chk[_src_idx]) {
			for(auto next : v[_src_idx]) {
				int _dst_idx = next.first;
				int __w = next.second;
				dist[_dst_idx] = min(dist[_dst_idx], dist[_src_idx] + __w);
				dist_src.push(make_pair(dist[_dst_idx], _dst_idx));
			}
			chk[_src_idx] = 1;
		} else {
			continue;
		}
	}

	for(int i = 0; i < V; i++) {
		if (dist[i] != INF) {
			cout << dist[i];
		} else
			cout << "INF";
		cout << '\n';
	}
	return 0;

}
