#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int MOD;
int tim = 0;
const int maxN = 1e5 + 7;
vector<int> adj[maxN];
int arr[maxN], val[maxN];
int fa[maxN], siz[maxN], zSon[maxN], dep[maxN];
int dfn[maxN], id[maxN], top[maxN];

void dfs_heavy(int x, int f, int h) {
    dep[x] = h; fa[x] = f; siz[x] = 1;
    for (auto &son : adj[x]) {
        if (son == f) continue;
        dfs_heavy(son, x, h+1);
        if (!zSon[x] || siz[zSon[x]] < siz[son]) zSon[x] = son;
        siz[x] += siz[son];
    }
}

void dfs_order(int x, int f) {
    dfn[x] = ++tim;
    arr[tim] = val[x];
    id[tim] = x;

    if (zSon[x]) {
        top[zSon[x]] = top[x];
        dfs_order(zSon[x], x);
    }
    for (auto &son : adj[x]) {
        if (son != f && son != zSon[x]) {
            top[son] = son;
            dfs_order(son, x);
        }
    }
}

int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}

int k_root(int x, int k) {
    if (dep[x] <= k) return 0;
    while (x) {
        int dist = dep[x] - dep[top[x]];
        if (k <= dist) {
            return id[dfn[x] - k]; 
        }
        k -= dist + 1;
        x = fa[top[x]];
    }
    return 0;
}


void solve(){
    int n, q, root;cin >> n >> q >> root >> MOD;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while (q--) {
        int op;cin >> op;
        if (op == 1) { // x 到 y 最短路径区间加 z
            int x, y, z;cin >> x >> y >> z;

        } else if (op == 2) { // 计算 x 到 y 最短路径上的区间和
            int x, y;cin >> x >> y;

        } else if (op == 3) { // 根为 x 的子树所有结点加 z
            int x, z;cin >> x >> z;

        } else { // 根为 x 的子树权值之和
            int x;cin >> x;

        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}