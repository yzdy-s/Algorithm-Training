#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, r;cin >> n >> r;
    vector<PII> arr(n + 1);
    int X = 0;

    for (int i = 1; i <= n; i++) {
        int x, y;cin >> x >> y;
        arr[i] = {x, y};
        X = max(X, abs(x));
        X = max(X, abs(y));
    }

    vector<PII> ans;
    ans.push_back({-X, X});
    while (1) {
        int x = ans.back().first + 2 * r; 
        int y = ans.back().second;
        if (x > X) break;
    }
    int all = ans.size();
    int k = 1;
    while (1) {
        int y = ans[0].second - k * r;
        if (y < -X) break;
        for (int i = 0; i < all; i++) {
            ans.push_back({ans[i].first, y});
        }
        k++;
    }
    

    cout << ans.size() << endl;
    for (auto [x, y] : ans) cout << x << ' ' << y << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}