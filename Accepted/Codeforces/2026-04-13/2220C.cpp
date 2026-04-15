#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int p, q;cin >> p >> q;
    int x = p + q * 2;
    // cout << x << ' ';
    x = 2 * x + 1;
    for (int a = 1; a * a <= x; a++) {
        if (x % a) continue;
        int b = x / a;
        if (a % 2 == 0 || b % 2 == 0) continue;
        int n = (a - 1) / 2;
        int m = (b - 1) / 2;
        if (n && m) {
            if (n * (m + 1) < q) continue;
            // cout << a << ' ' << b << ' ';
            cout << n << ' ' << m << endl;
            
            return;
        }
    }
    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
