#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k, x, y;cin >> n >> k >> x >> y;
    vector<int> arr(k + 1);
    for (int i = 1; i <= k; i++) cin >> arr[i];

    vector<int> dp(k + 1);
    vector<int> vis(n + 1), sum(k + 1);
    for (int i = 1; i <= k; i++) {
        sum[i] = (sum[i - 1] + arr[i]) % n;
    }

    for (int i = k; i >= 1; i--) {
        int J = (sum[i] + x - y + n) % n;
        if (vis[J]) {
            dp[i] = dp[vis[J]];
        } else {
            dp[i] = (sum.back() - sum[i] + n + y) % n;
        }
        vis[sum[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (i == x) continue;
        int J = (x - i + n) % n;
        if (!vis[J]) {
            cout << (sum.back() + i) % n << ' ';
        } else cout << dp[vis[J]] << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
