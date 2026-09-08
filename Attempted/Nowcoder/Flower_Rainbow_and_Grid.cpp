#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n = 9, m = 9;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res.push_back(i * i - j * j);
        }
    }
    ranges::sort(res);
    for (auto &i : res) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}