#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m, a, b;cin >> n >> m >> a >> b;
    if (gcd(a, n) == 1 && gcd(b, m) == 1 && gcd(n, m) <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
