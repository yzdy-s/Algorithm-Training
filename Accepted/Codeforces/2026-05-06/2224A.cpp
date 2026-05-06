#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int ans = 0;
    
    vector<int> dp(n + 1, -LNF);
    dp[n] = arr[n];
    for (int i = n - 1; i >= 1; i--){
        dp[i] = max(arr[i], dp[i + 1] + arr[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i] > 0) ans++;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
