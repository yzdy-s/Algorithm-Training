#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> res(n + 1), vis(n + 7, 0);

    int cur = 0;
    for (int i = 1; i <= n; i++) {
        vis[arr[i]] = 1;
        while (vis[cur]) cur++;
        res[i] = cur;
    }
    int ans = res[n - k + 1];
    // for (int i = 1; i <= n; i++) cout << res[i] << " \n"[i == n];

    int I = 0, J = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            swap(arr[i], arr[j]);
            for (int m = 1; m <= n; m++) b[m] = arr[m];
            swap(arr[i], arr[j]);
            for (int m = 0; m <= n; m++) vis[m] = 0;
            // cout << i << ' ' << j << endl;
            cur = 0;
            for (int m = 1; m <= n; m++) {
                vis[b[m]] = 1;
                while (vis[cur]) cur++;
                res[m] = cur;
            }
            // for (int m = 1; m <= n; m++) cout << b[m] << " \n"[m == n];

            // for (int m = 1; m <= n; m++) cout << res[m] << " \n"[m == n];

            if (res[n - k + 1] > ans) {
                ans = res[n - k + 1];
                I = i; J = j;
            }
        }
    }
    // cout << ans << endl;
    if (I && J) cout << I << ' ' << J << endl;
    else cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
