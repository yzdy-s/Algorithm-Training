#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        int l, r;cin >> l >> r;
        if (r - l + 1 > 1) g = 1;
        else g = gcd(g, l);
    }
    cout << g << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
