#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    if (n == 2) {
        cout << k + 2 << ' ' << 2 << endl;
        return;
    }
    int mx = k + n;
    cout << mx << ' ' << 2 << ' ';
    for (int i = 1; i <= n-2; i++) cout << 1 << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}