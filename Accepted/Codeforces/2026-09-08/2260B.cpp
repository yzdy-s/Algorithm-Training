#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int x, y, k;cin >> x >> y >> k;
    int res = 0;
    int c = y - x;

    for (int i = 0; i < min(c, k); i++) {
        int t = c % (x + i);
        res += t;
    }
    if (k > c) res += c * (k - c);
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
