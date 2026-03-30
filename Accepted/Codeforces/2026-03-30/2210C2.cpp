#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
int primes[] = {
    2,3,5,7,11,13,17,19,23,29,31,37,41,
    43,47,53,59,61,67,71,73,79,83,89,
    97,101,103,107,109,113,127,131,137,
    139,149,151,157,163,167,173,179,181,
    191,193,197,199,211,223,227,229,233,
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> g(n + 1);
    for (int i = 2; i <= n; i++) {
        g[i] = gcd(a[i], a[i - 1]);
    }

    vector<vector<int>> aid(n + 1);
    for (int i = 1; i <= n; i++) {
        aid[i].push_back(a[i]);
        
        int G = 1;
        if (i == 1) G = g[2];
        else if (i == n) G = g[n];
        else G = lcm(g[i], g[i + 1]);

        if (G <= b[i]) {
            aid[i].push_back(G);
            for (int p : primes) {
                if (G * p <= b[i] && G * p != a[i]) {
                    aid[i].push_back(G * p);
                }
            }
        }
    }

    vector<vector<int>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i].assign(aid[i].size(), -1); 
    }

    for (int j = 0; j < aid[1].size(); j++) {
        if (aid[1][j] <= b[1] || aid[1][j] == a[1]) { 
            dp[1][j] = (aid[1][j] != a[1]);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j1 = 0; j1 < aid[i - 1].size(); j1++) {
            if (dp[i - 1][j1] == -1) continue;
            for (int j2 = 0; j2 < aid[i].size(); j2++) {
                if (aid[i][j2] != a[i] && aid[i][j2] > b[i]) continue;
                if (gcd(aid[i - 1][j1], aid[i][j2]) == g[i]) {
                    dp[i][j2] = max(dp[i][j2], dp[i - 1][j1] + (aid[i][j2] != a[i]));
                }
            }
        }
    }

    int res = 0;
    for (int j = 0; j < aid[n].size(); j++) {
        res = max(res, dp[n][j]);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
