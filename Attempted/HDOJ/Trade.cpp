#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 7);
    arr[0] = LNF;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int sale;cin >> sale;

    // 第 i 个   操作完后手上几股   前一个   当前  (0买入    1卖出)
    int dp[n + 7][n + 7][2][2];
    for (int i = 1; i <= n + 5; i++) {
        for (int _ = 0; _ <= n + 5; _++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 1; k++) {
                    dp[i][_][j][k] = -LNF;
                }
            }
        }
        
    }

    dp[0][0][0][0] = 0;
    dp[1][0][0][0] = 0;
    dp[1][1][0][1] = sale - arr[1];

    for (int i = 1; i <= n; i++) {
        for (int cnt = 0; cnt < i; cnt++) {
            dp[i][cnt + 1][0][1] = max(dp[i - 1][cnt][1][0], dp[i - 1][cnt][0][0]);
        }
    }

    cout << max({dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1]}) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}