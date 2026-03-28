#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define LNF 1e18

int popcnt(int x) {
    int res = 0;
    while (x) {
        if (x & 1) res++;
        x >>= 1;
    }
    return res;
}

PII calc(int x, int bit, int n) {
    PII res;
    for (int b = bit; b >= 0; b--) {
        if ((x >> b) & 1) break;
        res.first = b;
    }
    for (int b = bit; b < n; b++) {
        if ((x >> b) & 1) break;
        res.second = b;
    }
    return res;
}

void solve() {
    int n, k, m;cin >> n >> k >> m;
    map<PII, int> cnt;
    for (int i = 1; i <= m; i++) {
        int l, r;cin >> l >> r;
        l--, r--;
        cnt[{l, r}]++;
    }
    int pre[n][n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) pre[i][j][k] = 0;
        }
    }
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            for (auto [PI, c] : cnt) {
                if (l <= PI.first && PI.second <= r) {
                    for (int k = PI.first; k <= PI.second; k++) {
                        pre[l][r][k] += c;
                    }
                }
            }
        }
    }
    const int mx = (1 << n) - 1;
    vector<int> dp(mx + 1, LNF);
    dp[0] = 0;
    int cur = 0;
    for (int cost = k; cost >= 1; cost--, cur++) {
        for (int st = 0; st <= mx; st++) {
            if (__builtin_popcount(st) != cur || dp[st] == LNF) continue;
            for (int bit = 0; bit < n; bit++) {
                if ((st >> bit) & 1) continue;
                PII d = calc(st, bit, n);
                dp[st | (1 << bit)] = min(dp[st | (1 << bit)], dp[st] + pre[d.first][d.second][bit] * cost);
            }
        }
    }

    int res = LNF;
    for (int st = 0; st <= mx; st++) {
        if (__builtin_popcount(st) != k) continue;
        res = min(res, dp[st]);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;// cin >> T;
    while (T--) solve();
}