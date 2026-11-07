#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int l, r;cin >> l >> r;
    if ((l < 0 && r < 0) || (l > 0 && r > 0)) {
        cout << r - l << endl;
        return;
    }
    cout << max(0ll, max(abs(l), abs(r)) - min(abs(l), abs(r)) - 1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
