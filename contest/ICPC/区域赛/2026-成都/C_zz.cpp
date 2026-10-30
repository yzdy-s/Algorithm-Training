#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998'244'353;

int b[101][5500][101], p[105], p2[105];
typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    fill(p, p+1+n, -1);
    p[1] = 0;
    bool dame = 0;
    for (int i = 1; i <= m; ++i) {
        int pos, val; cin >> pos >> val;
        if (p[pos] != -1 && p[pos] != val) { dame = 1; }
        p[pos] = val;
    }
    if (dame) return cout << "0\n", void();

    int lid = 1, pre = 0;
    vector<int> ndp(n + 1), dp(n + 1);
    dp[0] = 1;

    for (int i = 2; i <= n; ++i) {
        if (p[i] != -1) {
            int len = i - lid;

            for (int aj = 0; aj <= i - 1; ++aj) {
                if (lid == 1 && aj) break;
                for (int ai = aj; ai <= min(i - 1, aj + len); ++ai) {
                    int sum = p[i] - pre - aj * len;
                    if (sum < 0 || 5000 < sum) continue;
                    
                    ndp[ai] += dp[aj] * b[len][sum][ai - aj] % MOD;
                    
                    ndp[ai] %= MOD;
                }
            }
            
            lid = i;
            pre = p[i];
            dp.swap(ndp);
            fill(ndp.begin(), ndp.end(), 0); ////
        }
    }


    ll res = 0;
    for (int ai = 0; ai <= n; ++ai) {
        (res += dp[ai]) %= MOD;
    }
    res = res * p2[n - lid] % MOD;
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    b[0][0][0] = 1;
    for (int len = 1; len <= 100; ++len) {
        const int MAXS = len * (len + 1) / 2;
        for (int s = 0; s <= MAXS; ++s) {
            for (int stp = 0; stp <= len; ++stp) {
                b[len][s][stp] = b[len-1][s][stp];
                if (stp && len <= s) (b[len][s][stp] += b[len-1][s-len][stp-1]) %= MOD;
            }
        }
    }

    p2[0] = 1;
    for (int i = 1; i <= 100; ++i) p2[i] = p2[i-1] * 2LL % MOD;

    int T_ = 1; cin >> T_;
    while (T_--) solve();
}