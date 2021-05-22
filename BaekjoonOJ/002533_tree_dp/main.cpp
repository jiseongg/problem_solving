
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[1000000][2];

vector<int> v[1000000];

void solve(int n, int parent = -1) {
    if(parent != -1 && v[n].size() == 1) {
        d[n][0] = 0;
        d[n][1] = 1;
        return;
    }
    for(int child : v[n]) {
        if (child == parent)
            continue;
        
        solve(child, n);
        d[n][0] += d[child][1];
        d[n][1] += min(d[child][0], d[child][1]);
    }
    d[n][1]++;
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
    }
    solve(0);
    cout << min(d[0][0], d[0][1]) << n;
    
    return 0;
}
