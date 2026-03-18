#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n;
const int maxN = 1e5 + 7;
vector<int> arr(maxN);
vector<int> sum(maxN);

int dp() {
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = arr[i];
        dp[i] = max(dp[i], dp[i] + dp[i - 1]);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dp[i]);
    return res;
}

int baoli() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            res = max(res, sum[j] - sum[i - 1]);
        }
    }
    return res;
}

array<int, 3> fz(int l, int r) { // l, mid, r
    if (l == r) return {arr[l], arr[l], arr[l]};
    int mid = l + r >> 1;
    auto lc = fz(l, mid);
    auto rc = fz(mid+1, r);
    array<int, 3> res = {-INF, -INF, -INF};
    res[0] = max(lc[0], sum[mid] - sum[l - 1] + rc[0]);
    res[2] = max(rc[2], sum[r] - sum[mid] + lc[2]);
    res[1] = max({lc[1], rc[1], lc[2] + rc[0]});
    return res;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) sum[i] = arr[i] + sum[i - 1];
    auto ans = fz(1, n);
    cout << max({ans[0], ans[1], ans[2]}) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}