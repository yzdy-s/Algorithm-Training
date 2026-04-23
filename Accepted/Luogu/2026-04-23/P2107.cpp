#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


void solve(){
    int n, m;cin >> n >> m;
    vector<PII> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int x, t;cin >> x >> t;
        arr[i] = {x, t};
    }
    sort(arr.begin()+1, arr.end());
    priority_queue<int> pq;
    int cur = m;
    int sum = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        pq.push(arr[i].second);
        sum += arr[i].second;
        cur = m - arr[i].first;
        // cout << sum << ' ' << cur << endl;
        while (pq.size() && cur < sum) {
            int x = pq.top();
            pq.pop();
            sum -= x;
        }
        res = max(res, (int)pq.size());
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
