#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define PIP pair<int, PII>
const int maxN = 5e3 + 7;

const int MOD = 998244353;
vector<int> f(maxN + 7);
vector<int> finv(maxN + 7);
vector<int> fa(maxN);

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

int find(int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    sort(arr.begin()+1, arr.end());
    vector<PIP> e; // val - {v, u}
    for (int i = 1; i < n; i++) {
        e.push_back({C(arr[i+1], arr[i]), {i+1, i}});
    }
    for (int i = 2; i < n; i++) {
        e.push_back({C(arr[i], arr[1]), {i, 1}});
        e.push_back({C(arr[n], arr[i]), {n, i}});
    }
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) fa[i] = i;
    int res = 0;
    for (auto &i : e) {
        int val = i.first;
        auto [v, u] = i.second;
        int v_fa = find(v);
        int u_fa = find(u);
        if (v_fa != u_fa) {
            res = (res + val) % MOD;
            fa[v_fa] = u_fa;
        }
    }

    cout << res % MOD << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;cin >> T;
    while (T--) solve();
}