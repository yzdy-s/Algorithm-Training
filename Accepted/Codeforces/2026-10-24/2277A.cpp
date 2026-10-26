#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ranges::sort(arr.begin() + 1, arr.end());
    map<int, int> pos;
    for (int i = 1; i <= n; i++) {
        pos[arr[i]] = i;
    }
    // for (auto &i : pos) {
    //     cout << i.first << ' ' << i.second << endl;
    // }
    int mx = 0;
    while (1) {
        if (pos[mx] == 0 || pos[mx] < (mx + 1) * k) {
            cout << mx << endl;
            return;
        }
        mx++;
    }
    cout << n << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
