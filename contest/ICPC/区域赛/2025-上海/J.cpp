#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;

constexpr int N = 500005 << 3;

using vi = vector<int>;



void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector< array<vector<int>, 9> > adj(n+1);
    for (int i = 1; i <= m; ++i) {
        int x, y, z; cin >> x >> y >> z;
        adj[x][z].emplace_back(y);
        adj[0][z].emplace_back(y);
    }

    int idx = 0, cnt = 0;
    
    auto dfs = [&](auto &&self, vi &pool, int len) -> void {
        if (cnt == k) return;

        for (int z = 1; z <= 8; ++z) {                                           
            if (cnt == k) return;
            vi ntpool;
            for (int u : pool) {
                if (cnt == k) return;
                for (int v : adj[u][z]) {
                    if (cnt == k) return;
                    ntpool.emplace_back(v);
                    cout << len << '\n'; ++cnt;
                }
            }
            if (cnt == k) return;

            if (ntpool.size()) self(self, ntpool, len + 1);
        }
        return;
    };

    for (int z = 1; z <= 8 && cnt < k; ++z) {
        vi ntpool;
        for (int v : adj[0][z]) {
            if (cnt == k) break;
            ntpool.emplace_back(v);
            cout << "1\n"; ++cnt;
        }
        if (cnt < k) dfs(dfs, ntpool, 2);
    }

    for (int i = cnt + 1; i <= k; ++i) cout << "-1\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T = 1; // cin >> T;
    while (T--) solve();
}