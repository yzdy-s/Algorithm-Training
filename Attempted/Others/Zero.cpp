#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define inv(x) ksm(x, MOD - 2)

const int MOD = 998244353;
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

int f(int n, int m, int k, int k_1) {
    if (n == 1) return 1;
    if (n == 2) return 0;
    return k * ksm(k_1, n - 2) - f(n - 2, m, k, k_1) * k_1;
}

void solve(){
    int n, m;cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
        return;
    } else if (n == 2) {
        cout << 0 << endl;
        return;
    }
    if (m == 0) {
        cout << 0 << endl;
        return;
    }
    
    int k = ksm(2, m);
    int k_1 = ((k - 1) % MOD + MOD) % MOD;
    // cout << "===" << f(n, m, k, k_1) << endl;
    // // cout << k << ' ' << tot << endl;
    int res;
    if (n & 1) {
        res = ksm(k_1, n - 1);
    } else {
        int t = ((inv(k) % MOD * ksm(-1, n / 2 )%MOD+MOD) % MOD * (1 - ksm(-k_1, n / 2 - 1)) % MOD + MOD) % MOD;
        
        res = k * ksm(k_1, n / 2) % MOD * t % MOD;
        //cout<<t<<'\n';
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}