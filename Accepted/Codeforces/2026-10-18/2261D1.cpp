#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int res = (n + 1) / 2;
    int i = n / 2, j = i + 1;
    cout << res << endl;

    cout << j << ' ' << (n >> 1 << 1 ) << endl;
    if (n & 1) cout << n << ' ' << n << endl;
    while (i >= 2) {
        cout << i << ' ' << j << endl;
        i--, j++;
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
