#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

void solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[1][0] = 1;
    int f = 1;
    vector<int> val(n + 1, -1);
    val[1] = 0;
    for (int i = 1; i <= m; i++) {
        int p, v;cin >> p >> v;
        if (val[p] != -1 && val[p] != v) f = 0;
        val[p] = v;
    }

    if (!f) {
        cout << 0 << endl;
        return;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
        if (val[i] != -1) {
            for (int j = 0; j <= n; j++) {
                if (j != val[i]) dp[i][j] = 0;
            }
        }
    }

    int ans = 0;
    // for (int j = 0; j <= n; j++) ans = (ans + dp[])
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}