#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m, x, y, k;cin >> n >> m >> x >> y >> k;
    int ans = LNF;
    for (int a = 0; a <= n; a++) {
        int dNeed = n - a;
        if (dNeed > a / 2) continue;
        if (dNeed > k) continue;
        for (int b = 0; b <= m; b++) {
            int cNeed = m - b;
            if (cNeed > b / 3) continue;
            if (dNeed + cNeed > k) continue;
            ans = min(ans, a * x + b * y);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
