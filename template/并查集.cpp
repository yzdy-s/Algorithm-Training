#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

struct DSU {
    std::vector<int> fa;
    std::vector<int> sz;

    DSU(int n) {
        fa.resize(n + 1);
        sz.assign(n + 1, 1);
        std::iota(fa.begin(), fa.end(), 0); // 批量赋值 fa[i] = i
    }

    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]); 
    }

    bool merge(int u, int v) {
        int u_root = find(u);
        int v_root = find(v);

        if (u_root == v_root) return false;

        if (sz[u_root] < sz[v_root]) {
            fa[u_root] = v_root;
            sz[v_root] += sz[u_root];
        } else {
            fa[v_root] = u_root;
            sz[u_root] += sz[v_root];
        }
        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }
    
    int size(int x) {
        return sz[find(x)];
    }
};



struct PersistentDSU {
    int n, tot;
    // 线段树节点数组：记录左右儿子、当前区间的 fa 和 dep (只有叶子节点有效)
    std::vector<int> root, ls, rs, fa, dep;

    // n 为元素个数，max_ops 为最大操作/版本数
    PersistentDSU(int n, int max_ops) : n(n), tot(0) {
        int max_nodes = n * 4 + max_ops * 40; 
        root.assign(max_ops + 1, 0);
        ls.assign(max_nodes, 0);
        rs.assign(max_nodes, 0);
        fa.assign(max_nodes, 0);
        dep.assign(max_nodes, 0);
        
        // 建立初始版本 0
        root[0] = build(1, n);
    }

    // 建树
    int build(int l, int r) {
        int p = ++tot;
        if (l == r) {
            fa[p] = l;
            dep[p] = 1;
            return p;
        }
        int mid = l + (r - l) / 2;
        ls[p] = build(l, mid);
        rs[p] = build(mid + 1, r);
        return p;
    }

    // 单点修改 fa 数组，生成新节点
    int modify_fa(int pre, int l, int r, int pos, int new_fa) {
        int p = ++tot;
        ls[p] = ls[pre]; rs[p] = rs[pre]; fa[p] = fa[pre]; dep[p] = dep[pre];
        if (l == r) {
            fa[p] = new_fa;
            return p;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) ls[p] = modify_fa(ls[pre], l, mid, pos, new_fa);
        else rs[p] = modify_fa(rs[pre], mid + 1, r, pos, new_fa);
        return p;
    }

    // 单点修改 dep 数组 (深度+1)
    int add_dep(int pre, int l, int r, int pos) {
        int p = ++tot;
        ls[p] = ls[pre]; rs[p] = rs[pre]; fa[p] = fa[pre]; dep[p] = dep[pre];
        if (l == r) {
            dep[p]++;
            return p;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) ls[p] = add_dep(ls[pre], l, mid, pos);
        else rs[p] = add_dep(rs[pre], mid + 1, r, pos);
        return p;
    }

    // 单点查询，返回线段树上叶子节点的编号
    int query(int p, int l, int r, int pos) {
        if (l == r) return p;
        int mid = l + (r - l) / 2;
        if (pos <= mid) return query(ls[p], l, mid, pos);
        else return query(rs[p], mid + 1, r, pos);
    }

    int find(int ver, int x) {
        int node = query(root[ver], 1, n, x);
        if (fa[node] == x) return node;
        return find(ver, fa[node]);
    }

    int merge(int pre_ver, int u, int v) {
        int u_node = find(pre_ver, u);
        int v_node = find(pre_ver, v);
        int u_root = fa[u_node], v_root = fa[v_node];

        if (u_root == v_root) return root[pre_ver]; 

        if (dep[u_node] < dep[v_node]) {
            return modify_fa(root[pre_ver], 1, n, u_root, v_root);
        } else if (dep[u_node] > dep[v_node]) {
            return modify_fa(root[pre_ver], 1, n, v_root, u_root);
        } else {
            int temp_root = modify_fa(root[pre_ver], 1, n, u_root, v_root);
            return add_dep(temp_root, 1, n, v_root);
        }
    }

    bool same(int ver, int u, int v) {
        int u_node = find(ver, u);
        int v_node = find(ver, v);
        return fa[u_node] == fa[v_node];
    }
};


void solve(){
    int n, m;cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        int op, x, y;cin >> op >> x >> y;
        if (op == 1) dsu.merge(x, y);
        else {
            if (dsu.same(x, y)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}