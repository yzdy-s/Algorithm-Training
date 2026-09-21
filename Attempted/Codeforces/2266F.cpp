#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;cin >> x >> y;
        mp[x] = y;
        ans = max(ans, x);
    }
    int m = 100;
    if (ans >= m) {
        cout << ans << endl;
        return;
    }
    int l = 0, r = m;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        int f = 0;
        if (mp.count(mid)) f = 1;
        int need = 1;
        for (int i = mid; i >= 1; i--) {
            if (mp[i] >= need) need = 1;
            else {
                need = (need - mp[i]) + 1;
            }
        }
        if (need <= mp[0]) f = 1;

        if (f) {
            ans = max(ans, mid);
            l = mid;
        } else {
            r = mid;
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