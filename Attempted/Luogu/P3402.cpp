#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
int n, q, tot = 0;
const int maxN = 1e5 + 7;
int fa[maxN << 5], dep[maxN << 5];
int lc[maxN << 5], rc[maxN << 5], root[maxN];


int build(int l, int r) {
    int np = ++tot;
    if (l == r) {
        fa[np] = l;
        dep[np] = l;
        return np;
    }
    int mid = l + r >> 1;
    lc[np] = build(l, mid);
    rc[np] = build(mid+1, r);
    return np;
}

// 
int modify(int p, int l, int r, int pos, int f) {
    int np = ++tot;
    lc[np] = lc[p]; rc[np] = rc[p]; fa[np] = fa[p]; dep[np] = dep[p];
    if (l == r) {
        fa[np] = f;
        return np;
    }
    int mid = l + r >> 1;
    if (pos <= mid) lc[np] = modify(lc[np], l, mid, pos, f);
    else rc[np] = modify(rc[np], mid + 1, r, pos, f);
    return np;
}

// 查询操作：返回的是线段树上对应的【节点编号】，方便同时获取 fa 和 dep
int query(int p, int l, int r, int pos) {
    if (l == r && l == pos) return p;
    int mid = l + r >> 1;
    if (pos <= mid) return query(lc[p], l, mid, pos);
    else return query(rc[p], mid+1, r, pos);
}

int find(int rt, int x) {
    int node = query(rt, 1, n, x);
    if (fa[node] == x) return node;
    return find(rt, fa[node]);
}

void merge(int a, int b) {

}

void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) fa[i] = i;
    root[0] = build(1, n);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        int op;cin >> op;
        if (op == 1) {
            int a, b;cin >> a >> b;
            merge(a, b);
        } else if (op == 2) {
            int k;cin >> k;
            cur = k;
        } else {
            int a, b;cin >> a >> b;
            if (isSame(a, b)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}