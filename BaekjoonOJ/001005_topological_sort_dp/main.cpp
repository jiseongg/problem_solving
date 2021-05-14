#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[1000];
int indegree[1000];
int cost[1000];
int time[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    queue<int> q;   
    vector<int> res;
    
    int T, N, K, D, X, Y;
 
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;
        
        for (int n = 0; n < N; n++) {
            cin >> D;
            time[n] = D;
        }
        
        for (int k = 0; k < K; k++) {
            cin >> X >> Y;
            indegree[Y - 1]++;
            v[X - 1].push_back(Y - 1);
        }
    }

    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
						cost[i] = time[i];
        }
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        res.push_back(front);
        for(int dst : v[front]) {
						cost[dst] = time[dst] + cost[front];
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
