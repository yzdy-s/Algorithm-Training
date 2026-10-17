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
    vector<vector<int>> dp(vector<vector<int>>(n + 1, vector<int>(2, 0)));

    vector<int> b(n + 1);
    for (int i = 1; i <= n - 4; i++) b[i] = arr[i] + arr[i + 2] - arr[i + 4];
    // for (int i = 1; i <= n - 4; i++) cout << b[i] << " \n"[i == n - 4];
    map<int, int> cx;
    int ans = 0;
    for (int i = 1; i <= n - 4; i++) {
        int t = b[i];
        for (int d = 1; d <= 3; d += 2) {
            if (i - d <= 0) break;
            if (t == b[i - d]) {
                ans++;
            }
        }
        if (i >= 6) cx[b[i - 5]]++;
        ans += cx[t];
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
