#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_V 10000
#define MAX_E 100000

int parent[MAX_V];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x != y) parent[x] = y;
}

class edge {
	public:
		int u, v, c;
		bool operator < (const edge &others) const {
			return c < others.c;
		}
};

edge edges[MAX_E];

int main()
{
	int V, E;
	int sum = 0;

	cin >> V >> E;

	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].c;
	}

	sort(edges, edges + E);

	for (int i = 0; i < E; i++) {
		if (find(edges[i].u) != find(edges[i].v)) {
			sum += edges[i].c;
			merge(edges[i].u, edges[i].v);
		}
	}

	cout << sum;

	return 0;
}
