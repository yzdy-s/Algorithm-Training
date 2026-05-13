#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e5 + 7;

vector<int> tree(4 * maxN, 2);
vector<int> lazy(4 * maxN);

void pushdown(int p, int l, int r) {
    lazy[2*p] = lazy[p];
    lazy[2*p + 1] = lazy[p];
    lazy[p] = 0;

    tree[2*p] = lazy[2*p];
    tree[2*p + 1] = lazy[2*p + 1];
}

// 区间推平为 (1 << k)
void change(int p, int l, int r, int x, int y, int k) {
    if (x <= l && r <= y) {
        lazy[p] = 1LL << k;
        tree[p] = 1LL << k;
        return;
    }
    if (lazy[p]) pushdown(p, l, r);
    int mid = l + r >> 1;
    if (x <= mid) change(2*p, l, mid, x, y, k);
    if (y > mid) change(2*p+1, mid+1, r, x, y, k);
    tree[p] = (tree[2*p] | tree[2*p+1]);
}

int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p];
    int mid = l + r >> 1;
    int res = 0;
    if (lazy[p]) pushdown(p, l, r);
    if (x <= mid) res |= query(2*p, l, mid, x, y);
    if (y >  mid) res |= query(2*p+1, mid+1, r, x, y);
    return res;
}

void solve(){
    int n, m, q;cin >> n >> m >> q;
    while (q--) {
        char op;cin >> op;
        if (op == 'C') {
            int l, r, k;cin >> l >> r >> k;
            if (l > r) swap(l, r);
            change(1, 1, n, l, r, k);
        } else {
            int l, r;cin >> l >> r;
            if (l > r) swap(l, r);
            int res = query(1, 1, n, l, r);
            cout << __popcount((unsigned int)res) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
