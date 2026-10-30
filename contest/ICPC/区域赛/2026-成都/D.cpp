#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;

void solve() {
    int a, b, A, B;cin >> a >> b >> A >> B;
    int x = (A + b - 1) / b;
    int y = (B + a - 1) / a;
    if (x >= y + 4) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}