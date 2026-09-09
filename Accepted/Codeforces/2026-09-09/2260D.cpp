#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = "#" + s;
    if (s[1] == '0') {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0' && s[i] == s[i - 1]) {
            cout << -1 << endl;
            return;
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(10, LNF));

    dp[0][5] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            for (int j = 1; j <= 9; j++) {
                if (j != 5) dp[i][5] = min(dp[i][5], max(abs(5 - j), dp[i - 1][j]));
            }
        } else if (s[i] == '-') {
            for (int j = 1; j <= 9; j++) {
                if (j != 1) dp[i][1] = min(dp[i][1], max(abs(1 - j), dp[i - 1][j]));
                if (j != 2) dp[i][2] = min(dp[i][2], max(abs(2 - j), dp[i - 1][j]));
                if (j != 3) dp[i][3] = min(dp[i][3], max(abs(3 - j), dp[i - 1][j]));
                if (j != 4) dp[i][4] = min(dp[i][4], max(abs(4 - j), dp[i - 1][j]));
            }
        } else {
            for (int j = 1; j <= 9; j++) {
                if (j != 6) dp[i][6] = min(dp[i][6], max(abs(6 - j), dp[i - 1][j]));
                if (j != 7) dp[i][7] = min(dp[i][7], max(abs(7 - j), dp[i - 1][j]));
                if (j != 8) dp[i][8] = min(dp[i][8], max(abs(8 - j), dp[i - 1][j]));
                if (j != 9) dp[i][9] = min(dp[i][9], max(abs(9 - j), dp[i - 1][j]));
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= 5; j++) {
    //         cout << dp[i][j] << " \n"[j == 5];
    //     }
    // }
    int res = LNF;
    for (int i = 1; i <= 9; i++) res = min(res, dp[n][i]);
    if (res == LNF) cout << -1 << endl;
    else cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
