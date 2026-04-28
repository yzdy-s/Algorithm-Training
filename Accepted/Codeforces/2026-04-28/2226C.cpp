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
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr.begin() + 1, arr.end(), greater<int>());
    
    int l = 0, r = n + 7;
    int ans = 0;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        int f = 1;
        vector<int> vis(mid);
        vector<int> c;
        for (int i = 1; i <= n; i++) {
            int num = arr[i];
            if (num < mid && vis[num] == 0) vis[num] = 1;
            else c.push_back(num);
        }
        for (int i = 0; i < mid; i++) {
            if (vis[i]) continue;
            while (c.size() && (c.back() - 1) / 2 < i) c.pop_back();
            if (c.size()) {
                // cout << mid << ' ' << i << endl;
                vis[i] = 1;
                c.pop_back();
            }
            if (vis[i] == 0) break;
        }
        for (int i = 0; i < mid; i++) {
            if (vis[i] == 0) f = 0;
        }
        if (f) {
            l = mid;
            // cout << "++++";
            ans = max(ans, mid);
        } else r = mid;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
