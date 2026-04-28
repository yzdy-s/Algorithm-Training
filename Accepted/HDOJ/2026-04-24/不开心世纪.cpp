#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int l = 1;

    map<int, int> mp;
    int sum = 0, utility = 0;
    int res = LNF;
    for (int r = 1; r <= n; r++) {
        int num = arr[r];
        mp[num]++;
        if (num >= 1 && num <= m && mp[num] == 1) utility++;
        while (l <= r && utility == m) {
            mp[arr[l]]--;
            if (arr[l] >= 1 && arr[l] <= m && mp[arr[l]] == 0) {
                mp[arr[l]]++;
                // l--;
                break;
            }
            l++;
        }
        if (utility == m) {
            // cout << l << ' ' << r << endl;
            res = min(res, r - l + 1 - m);
        }
    }
    if (res == LNF) cout << -1 << endl;
    else cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
