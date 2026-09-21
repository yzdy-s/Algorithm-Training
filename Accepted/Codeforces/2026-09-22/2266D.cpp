#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] -= i;
    }
    sort(arr.begin() + 1, arr.end());
    // for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
    map<int, int> mp;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        mp[arr[i]] = max(mp[arr[i]], mp[arr[i] - 1] + 1);
        res = max(res, mp[arr[i]]);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
