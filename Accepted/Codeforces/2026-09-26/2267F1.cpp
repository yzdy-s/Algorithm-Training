#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, q;cin >> n >> q;
    vector<int> arr(n + 1);
    int mx = 0, mn = LNF;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    vector<int> ans;
    ans.push_back(mx - mn);
    for (int Z = 1; Z <= 100; Z++) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                pq.push(arr[i] ^ arr[j]);
            }
        }

        for (int i = 1; i <= n; i++) {
            arr[i] = pq.top(); pq.pop();
        }
        ans.push_back(arr[n] - arr[1]);
    }

    while (q--) {
        int x;cin >> x;
        if (x <= 100) cout << ans[x] << endl;
        else cout << 0 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
