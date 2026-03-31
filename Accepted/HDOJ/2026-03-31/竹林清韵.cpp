#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
vector<int> arr(maxN);
vector<PII> tree(4 * maxN); // val - idx

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = {arr[l], l};
        return;
    }
    int mid = l + r >> 1;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    tree[p] = max(tree[2*p], tree[2*p+1]);
}

void change(int p, int l, int r, int pos, int f) {
    if (l == r && l == pos) {
        if (!f) tree[p] = {-1, -1};
        else tree[p] = {arr[l], l};
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) change(2*p, l, mid, pos, f);
    else change(2*p+1, mid+1, r, pos, f);
    tree[p] = max(tree[2*p], tree[2*p+1]);
}

PII calc(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p];
    int mid = l + r >> 1;
    PII res = {-1, -1};
    if (x <= mid) res = max(res, calc(2*p, l, mid, x, y));
    if (y >= mid + 1) res = max(res, calc(2*p+1, mid+1, r, x, y));
    return res;
}

void solve(){
    int n;cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    vector<int> ans(n);
    for (int x = 1; x < n; x++) {
        int k = (n + x) / (x + 1);
        vector<int> choose;
        for (int c = k; c >= 1; c--) {
            int l = (c - 1) * (x + 1) + 1;
            if (l > n) continue;
            PII t = calc(1, 1, n, l, n);
            ans[x] += t.first;
            change(1, 1, n, t.second, 0);
            choose.push_back(t.second);
        }
        for (auto &idx : choose) change(1, 1, n, idx, 1);
    }
    for (int i = 1; i < n; i++) cout << ans[i] << " \n"[i == n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
