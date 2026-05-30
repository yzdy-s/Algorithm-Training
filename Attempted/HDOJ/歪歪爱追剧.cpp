#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


void solve(){
    int L, n, m;cin >> L >> n >> m;
    vector<PII> k(n + 1);
    for (int i = 1; i <= n; i++) {
        int l, r;cin >> l >> r;
        k[i] = {l, r};
    }
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(k.begin()+1, k.end());

    priority_queue<PII, vector<PII>, greater<PII>> pq; // r - l
    int res = 0;
    int e = 0;
    int p = 1;
    for (int i = 1; i <= m; i++) {
        int aid = a[i];
        while (p <= n && (k[p].first >= e+1 && k[p].first <= aid)) {
            pq.push({k[p].second, k[p].first});
            p++;
        }
        while (pq.size()) {
            auto [r, l] = pq.top();pq.pop();
            if (l <= e || r < aid) continue;
            res += r - l + 1;
            e = r;
            break;
        }
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}