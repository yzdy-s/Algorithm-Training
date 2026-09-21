#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 1e9 + 7;
void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> d(n + 7, 0); // 不能选的数字
    for (int k = 1; k <= n; k++) {
        int l = arr[k] * k;
        int r = min((arr[k] + 1) * k - 1, n - 1);
        if (l <= r) {
            d[l + 1]++;
            d[r + 2]--;
        }
    }
    for (int i = 1; i <= n; i++) d[i] += d[i - 1];
    for (int i = 1; i <= n; i++) {
        if (d[i] > 0) d[i] = 1;
        else d[i] = 0;
    }
    d[0] = 0;
    d[n + 1] = 0;

    vector<int> maxL(n + 2, 0);
    for (int k = 1; k <= n; k++) {
        for (int t = 0; t < arr[k]; t++) {
            int l = t * k;
            int r = min((t + 1) * k - 1, n - 1);
            l++;
            r++;
            maxL[r] = max(maxL[r], l);
        }
    }

    vector<int> st(n + 2, 0);
    st[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        st[i] = max(st[i - 1], maxL[i - 1]);
    }

    vector<int> dp(n + 2, 0);
    vector<int> sum(n + 2, 0);
    dp[0] = 1;
    sum[0] = 1;

    // for (int i = 1; i <= n + 1; i++) {
    //     if (d[i]) dp[i] = 0;
    //     else {
    //         int l = st[i];
    //         int r = i - 1;
    //         int res = 0;
    //         for (int j = l; j <= r; j++) res += dp[j];
    //         dp[i] = res;
    //     }
    // }

    for (int i = 1; i <= n + 1; i++) {
        if (d[i]) dp[i] = 0;
        else {
            int l = st[i];
            int r = i - 1;
            int res = 0;
            if (l <= r) {
                res = sum[r];
                if (l > 0) res = (res - sum[l - 1] + MOD) % MOD;
            }
            dp[i] = res;
        }
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n + 1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
