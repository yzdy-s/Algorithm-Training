#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector<int> arr(5e5 + 7);
vector<int> brr(5e5 + 7);
vector<int> val(2.5e7 + 7);
vector<int> sum(2.5e7 + 7);

class xorTree {
private:
    int n;
    vector<int> tree;
public:
    xorTree (int n) {
        this->n = n;
        tree.assign(4 * n + 7, 0);
        build(1, 1, n);
    }
    void build(int p, int l, int r) {
        if (l == r) {
            tree[p] = brr[l];
            return;
        }
        int mid = l + r >> 1;
        build(2*p, l, mid);
        build(2*p+1, mid+1, r);
        tree[p] = (tree[2*p] ^ tree[2*p+1]);
    }
    
    void change(int p, int l, int r, int pos) {
        if (l == r && l == pos) {
            tree[p] = brr[pos];
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid) change(2*p, l, mid, pos);
        else change(2*p+1, mid+1, r, pos);
        tree[p] = (tree[2*p] ^ tree[2*p+1]);
    }

    int calc(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree[p];
        int mid = l + r >> 1;
        int res = 0;
        if (x <= mid) res ^= calc(2*p, l, mid, x, y);
        if (y > mid) res ^= calc(2*p+1, mid+1, r, x, y);
        return res;
    }
};

class mTree {
private:
    int n;
    vector<PII> tree; // mx, mn
public:
    mTree (int n) {
        this->n = n;
        tree.assign(4 * n + 7, {-LNF, LNF});
        build(1, 1, n);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            tree[p] = {arr[l], arr[l]};
            return;
        }
        int mid = l + r >> 1;
        build(2*p, l, mid);
        build(2*p+1, mid+1, r);
        tree[p].first = max(tree[2*p].first, tree[2*p+1].first);
        tree[p].second = min(tree[2*p].second, tree[2*p+1].second);
    }

    void change(int p, int l, int r, int pos) {
        if (l == r) {
            tree[p] = {arr[l], arr[l]};
            return;
        }
        int mid = l + r >> 1;
        if (pos <= mid) change(2*p, l, mid, pos);
        else change(2*p+1, mid+1, r, pos);
        tree[p].first = max(tree[2*p].first, tree[2*p+1].first);
        tree[p].second = min(tree[2*p].second, tree[2*p+1].second);
    }

    PII calc(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree[p];
        int mid = l + r >> 1;
        PII res = {-LNF, LNF};
        if (x <= mid) {
            auto t = calc(2*p, l, mid, x, y);
            res.first = max(res.first, t.first);
            res.second = min(res.second, t.second);
        }
        if (y >= mid+1) {
            auto t = calc(2*p+1, mid+1, r, x, y);
            res.first = max(res.first, t.first);
            res.second = min(res.second, t.second);
        }
        return res;
    }
};

void pre() {
    for (int i = 1; i <= 2.5e7; i++) val[i] = rnd();
    for (int i = 1; i <= 2.5e7; i++) sum[i] = (sum[i - 1] ^ val[i]);
}

void solve(){
    int q, n;cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) brr[i] = val[arr[i]];
    xorTree xt(n);
    mTree mt(n);
    while (q--) {
        int op;cin >> op;
        if (op == 1) {
            int x, y;cin >> x >> y;
            arr[x] = y;
            brr[x] = val[arr[x]];
            xt.change(1, 1, n, x);
            mt.change(1, 1, n, x);
        } else {
            int l, r;cin >> l >> r;
            auto [mx, mn] = mt.calc(1, 1, n, l, r);
            if (mx - mn + 1 != r - l + 1) {
                cout << "yuanxing" << endl;
                continue;
            }
            int aid = (sum[mx] ^ sum[mn - 1]);
            int cur = xt.calc(1, 1, n, l, r);
            if (cur != aid) {
                cout << "yuanxing" << endl;
            } else {
                cout << "damushen" << endl;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    pre();
    int T = 1;//cin >> T;
    while (T--) solve();
}
