#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e5 + 7;
const int MOD = 1e9 + 7;
vector<int> f(maxN + 7);
vector<int> finv(maxN + 7);

int ksm(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    f[0] = finv[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        f[i] = i * f[i-1] % MOD;
        finv[i] = ksm(f[i], MOD - 2);
    }
}

int C(int n, int m) {
    return f[n] * finv[m] % MOD * finv[n-m] % MOD;
}

int A(int n, int m) {
    return f[n] % MOD * finv[n-m] % MOD;
}

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> ans(n + 1);
    for (int i = n; i >= 1; i--) {
        if (arr[i]) {
            for (int j = 1; j <= i; j++) {
                ans[j] = (ans[j] + arr[i]) % MOD;
            }
            for (int j = 1; j <= i; j++) {
                arr[j] = (arr[j] - C(i, j) * arr[i] % MOD + MOD) % MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;cin >> T;
    while (T--) solve();
}
