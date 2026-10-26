/* 
5 4
1 3 2 4 3

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
constexpr int N = 8003;
int a[N], cd[1000006];

void solve() {
    int n, M; cin >> n >> M;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int d = 2; d <= M; ++d) {
        for (int j = d; j <= M; j += d) ++cd[j];
    }
    cd[0] = M - 1;
    
    ll res = 0;
    // odd
    for (int i = 2; i < n; ++i) {
        int g = 0;
        for (int l = i - 1, r = i + 1; 1 <= l && r <= n; --l, ++r) {
            g = gcd(g, a[r] - a[l]);
            res += cd[g];
        }
    }
    // even
    for (int bgi = 1; bgi < n; ++bgi) {
        int g = 0;
        for (int l = bgi, r = bgi + 1; 1 <= l && r <= n; --l, ++r) {
            g = gcd(g, a[r] - a[l]);
            res += cd[g];
        }
    }

    cout << res << '\n';
}

signed main() {
    int T = 1;    
    //cin >> T;
    while (T--) solve();
}