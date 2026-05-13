#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e5 + 7;
vector<int> arr(maxN);
vector<int> tree(4 * maxN);

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    tree[p] = min(tree[2*p], tree[2*p+1]);
}


int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p];
    int mid = l + r >> 1;
    int res = LNF;
    if (x <= mid) res = min(res, query(2*p, l, mid, x, y));
    if (y > mid) res = min(res, query(2*p+1, mid+1, r, x, y));
    return res;
}

void solve(){
    int n, q;cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        int l, r;cin >> l >> r;
        cout << query(1, 1, n, l, r) << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
