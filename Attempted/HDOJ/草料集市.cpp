#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e5 + 7;
vector<PII> tree(4 * maxN, {LNF, LNF});

void change(int p, int l, int r, int pos, int val) {
    if (l == r && l == pos) {
        tree[p] = {val, pos};
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) change(2*p, l, mid, pos, val);
    else change(2*p+1, mid+1, r, pos, val);

    if (tree[2*p].first < tree[2*p+1].first) tree[p] = tree[2*p];
    else if (tree[2*p].first > tree[2*p+1].first) tree[p] = tree[2*p+1];
    else if (tree[2*p].second < tree[2*p+1].second) tree[p] = tree[2*p+1];
    else tree[p] = tree[2*p];
}

PII calc(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p];
    PII ans = {LNF, LNF};
    int mid = l + r >> 1;
    if (x <= mid) {
        PII t1 = calc(2*p, l, mid, x, y);
        PII t = ans;
        if (t.first < t1.first) ans = t;
        else if (t.first > t1.first) ans = t1;
        else if (t.second < t1.second) ans = t1;
        else ans = t;
    }
    if (y >= mid + 1) {
        PII t1 = calc(2*p+1, mid+1, r, x, y);
        PII t = ans;
        if (t.first < t1.first) ans = t;
        else if (t.first > t1.first) ans = t1;
        else if (t.second < t1.second) ans = t1;
        else ans = t;
    }
    return ans;
}

void solve(){
    int n, k;cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        tree[i] = {LNF, 0};
    }

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    // set<PII> st;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + arr[i];
        change(1, 1, n, i, dp[i][1]);
        int l = max(1LL, i-k);
        int r = max(1LL, i-1);
        // int val = LNF, idx;
        // for (int j = l; j <= r; j++) {
        //     if (dp[j][1] <= val) {
        //         val = dp[j][1];
        //         idx = j;
        //     }
        // }
        auto [val, idx] = calc(1, 1, n, l, r);
        dp[i][0] = val + (sum[i] - sum[idx]) / 2;
        if (i == 1) dp[i][0] = LNF;
        // cout << val << ' ' << idx << endl;
        // st.insert({dp[i][1], i});
        // if (st.size() > k) st.erase({dp[i-k][1], i});
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}