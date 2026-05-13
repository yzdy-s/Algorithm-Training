#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define inv(x) (ksm(x, MOD - 2))
const int MOD = 998244353;

int ksm(int x, int n) {
    int ans = 1;
    x  %= MOD;
    while (n) {
        if (n & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ans;
}

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> sumA(n + 1), sumB(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {cin >> a[i]; sum += a[i];}
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) sumA[i] = sumA[i - 1] + a[i];
    for (int i = 1; i <= n; i++) sumB[i] = sumB[i - 1] + b[i];

    int t1 = 0, t2 = 0;
    // 分母是 sum
    for (int i = 1; i <= n; i++) {
        t2 = (t2 + a[i] * b[i]) % MOD;
    }
    
    // 分母是 2*sum
    for (int i = 1; i <= n; i++) {
        t1 = (t1 + a[i] * sumB[i - 1]) % MOD;
    }
    // cout << t1 << ' ' << t2 << endl;
    int x = t1 * 2 + t2;
    int ans = x % MOD * inv(2 * sum) % MOD;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
