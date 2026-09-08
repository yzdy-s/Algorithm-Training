#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    int A = 0, B = 0;
    for (int i = 2; i <= n; i++) A += a[i - 1] - a[i] + 1;
    A += a[n];
    for (int i = 2; i <= m; i++) B += b[i - 1] - b[i] + 1;
    B += b[m];
    if (B > A) cout << 2 << endl;
    else cout << 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
