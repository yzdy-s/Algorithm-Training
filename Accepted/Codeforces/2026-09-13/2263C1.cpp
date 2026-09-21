#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


class SegmentTree {
private:
    int n;
    int MOD;
    vector<int> tree_sum;
    vector<int> tree_max;
    vector<int> lazy;

    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree_sum[p] = arr[l] % MOD;
            tree_max[p] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * p, l, mid, arr);
        build(2 * p + 1, mid + 1, r, arr);
        
        tree_sum[p] = (tree_sum[2 * p] + tree_sum[2 * p + 1]) % MOD;
        tree_max[p] = max(tree_max[2 * p], tree_max[2 * p + 1]);
    }

    void pushdown(int p, int l, int r) {
        if (lazy[p] == 0) return;
        
        int mid = (l + r) >> 1;
        int val = lazy[p];

        lazy[2 * p] += val;
        lazy[2 * p + 1] += val;
        
        tree_max[2 * p] += val;
        tree_max[2 * p + 1] += val;
        
        tree_sum[2 * p] = (tree_sum[2 * p] + (mid - l + 1) * (val % MOD)) % MOD;
        tree_sum[2 * p + 1] = (tree_sum[2 * p + 1] + (r - mid) * (val % MOD)) % MOD;
        
        lazy[p] = 0;
    }

    void change(int p, int l, int r, int x, int y, int num) {
        if (x <= l && r <= y) {
            tree_max[p] += num;
            tree_sum[p] = (tree_sum[p] + (r - l + 1) * (num % MOD)) % MOD;
            lazy[p] += num;
            return;
        }
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        if (x <= mid) change(2 * p, l, mid, x, y, num);
        if (y >= mid + 1) change(2 * p + 1, mid + 1, r, x, y, num);
        
        tree_max[p] = max(tree_max[2 * p], tree_max[2 * p + 1]);
        tree_sum[p] = (tree_sum[2 * p] + tree_sum[2 * p + 1]) % MOD;
    }

    int calc_sum(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree_sum[p];
        pushdown(p, l, r);
        
        int res = 0;
        int mid = (l + r) >> 1;
        if (x <= mid) res = (res + calc_sum(2 * p, l, mid, x, y)) % MOD;
        if (y >= mid + 1) res = (res + calc_sum(2 * p + 1, mid + 1, r, x, y)) % MOD;
        return res;
    }

    int calc_max(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree_max[p];
        pushdown(p, l, r);
        
        int res = -LNF; 
        int mid = (l + r) >> 1;
        if (x <= mid) res = max(res, calc_max(2 * p, l, mid, x, y));
        if (y >= mid + 1) res = max(res, calc_max(2 * p + 1, mid + 1, r, x, y));
        return res;
    }

    int query_first(int p, int l, int r, int x, int y, int val) {
        if (l > y || r < x || tree_max[p] < val) return -1;
        if (l == r) return l;
        
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        
        int res = query_first(2 * p, l, mid, x, y, val);
        if (res == -1) res = query_first(2 * p + 1, mid + 1, r, x, y, val);
        return res;
    }

public:
    SegmentTree(int size, int mod = 1e18) {
        n = size;
        MOD = mod;
        tree_sum.assign(4 * n + 7, 0);
        tree_max.assign(4 * n + 7, -LNF);
        lazy.assign(4 * n + 7, 0);
    }

    void init(const vector<int>& arr) {
        build(1, 1, n, arr);
    }

    void update(int x, int y, int num) {
        if (x > y) return;
        change(1, 1, n, x, y, num);
    }

    int query_sum(int x, int y) {
        if (x > y) return 0;
        return calc_sum(1, 1, n, x, y);
    }

    int query_max(int x, int y) {
        if (x > y) return -LNF;
        return calc_max(1, 1, n, x, y);
    }

    int find_first(int x, int y, int val) {
        if (x > y) return -1;
        return query_first(1, 1, n, x, y, val);
    }
};

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    SegmentTree st(n + 1);
    vector<int> _(n + 1, 1);
    st.init(_);
    for (int k = 1; k <= n; k++) {
        int l = max(1ll, arr[k] * k);
        int r = min((arr[k] + 1) * k - 1, n - 1);
        st.update(l, r, -1);
    }
    vector<int> ans;
    if (arr[1] != 0) ans.push_back(0);
    for (int i = 1; i < n; i++) {
        if (st.query_sum(i, i) > 0) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (auto &i : ans) cout << i << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
