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
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2) {
        cout << "2 2" << endl;
        return;
    }
    vector<int> ans(n + 1, 3);
    for (int i = 1; i <= n; i++) {
        int l = max(1LL, i-2);
        int r = min(n, i+2);
        int mn = LNF, mx = 0;
        for (int j = l; j <= r; j++) {
            mx = max(mx, arr[i]);
            mn = min(mn, arr[i]);
        }
        if (arr[i] == mn && arr[i] == mx) ans[arr[i]] = 2;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
