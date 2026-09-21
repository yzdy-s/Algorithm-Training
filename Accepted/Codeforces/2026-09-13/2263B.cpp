#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    if (k == 2 * n || k < n) {
        cout << -1 << endl;
        return;
    }
    vector<vector<int>> ans(n + 1, vector<int>(n + 1));

    int x = 1;
    int t = k - n + 1;
    for (int i = 1; i <= t; i++) {
        ans[1][i] = x++;
    }
    for (int i = 2; i <= t; i++) {
        ans[i][1] = x++;
    }

    int cnt = 0;
    for (int i = t + 1; i <= n; i++) {
        if (ans[i][i] == 0) {
            cnt++;
            ans[i][i] = x++;
        }
        if (cnt == k - 2 * t + 1) break;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == 0) ans[i][j] = x++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << " \n"[j == n];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
