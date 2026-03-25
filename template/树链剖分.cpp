#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

// 给出的线段树为 区间加，维护区间和
class HLD {
public:
    const int MOD = 1e9 + 7;
    int n, root, tim;
    vector<vector<int>> adj;
    // 树剖基础数组
    vector<int> fa, siz, zSon, dep, dfn, top, id;
    // 权值数组：arr 存原节点权值，val 存 DFS 序对应的权值
    // vector<int> arr, val;
    // 线段树数组
    vector<int> tree, lazy;

    #define ls(x) ((x) << 1)
    #define rs(x) ((x) << 1 | 1)

    // ================== 树链剖分 DFS ==================
    void dfs_heavy(int x, int f, int h) {
        dep[x] = h; fa[x] = f; siz[x] = 1;
        for (auto &son : adj[x]) {
            if (son == f) continue;
            dfs_heavy(son, x, h + 1);
            if (!zSon[x] || siz[zSon[x]] < siz[son]) zSon[x] = son;
            siz[x] += siz[son];
        }
    }

    void dfs_order(int x, int f) {
        dfn[x] = ++tim;
        // val[tim] = arr[x]; // 将原权值映射到 DFS 序上
        id[tim] = x;       // dfn 对应的原数组的位置

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

    // ================== 线段树维护区间 ==================
    void pushup(int p) {
        tree[p] = (tree[ls(p)] + tree[rs(p)]) % MOD;
    }

    void pushdown(int p, int l, int r) {
        if (lazy[p]) {
            int mid = (l + r) >> 1;
            lazy[ls(p)] = (lazy[ls(p)] + lazy[p]) % MOD;
            lazy[rs(p)] = (lazy[rs(p)] + lazy[p]) % MOD;
            tree[ls(p)] = (tree[ls(p)] + (mid - l + 1) % MOD * lazy[p]) % MOD;
            tree[rs(p)] = (tree[rs(p)] + (r - mid) % MOD * lazy[p]) % MOD;
            lazy[p] = 0;
        }
    }

    void build_seg(int p, int l, int r) {
        if (l == r) {
            // tree[p] = val[l] % MOD;
            return;
        }
        int mid = (l + r) >> 1;
        build_seg(ls(p), l, mid);
        build_seg(rs(p), mid + 1, r);
        pushup(p);
    }

    void update_seg(int p, int l, int r, int x, int y, int add) {
        if (x <= l && r <= y) {
            lazy[p] = (lazy[p] + add) % MOD;
            tree[p] = (tree[p] + (r - l + 1) % MOD * add) % MOD;
            return;
        }
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        if (x <= mid) update_seg(ls(p), l, mid, x, y, add);
        if (y > mid)  update_seg(rs(p), mid + 1, r, x, y, add);
        pushup(p);
    }

    int query_seg(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree[p];
        pushdown(p, l, r);
        int res = 0;
        int mid = (l + r) >> 1;
        if (x <= mid) res = (res + query_seg(ls(p), l, mid, x, y)) % MOD;
        if (y > mid)  res = (res + query_seg(rs(p), mid + 1, r, x, y)) % MOD;
        return res;
    }

    HLD(int _n) : n(_n) {
        tim = 0;
        adj.assign(n + 1, vector<int>());
        fa.assign(n + 1, 0); siz.assign(n + 1, 0); zSon.assign(n + 1, 0);
        dep.assign(n + 1, 0); dfn.assign(n + 1, 0); top.assign(n + 1, 0); id.assign(n + 1, 0);
        // arr.assign(n + 1, 0); val.assign(n + 1, 0);
        tree.assign(4 * n + 4, 0); lazy.assign(4 * n + 4, 0);
    }

    // 外部一键建树接口
    void build(int _root, const vector<vector<int>>& _adj) {
        root = _root;
        adj = _adj;
        // arr = _arr;
        
        dfs_heavy(root, 0, 1);
        top[root] = root;
        dfs_order(root, 0);
        // build_seg(1, 1, n);
    }

    // ================== 路径与子树操作 ==================
    void update_path(int x, int y, int add) {
        add %= MOD;
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            update_seg(1, 1, n, dfn[top[x]], dfn[x], add);
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        update_seg(1, 1, n, dfn[x], dfn[y], add);
    }

    int query_path(int x, int y) {
        int res = 0;
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            res = (res + query_seg(1, 1, n, dfn[top[x]], dfn[x])) % MOD;
            x = fa[top[x]];
        }
        if (dep[x] > dep[y]) swap(x, y);
        res = (res + query_seg(1, 1, n, dfn[x], dfn[y])) % MOD;
        return res;
    }

    void update_subtree(int x, int add) {
        add %= MOD;
        update_seg(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, add);
    }

    int query_subtree(int x) {
        return query_seg(1, 1, n, dfn[x], dfn[x] + siz[x] - 1);
    }

    // LCA
    int get_lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] < dep[top[y]]) swap(x, y);
            x = fa[top[x]];
        }
        return (dep[x] < dep[y] ? x : y);
    }

    // K 级祖先
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
};

#define ui unsigned int
ui s;

inline ui get(ui x) {
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return s = x; 
}

void solve() {
    int n, q;cin >> n >> q >> s;

    int root = 1;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        int u;cin >> u;
        if (!u) root = i;
        else adj[u].push_back(i);
    }
    HLD hld(n);
    hld.build(root, adj);

    int ans = 0;
    int res = 0;
    for (int i = 1; i <= q; i++) {
        int x = (get(s) ^ ans) % n + 1;
        int k = (get(s) ^ ans) % hld.dep[x];
        ans = hld.k_root(x, k);
        res ^= (i * ans);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;// cin >> T;
    while (T--) solve();
}