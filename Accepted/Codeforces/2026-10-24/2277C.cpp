#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MAXN = 5e5 + 7;
int n, m;
vector<int> adj[MAXN];
vector<int> dis(MAXN);

void dfs(int x, int fa) {
    if (x == 1) return;
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dis[son] = dis[x] + 1;
        dfs(son, x);
    }
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dis[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dis[n] = 0;
    dfs(n, 0);
    // for (int i = 1; i <= n; i++) cout << dis[i] << " \n"[i == n];
    int ans = dis[1];
    for (int i = 1; i <= m; i++) {
        int x;cin >> x;
        // cout << dis[x] << ' ';
        ans = max(ans, dis[x] + 1);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
