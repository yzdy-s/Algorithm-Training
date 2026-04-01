// 区间第k小板子
// 若要求第k大则  k = len - k + 1;
// 主席树需要开40倍maxN所以要注意longlong爆内存问题
// 实际上是开了n个版本的权值线段树，问[l, r]区间就是在[l, r]版本之间的线段树二分

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, q, x, tot = 0;
const int maxN = 2e5 + 7;
int sum[maxN << 5] = {0}, lc[maxN << 5] = {0}, rc[maxN << 5] = {0};
int root[maxN], a[maxN], b[maxN];

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

int query(int u, int v, int l, int r, int k) {
    if (l == r) return l;
    int x = sum[lc[v]] - sum[lc[u]];
    int mid = l + r >> 1;
    if (x >= k) return query(lc[u], lc[v], l, mid, k);
    else return query(rc[u], rc[v], mid+1, r, k - x);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1, b+1+n);
    int siz = unique(b+1, b+n+1) - b - 1;

    for (int i = 1; i <= n; i++) {
        int x = lower_bound(b+1, b+siz+1, a[i]) - b;
        root[i] = modify(root[i - 1], 1, siz, x);
    }

    while (q--) {
        int l, r, k;cin >> l >> r >> k;
        int res = query(root[l - 1], root[r], 1, siz, k);
        cout << b[res] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}