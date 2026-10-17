#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k, l, r;cin >> n >> k >> l >> r;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    // dp[i][j] 前 i 个分 j 段的的最大值

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j] + arr[i] * (j % 2 == 1 ? 1 : -1), dp[i - 1][j - 1] + arr[i] * (j % 2 == 1 ? 1 : -1));
        }
    }

    cout << dp[n][k] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}