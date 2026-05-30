#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 998244353;
int n, m;
const int maxN = 1e5 + 7;
vector<int> arr(maxN + 7);
vector<int> tree(4*maxN + 7);
vector<int> lazy(4*maxN + 7);

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    tree[p] = (tree[2*p] + tree[2*p+1]) % MOD;
}

void pushdown(int p, int l, int r) {
    int mid = (l + r) / 2;
    lazy[2 * p] += lazy[p];
    lazy[2 * p + 1] += lazy[p];
    
    tree[2 * p] += (mid - l + 1) * lazy[p];
    tree[2 * p + 1] += (r - (mid + 1) + 1) * lazy[p];

    lazy[2 * p] %= MOD;
    lazy[2 * p + 1] %= MOD;
    tree[2 * p] %= MOD;
    tree[2 * p + 1] %= MOD;

    lazy[p] = 0;
}

void change(int p, int l, int r, int x, int y, int num) {
    if (x<=l && r<=y) {
        tree[p] += (r - l + 1) * num;
        lazy[p] += num;
        return;
    }

    if (lazy[p] != 0) {
        pushdown(p, l, r);
    }
    int mid = (l + r) / 2;
    if (x <= mid) {
        change(2*p, l, mid, x, y, num);
    }

    if (y >= (mid+1)) {
        change(2*p+1, mid+1, r, x, y, num);
    }
    tree[p] = (tree[2*p] + tree[2*p + 1]) % MOD;
}

int calc(int p, int l, int r, int x, int y) {
    if (x<=l && r<=y) return tree[p];

    if (lazy[p] != 0) pushdown(p, l, r);

    int res = 0;
    int mid = (l + r) / 2;
    if (x <= mid) res += calc(2*p, l, mid, x, y);
    if (y >= mid+1) res += calc(2*p+1, mid+1, r, x, y);
    return res % MOD;
}


void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int a = 0;
    while (m--) {
        int op, l, r;cin >> op >> l >> r;
        if (op == 1) {
            int d;cin >> d;
            change(1, 1, n, l, r, d);
        } else {
            
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}