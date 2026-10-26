#include <bits/stdc++.h>
using namespace std;
#define int long long 
typedef long long ll;

constexpr int N = 3003;
ll dp[N][N], a[N], b[N];
ll tdp[N], pmin[N], smin[N];
constexpr ll INF64 = 0x7fff'ffff'ffff'ffff;

void solve() {
    int n, m, x, y, z; cin >> n >> m >> x >> y >> z;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    
    for (int j = 1; j <= n; ++j) {
        dp[1][j] = (j - 1LL) * z + abs(b[j] - a[j]) * y;
    }
    


    for (int i = 2; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {

        }
    }
    
    
    

    
    
}

signed main() {
    int T; cin >> T;
    while (T--) solve();
}