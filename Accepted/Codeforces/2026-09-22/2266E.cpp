#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

std::vector<int> minp, primes, phi;
 
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    phi.resize(n + 1);
    phi[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
        }
        
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}

void solve(){
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> dp(n + 1, LNF);

    for (int i = 0; i <= n; i++) {
        if (i <= k) dp[i] = 0;
        else {
            if (isprime(i)) dp[i] = 1;
            else {
                int x = i;
                while (x != 1) {
                    int mn = minp[x];
                    dp[i] = min(dp[i], mn * dp[i / mn] + 1);
                    while (x % mn == 0) x /= mn;
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++) cout << dp[i] << " \n"[i == n];
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += dp[arr[i]];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    sieve(2e5 + 7);
    int T = 1;cin >> T;
    while (T--) solve();
}
