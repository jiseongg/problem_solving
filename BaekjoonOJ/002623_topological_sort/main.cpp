#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[1000];
int indegree[1000];

int main()
{
    queue<int> q;
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    vector<int> res;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int num;
        int prev = -1, next;
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> next;
            if (prev != -1) {
                indegree[next - 1]++;
                v[prev].push_back(next - 1);
            }
            prev = next - 1;
        }
    }

    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        res.push_back(front);
        for(int dst : v[front]) {
            indegree[dst]--;
            if(indegree[dst] == 0) {
                q.push(dst);
            }
        }
    }

    if ((int) res.size() != N) {
        cout << 0;
    } else {
        for (int el : res) {
            cout << el + 1 << '\n';
        }
    }

    return 0;
}