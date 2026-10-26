#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    int mn = LNF;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        mn = min(mn, x);
    }
    if (mn < n) {
        cout << n << endl;
    } else cout << 0 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
