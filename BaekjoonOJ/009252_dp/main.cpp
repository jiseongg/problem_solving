#include <bits/stdc++.h>

using namespace std;

char s[1017], t[1017];
int d[1001][1001];
int n, m;

int go(int N, int M) {
    if (N == n + 1 || M == m + 1) {
        return 0;
    }
    
    int &ret = d[N][M];
    if (ret != -1) {
        return d[N][M];
    }
    
    ret = max(go(N + 1, M), go(N, M + 1));
    
    if (s[N] == t[M]) {
        ret = max(go(N + 1, M + 1) + 1, ret);
    }
    
    return ret;
}

void track(int N, int M) {
    if (N == n + 1 || M == m + 1) {
        return;
    }
    
    if (go(N, M) == go(N + 1, M)) {
        track(N + 1, M);
    } else if (go(N, M) == go(N, M + 1)) {
        track(N, M + 1);
    } else if (s[N] == t[M] && go(N, M) == go(N + 1, M + 1) + 1) {
        putchar(s[N]);
        track(N + 1, M + 1);
    }
    
}

int main() {
    scanf("%s%s", s + 1, t + 1);
    
    n = strlen(s + 1);
    m = strlen(t + 1);
    
    memset(d, -1, sizeof(d));
    
    cout << go(1, 1) << '\n';
    track(1, 1);
    cout << '\n';
    
    return 0;
}