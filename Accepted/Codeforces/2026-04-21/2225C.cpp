#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<char> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(2, LNF)); // 1 - 竖着放
    dp[0][0] = 0;
    dp[0][1] = 0;
    if (a[1] == b[1]) dp[1][1] = 0;
    else dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == b[i]) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
        } else dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        int add = (a[i] != a[i - 1]) + (b[i] != b[i - 1]);
        dp[i][0] = min(dp[i - 2][0], dp[i - 2][1]) + add;
    }
    cout << min(dp[n][0], dp[n][1]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
