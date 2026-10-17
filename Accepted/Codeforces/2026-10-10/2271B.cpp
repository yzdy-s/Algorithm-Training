#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        cnt[x]++;
    }
    int mn = 0;
    while (cnt[mn] >= 2 * k) mn++;
    if (cnt[mn] == 2 * k - 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
