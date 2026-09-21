#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;cin >> x;
            if (((i + j) & 1) != (x & 1)) x++;
            cout << x << " \n"[j == m];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}