#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    vector<int> odd, even;
    int n;cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        if (x & 1) odd.push_back(x);
        else even.push_back(x);
    }
    int res = 0;

    if (odd.size() & 1) {
        int mx = 0;
        for (auto &i : odd) mx = max(mx, i);
        for (auto &i : even) mx = max(mx, i - 1);
        res = (mx + 1) / 2;
    } else {
        int mx = 0;
        for (auto &i : odd) mx = max(mx, i - 1);
        for (auto &i : even) mx = max(mx, i);
        res = mx / 2;
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
