#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5;

const int MOD = 998244353;
vector<int> f(maxN + 7);
vector<int> finv(maxN + 7);

int ksm(int a, int b) {
    if (b < 0) return 0;
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
    f[0] = 1;
    for (int i = 1; i <= maxN; i++) f[i] = f[i-1] * i % MOD;
    finv[maxN] = ksm(f[maxN], MOD - 2);
    for (int i = maxN - 1; i >= 0; i--) finv[i] = finv[i+1] * (i+1) % MOD;
}

int C(int n, int m) {
    return f[n] * finv[m] % MOD * finv[n-m] % MOD;
}

int A(int n, int m) {
    return f[n] % MOD * finv[n-m] % MOD;
}

void solve(){
    int n;cin >> n;
    int sum = 0;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) cin >> arr[i];
    ranges::sort(arr);

    vector<int> w(n);
    w[0] = 1;
    for (int i = 1; i < n; i++) {
        w[i] = (w[i - 1] + ksm(3, i - 1)) % MOD;
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i] * w[i] % MOD * ksm(2, n - i - 1) % MOD;
        sum %= MOD;
    }

    cout << sum % MOD << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;cin >> T;
    while (T--) solve();
}
