#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, q, x, tot = 0;
const int maxN = 1e6 + 7;;
int val[maxN << 5] = {0}, lc[maxN << 5] = {0}, rc[maxN << 5] = {0};
int root[maxN], a[maxN];

int build(int l, int r) {
    int p = ++tot;
    if (l == r) {
        val[p] = a[l];
        return p;
    }
    int mid = l + r >> 1;
    lc[p] = build(l, mid);
    rc[p] = build(mid + 1, r);
    return p;
}

int modify(int p, int l, int r, int pos, int v) {
    int np = ++tot;
    lc[np] = lc[p]; rc[np] = rc[p]; val[np] = val[p];
    if (l == r) {
        val[np] = v;
        return np;
    }
    int mid = l + r >> 1;
    if (pos <= mid) lc[np] = modify(lc[np], l, mid, pos, v);
    else rc[np] = modify(rc[np], mid+1, r, pos, v);
    return np;
}

int query(int p, int l, int r, int pos) {
    if (l == r) return val[p];
    int mid = l + r >> 1;
    if (pos <= mid) return query(lc[p], l, mid, pos);
    else return query(rc[p], mid+1, r, pos);
}

void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    root[0] = build(1, n);
    for (int i = 1; i <= q; i++) {
        int v, op;cin >> v >> op;
        if (op == 1) {
            int p, c;cin >> p >> c;
            root[i] = modify(root[v], 1, n, p, c);
        } else {
            int p;cin >> p;
            int res = query(root[v], 1, n, p);
            cout << res << endl;
            root[i] = root[v];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
