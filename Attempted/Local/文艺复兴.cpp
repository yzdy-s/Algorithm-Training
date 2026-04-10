#include<bits/stdc++.h>
using namespace std;

int tim = 0;
const int maxN = 5e5 + 7;
vector<int> adj[maxN];
int arr[maxN], val[maxN];
int fa[maxN], siz[maxN], zSon[maxN], dep[maxN];
int dfn[maxN], id[maxN], top[maxN];

int tot = 0;
int sum[maxN << 5] = {0}, lc[maxN << 5] = {0}, rc[maxN << 5] = {0};
int root[maxN];



int modify(int p, int l, int r, int x) {
    int np = ++tot;
    lc[np] = lc[p]; rc[np] = rc[p];
    sum[np] = sum[p] + 1;
    if (l == r) return np;
    int mid = l + r >> 1;
    if (x <= mid) lc[np] = modify(lc[np], l, mid, x);
    else rc[np] = modify(rc[np], mid+1, r, x);
    return np;
}

// int query(int u, int v, int l, int r, int k) {
//     if (l == r) return l;
//     int x = sum[lc[v]] - sum[lc[u]];
//     int mid = l + r >> 1;
//     if (x >= k) return query(lc[u], lc[v], l, mid, k);
//     else return query(rc[u], rc[v], mid+1, r, k - x);
// }

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

void init(int n) {
    tim = 0;
    
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
        zSon[i] = 0;
        // top[i] = dfn[i] = fa[i] = dep[i] = siz[i] = arr[i] = rnk[i] = 0;
    }
}

void build(int root) {
    dfs_heavy(root, 0, 1);
    top[root] = root;
    dfs_order(root, 0);
}

int main() {
    int n, q;cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build(1);

    for (int i = 1; i <= n; i++) {
        root[i] = modify(root[i - 1], 1, n, dfn[i]);
    }

    while (q--) {
        int a, b, x;cin >> a >> b >> x;
        int A = LCA(a, b);
        int B = LCA(a, x);
        int C = LCA(b, x);
        int mx = max({dep[A], dep[B], dep[C]});
        if (mx == dep[A]) cout << A << endl;
        else if (mx == dep[B]) cout << B << endl;
        else if (mx == dep[C]) cout << C << endl;
    }
}