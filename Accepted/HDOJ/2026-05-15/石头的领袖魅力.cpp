#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int a, b;cin >> a >> b;
    int ans = a + b;
    if (min(a, b) == 1) {
        if (max(a, b) == 2) cout << 3 << endl;
        else cout << 2 << endl;
    } else cout << 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
