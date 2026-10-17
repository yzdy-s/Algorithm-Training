#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, R;cin >> n >> R;
    vector<pair<PII, string>> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, y;cin >> x >> y;
        string name;cin >> name;
        arr[i] = {{x, y}, name};
    }

    int cnt = LNF;
    vector<string> ans;
    for (int i = 1; i <= n; i++) {
        int X = arr[i].first.first;
        int Y = arr[i].first.second;
        int c = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int xx = arr[j].first.first;
            int yy = arr[j].first.second;
            if (((xx - X) * (xx - X) + (yy - Y) * (yy - Y)) <= R * R) c++;
        }

        if (c == cnt) {
            ans.push_back(arr[i].second);
        } else if (c < cnt) {
            cnt = c;
            ans.clear();
            ans.push_back(arr[i].second);
        }
    }
    // cout << cnt << endl;
    for (auto &s : ans) cout << s << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;// cin >> T;
    while (T--) solve();
}
