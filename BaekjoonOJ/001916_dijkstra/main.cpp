#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147483647

int dist[1000];
int chk[1000];
vector<pair<int, int>> v[1000];

int main()
{
	int M, N;
	int src, dst, cost;

	cin >> N >> M;

	for(int i = 0; i < N; i++) {
		dist[i] = INF;
	}

	for(int i = 0; i < M; i++) {
		int _src, _dst, _cost;
		cin >> _src >> _dst >> _cost;
		v[_src - 1].push_back(make_pair(_dst - 1, _cost));
	}

	priority_queue<pair<int, int>,
		vector<pair<int, int>>, greater<pair<int, int>>> dist_src;

	cin >> src >> dst;

	dist[src - 1] = 0;
	dist_src.push({0, src - 1});

	while(!dist_src.empty()) {
		int _src_idx = dist_src.top().second;
		dist_src.pop();

		if(!chk[_src_idx]) {
			for(auto next : v[_src_idx]) {
				int _dst_idx = next.first;
				int _cost = next.second;
				dist[_dst_idx] = min(dist[_dst_idx], dist[_src_idx] + _cost);
				dist_src.push(make_pair(dist[_dst_idx], _dst_idx));
			}
			chk[_src_idx] = 1;
		} else {
			continue;
		}
	}

	cout << dist[dst - 1] << '\n';

	return 0;
}
