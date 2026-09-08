#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<PII> arr;
    map<int, int> x, y;
    for (int i = 1; i <= m; i++) {
        int a, b;cin >> a >> b;
        x[a]++, y[b]++;
    }
    int res = LNF;
    for (auto &[_, cnt] : x) {
        res = min(res, n - cnt);
    }
    for (auto &[_, cnt] : y) {
        res = min(res, n - cnt);
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
