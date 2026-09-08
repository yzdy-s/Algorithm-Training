#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e6 + 7;
vector<int> a(MAXN), c(MAXN), w(MAXN);
map<int, map<int, int>> mp; // {a, {c, w}}
map<int, int> sum; // {a, sum}

vector<int> tree(4 * MAXN);
void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = w[l];
        return;
    }
    int mid = l + r >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

void change(int p, int l, int r, int pos) {
    if (l == r && l == pos) {
        tree[p] = w[pos];
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) change(2 * p, l, mid, pos);
    if (pos > mid) change(2 * p + 1, mid + 1, r, pos);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}

int calc(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p];
    
    int res = 0; 
    int mid = (l + r) >> 1;
    
    if (x <= mid) res += calc(2 * p, l, mid, x, y);
    if (y >= mid + 1) res += calc(2 * p + 1, mid + 1, r, x, y);
    return res;
}

void solve(){
    int n, q, k;cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    
    map<int, map<int, int>> mp;
    for (int i = 1; i <= n; i++) {
        if (c[i] != 0) {
            mp[a[i]][c[i]] = rnd() % INF;
        }
    }
    vector<vector<int>> query(q + 1);
    for (int i = 1; i <= q; i++) {
        int op;cin >> op;
        query[i].push_back(op);
        if (op == 1) {
            int p, X, C;cin >> p >> X >> C;
            query[i].push_back(p);
            query[i].push_back(X);
            query[i].push_back(C);
            if (C != 0) mp[X][C] = rnd() % INF;
        } else {
            int l, r;cin >> l >> r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
    }

    for (auto &[X, mmp] : mp) {
        int sum = 0;
        for (auto &i : mmp) sum += i.second;
        if (mmp.size() == k - 1) mmp[0] = -sum;
        else mmp[0] = rnd() % INF;
    }
    for (int i = 1; i <= n; i++) {
        w[i] = mp[a[i]][c[i]];
    }

    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        
        int op = query[i][0];
        if (op == 1) {
            int p = query[i][1];
            int X = query[i][2];
            int C = query[i][3];
            a[p] = X; c[p] = C;
            w[p] = mp[X][C];
            change(1, 1, n, p);
        } else {
            int l = query[i][1];
            int r = query[i][2];
            //cout << calc(1, 1, n, l, r) << endl;return;
            if (calc(1, 1, n, l, r) == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
