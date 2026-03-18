#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
set<PII> k;
vector<int> adj[maxN];
vector<int> vis(maxN);
vector<int> fa(maxN);
set<int> out;
map<int, int> cnt;

int find(int x) {
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

// st == 1 全是出度
void dfs(int x, int fa, int st) {
    if (vis[x]) return;
    vis[x] = 1;
    for (auto son : adj[x]) {
        if (son == fa) continue;
        PII edg = {x, son}, invaild = {son, x};
        if (!st) swap(edg, invaild);
        // cout << edg.first << ' ' << edg.second << endl;
        if (k.find(invaild) != k.end()) {
            cnt[find(x)] = 0;
            // cout << "@@@@@";
        }
        k.insert(edg);
    }

    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x, 1 - st);
    }

    if (st) out.insert(x);
}


void solve(){
    k.clear();
    cnt.clear();
    int n, m;cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) vis[i] = 0;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        if (u > v) swap(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        int u_fa = find(u);
        int v_fa = find(v);
        if (u_fa != v_fa) {
            fa[u_fa] = v_fa;
        }
    }

    for (int i = 1; i <= n; i++) {
        cnt[find(i)]++;
    }

    set<int> root;
    for (int i = 1; i <= n; i++) {
        root.insert(find(i));
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        out.clear();
        dfs(i, 0, 0);
        if (cnt[find(i)]) res += max(out.size(), cnt[find(i)] - out.size());
    }

    cout << res << endl;
    // for (auto &[e, st] : kkk) cout << st << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
