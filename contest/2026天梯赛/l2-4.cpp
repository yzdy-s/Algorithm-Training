#include <bits/stdc++.h>
using namespace std;
#define int long long


struct PII {
    int nx;
    int p;
    bool operator < (PII &b) {
        if (p != b.p) return p > b.p;
        return nx < b.nx;
    }
};

const int maxN = 1e4 + 7;
vector<PII> adj[maxN];
vector<int> vis(maxN, 1e9 + 7);
int k;
void dfs(int x) {
    if (adj[x].size() == 0) return;
    for (auto &t : adj[x]) {
        if (vis[t.nx] == k) continue;
        vis[t.nx] = k;
        cout << "->";
        cout << t.nx;
        dfs(t.nx);
        return;
    }
    
}

signed main() {
    int n, m;cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, p;cin >> u >> v >> p;
        PII t;
        t.nx = v;
        t.p = p;
        adj[u].push_back(t);
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    // for (int i = 1; i <= n; i++) {
    //     for (auto &t : adj[i]) {
    //         cout << t.nx << ' ' << t.p << endl;
    //     }
    //     cout << endl << endl;
    // }

    cin >> k;
    while (k--) {
        int x;cin >> x;
        cout << x;
        vis[x] = k;
        dfs(x);
        cout << endl;
    }
}