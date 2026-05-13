#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    if (n >= 2*k) {
        vector<int> fr(n + 1);
        int cur = 0;
        for (int i = 1; i <= k; i++) {
            cur += arr[i];
            fr[i] = cur;
        }
        int ans = cur;

        for (int r = k + 1; r <= n; r++) {
            cur += arr[r] - arr[r - k];
            ans = max(ans, cur);
            fr[r] = ans;
        }

        vector<int> bac(n + 1);
        cur = 0;
        for (int i = n; i >= n - k + 1; i--) {
            cur += arr[i];
            bac[i] = cur;
        }
        ans = cur;
        for (int i = n - k; i >= 1; i--) {
            cur += arr[i] - arr[i + k];
            ans = max(ans, cur);
            bac[i] = ans;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, fr[i] + bac[i + 1]);
        }
        cout << res + 2 * (1 + k) * k / 2 << endl;
        return;
    }
    // cout << "---" << endl;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += arr[i];    
    }
    while (n > 0 && k > 0) {
        res += k;
        if (n > 1) res += k;
        k--;
        n -= 2;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
