#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, x;cin >> n >> x;
    int a = 0, b = 0;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];

    priority_queue<int, vector<int>, greater<int>> pq;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        a++;
        pq.push(c[i]);
        if (a - b > x) {
            b++;
            a--;

            if (pq.empty()) {
                cout << -1 << endl;
                return;
            }

            ans += pq.top();
            pq.pop();
        }
    }
    if (a <= b) cout << -1 << endl;
    else cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
