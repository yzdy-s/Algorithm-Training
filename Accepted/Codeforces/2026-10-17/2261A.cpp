#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = "#" + s;
    int cnt = 0;
    int mn = LNF, mx = -LNF;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            cnt++;
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }

    if (cnt == 1) {
        cout << 0 << endl;
        return;
    } else if (cnt == 2) {
        cout << 1 << endl;
        return;
    }

    cout << mx - mn << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
