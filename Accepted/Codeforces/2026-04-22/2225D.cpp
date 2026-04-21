#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 998244353;

int cnt1(int x) {
    if (x == 0) return 0;
    return (x - 1) / 4 + 1;
}
int cnt0(int x) {
    if (x < 3) return 1;
    return (x - 3) / 4 + 2;
}

void solve(){
    int n, x;cin >> n >> x;
    // vector<int> XOR(n + 1);
    // for (int i = 1; i <= n; i++) {
    //     XOR[i] = (i ^ XOR[i - 1]);
    //     cout << XOR[i] << ' ';
    // }
    // cout << endl;
    int all0 = cnt0(n);
    int R = all0 - cnt0(x - 1);
    int L = cnt0(x - 1);
    int res = L % MOD * (R % MOD);

    int all1 = cnt1(n);
    R = all1 - cnt1(x - 1);
    L = cnt1(x - 1);
    res = (res + L % MOD * (R % MOD) % MOD) % MOD;

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
