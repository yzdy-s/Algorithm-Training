#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e6 + 7;
vector<int> col(4 * maxN), sum(4 * maxN);
vector<int> ans(maxN), arr(maxN);

void build(int p, int l, int r) {
    sum[p] = 0;
    if (l == r) {
        col[p] = arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    if (col[2*p] == col[2*p+1]) col[p] = col[2*p];
    else col[p] = -1;
}

void pushdown(int p, int l, int r) {
    int mid = l + r >> 1;
    if (col[p] != -1) {
        ans[col[p]] += sum[p] * (r - l + 1);
        col[2*p] = col[p];
        col[2*p+1] = col[p];
        return;
    }

    if (sum[p] == 0) return;

    sum[2*p] += sum[p];
    sum[2*p+1] += sum[p];
    sum[p] = 0;
    if (col[2*p] != -1) {
        ans[col[2*p]] += sum[2*p] * (mid - l + 1);
        sum[2*p] = 0;
    }
    if (col[2*p+1] != -1) {
        ans[col[2*p+1]] += sum[2*p+1] * (r - mid);
        sum[2*p+1] = 0;
    }
}

void clear(int p, int l, int r) {
    if (col[p] != -1) return;
    pushdown(p, l, r);
    if (l == r) return;
    int mid = (l + r) >> 1;
    clear(2*p, l, mid);
    clear(2*p+1, mid+1, r);
}

void bull(int p, int l, int r, int x, int y, int k) {
    if (col[p] == k) return;
    if (x <= l && r <= y) {
        if (col[p] == -1) clear(p, l, r);
        col[p] = k;
        sum[p] = 0;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if (x <= mid) bull(2*p, l, mid, x, y, k);
    if (y > mid) bull(2*p+1, mid+1, r, x, y, k);

    if (col[2*p] == col[2*p+1]) col[p] = col[2*p];
    else col[p] = -1;
}

void add(int p, int l, int r, int x, int y, int k) {
    if (col[p] != -1) {
        int L = max(x, l);
        int R = min(y, r);
        int len = R - L + 1;
        if (len > 0) ans[col[p]] += len * k;
        return;
    }

    if (x <= l && r <= y) {
        sum[p] += k;
        return;
    }
    
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if (x <= mid) add(2*p, l, mid, x, y, k);
    if (y > mid) add(2*p+1, mid+1, r, x, y, k);

    if (col[2*p] == col[2*p+1]) col[p] = col[2*p];
    else col[p] = -1;
}

void solve(){
    int n, m, q;cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) ans[i] = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        int op;cin >> op;
        int l, r, x;cin >> l >> r >> x;
        if (op == 1) {
            bull(1, 1, n, l, r, x);
        } else {
            add(1, 1, n, l, r, x);
        }
    }

    // for (int i = 1; i <= n; i++) add(1, 1, n, i, i, 0);
    // for (int i = 1; i <= 4*n; i++) cout << sum[i] << " \n"[i == 4*n];
    clear(1, 1, n);
    for (int i = 1; i <= m; i++) cout << ans[i] << " \n"[i == m];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
