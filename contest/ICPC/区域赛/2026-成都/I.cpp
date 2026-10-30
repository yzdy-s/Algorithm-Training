#include<bits/stdc++.h>
using namespace std;
#define int long long


typedef long long ll;
using vi = vector<int>;
using vvi = vector<vi>;

constexpr int N = 200005;
int dfn[N], vis[N], fa[N];

void solve1() {
    int n, m; cin >> n >> m;
    vvi adj(n+1);

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    
    int idx = 1;
    auto dfs = [&](auto &&self, int u) -> void {

        bool f = 1;
        for (int v : adj[u]) {
            if (v == fa[u]) continue;
            fa[v] = u;

            if (f) {
                f = 0;
                dfn[v] = idx;
                idx += 1;
            } else {
                dfn[v] = idx;
                
            }
            
            self(self, v);
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (dfn[i]) continue;
        dfn[i] = idx++;
        dfs(dfs, i);
        idx += 2;.
    }
    for (int i = 1; i <= n; ++i) cout << dfn[i] << " \n"[i == n];
}

void solve2() {



}


signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T_ = 1; cin >> T_;
    string op; cin >> op;
    if (op[0] == 'c') {
        while (T_--) solve1();
    } else {
        while (T_--) solve2();
    }
}