#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    int k = 0;
    for (int i = 1; i <= n; i++) k |= i;
    int m = 0;
    for (int i = 1; i <= n; i++) m ^= i;
    vector<int> ans(n + 1, 0);
    for (int i = n; i >= 1; i--) {
        int t = m ^ i ^ (2 * i);
        if (t > m) {
            m = t;
            ans[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
