#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define int long long

void solve() {
    int n, x, y;cin >> n >> x >> y;
    vector<pair<int, int>> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b;cin >> a >> b;
        arr[i] = {a, b};
    }

    int res = 0;
    int fj = 0, ti = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq; 
    for (int i = 1; i <= n; i++) {
        int a = arr[i].first, b = arr[i].second;
        fj = max(0ll, fj - (a - ti));
        ti = a;
        if (b > fj) {
            pq.push({fj, 1});
            pq.push({b, -1});
            res += (b - fj) * y; 
        }
        fj = max(fj, b);
    }

    int ans = res;
    int js = 0;
    int cnt = 0;
    while (pq.size()) {
        int A = pq.top().first;
        while (pq.size() && pq.top().first == A) {
            cnt += pq.top().second;
            pq.pop();
        }
        if (pq.size()) {
            int B = pq.top().first;
            res += x * (B - A) -  cnt * (B - A) * y;
        }
        ans = min(ans, res);
    }

    cout << ans << endl;
}

signed main() {
    int T;cin >> T;
    while (T--) solve();
}