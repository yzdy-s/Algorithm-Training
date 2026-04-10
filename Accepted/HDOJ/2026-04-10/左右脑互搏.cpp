#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> XOR(1 << n);
    for (int st = 0; st < (1 << n); st++) {
        for (int bit = 0; bit < n; bit++) {
            if ((st >> bit) & 1) XOR[st] ^= arr[bit];
        }
    }

    vector<int> dp(1 << n, INF); // 1 先手赢
    for (int st = 0; st < (1LL << n); st++) {
        int cnt = n - __popcount(st);
        // if (son[st][0] + son[st][1] == 1) {
        //     if (son[st][0]) dp[st] = 0;
        //     else dp[st] = 1;
        // } else {
        //     if (cnt & 1) dp[st] = 1;
        //     else dp[st] =  0;
        // }

        if (XOR[st] == 0) {
            if (cnt & 1) dp[st] = 1;
            else dp[st] = 0;
        }
        // if (son[st].size() == 1) {
        //     for (auto &i : son[st]) {
        //         dp[st] = i;
        //         break;
        //     }
        //     // dp[st] = son[st].begin();
        // } else {
        //     if (cnt & 1) dp[st] = 1;
        //     else dp[st] =  0;
        // }

        for (int bit = 0; bit < n; bit++) {
            if (((st >> bit) & 1) == 0) continue;
            int son = (1ll << bit) ^ st;
            if (arr[bit] <= XOR[son]) continue;
            if ((cnt & 1) == 1) {
                if (dp[son] == 0) {
                    dp[st] = 0;
                    break;
                } else {
                    dp[st] = 1;
                }
            } else {
                if (dp[son] == 1) {
                    dp[st] = 1;
                    break;
                } else {
                    dp[st] = 0;
                }
            }
            // dp[st | (1LL << bit)] = (dp[st], cnt);
        }
    }

    if (dp[(1LL << n) - 1]) cout << "Left" << endl;
    else cout << "Right" << endl;
    // cout << dp[(1LL << n) - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
